//     _    ____ ___ ____  _____
//    / \  / ___|_ _|  _ \| ____|
//   / _ \ \___ \| || | | |  _|
//  / ___ \ ___) | || |_| | |___
// /_/   \_\____/___|____/|_____|
// Originally written by Marcus Loo Vergara (aka. Bitsauce)
// 2011-2014 (C)

#include "ui_scripteditor.h"
#include "scripteditor.h"
#include "workspace.h"
#include "project.h"
#include "settings.h"
#include "debugger.h"

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>

#include <QDebug>

const int BREAKPOINT_MARKER = 1;
const int LINE_MARKER = 2;

//---------------------------------------
// ScriptEditor
// The default script editor
//---------------------------------------

ScriptEditor::ScriptEditor(QString filePath, QString title) :
    EditorBase(filePath, title),
    ui(new Ui::ScriptEditor)
{
    // Setup ui
    ui->setupUi(this);

    // Create mdi window
    QObject::connect(mdiWindow(), SIGNAL(aboutToActivate()), this, SLOT(aboutToActivate()));

    // Create the script text edit
    m_scriptTextEdit = new QsciScintilla(this);
    ui->gridLayout->addWidget(m_scriptTextEdit);
    connect(m_scriptTextEdit, SIGNAL(marginClicked(int,int,Qt::KeyboardModifiers)), this, SLOT(toggleBreakpoint(int,int,Qt::KeyboardModifiers)));
    connect(m_scriptTextEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));
    connect(m_scriptTextEdit, SIGNAL(modificationChanged(bool)), this, SLOT(setModified(bool)));
    connect(m_scriptTextEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(updatePositionLabel(int, int)));
    //connect(m_scriptTextEdit, SIGNAL(lineCountChanged(int,int)), this, SLOT(lineCountChanged(int,int)));

    // Setup fonts n stuff
    int fontSize = settings()->value("script_editor/font_size", 10).toInt();
    QFont font("Courier New", fontSize, QFont::Light);
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    QFontMetrics fontmetrics(font);

    QsciLexerCPP *lexer = new QsciLexerCPP(m_scriptTextEdit);
    lexer->setFont(font);
    m_scriptTextEdit->setLexer(lexer);
    m_scriptTextEdit->setAutoIndent(true);
    m_scriptTextEdit->setTabWidth(4);

    m_scriptTextEdit->setMarginsFont(font);
    m_scriptTextEdit->setMarginWidth(0, fontmetrics.width("00000"));
    m_scriptTextEdit->setMarginLineNumbers(0, true);
    m_scriptTextEdit->setMarginsBackgroundColor(QColor("#E4E4E4"));
    m_scriptTextEdit->setMarginsForegroundColor(QColor("#808080"));

    m_scriptTextEdit->setAutoCompletionThreshold(3);
    m_scriptTextEdit->setAutoCompletionSource(QsciScintilla::AcsAll);

    m_scriptTextEdit->setBraceMatching(QsciScintilla::StrictBraceMatch);
    m_scriptTextEdit->setMatchedBraceBackgroundColor(QColor("#B4EEB4"));
    m_scriptTextEdit->setMatchedBraceForegroundColor(QColor("#FF0000"));

    m_scriptTextEdit->setMarginSensitivity(0, true);
    m_scriptTextEdit->markerDefine(QsciScintilla::Circle, BREAKPOINT_MARKER);

    // Setup script goto
    ui->gotoButton->setDefaultAction(ui->actionGo_To);
    connect(ui->actionGo_To, SIGNAL(triggered()), this, SLOT(showScriptGoTo()));
    disconnect(workspace()->scriptGoTo(), 0, 0, 0);
    connect(workspace()->scriptGoTo(), SIGNAL(gotoLine(int)), this, SLOT(gotoLine(int)));

    // Setup script search
    ui->searchButton->setDefaultAction(ui->actionSearch);
    connect(ui->actionSearch, SIGNAL(triggered()), this, SLOT(showScriptSearch()));
    disconnect(workspace()->scriptSearch(), 0, 0, 0);
    connect(workspace()->scriptSearch(), SIGNAL(search(QString,bool,bool,bool,bool)), this, SLOT(search(QString,bool,bool,bool,bool)));
    connect(workspace()->scriptSearch(), SIGNAL(next()), this, SLOT(findNext()));

    // Setup script replace
    ui->replaceButton->setDefaultAction(ui->actionReplace);
    connect(ui->actionReplace, SIGNAL(triggered()), this, SLOT(showScriptReplace()));
    disconnect(workspace()->scriptReplace(), 0, 0, 0);
    connect(workspace()->scriptReplace(), SIGNAL(search(QString,bool,bool,bool,bool)), this, SLOT(search(QString,bool,bool,bool,bool)));
    connect(workspace()->scriptReplace(), SIGNAL(next()), this, SLOT(findNext()));
    //connect(workspace()->scriptReplace(), SIGNAL(replace()), this, SLOT(replaceSelection()));

    // Load file content
    load();
}

ScriptEditor::~ScriptEditor()
{
    // TODO: Make the script editor settings global, not local
    // Save font size
    //int fontSize = m_scriptTextEdit->font().pointSize();
    //workspace()->settings()->setValue("script_editor/font_size", fontSize);

    // Save window size
    //workspace()->settings()->setValue("script_editor/subwindow_size", m_mdiWindow->size());

    //workspace()->settings()->setValue("script_editor/subwindow_size", m_mdiWindow->size());

    // Clear ui
    delete ui;
}

ScriptEditor *ScriptEditor::createFile(QString filePath)
{
    // Create script file
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(workspace(), "Could not create file",
                             "Could not create the file '" + filePath + "'. Make sure "
                             "you have read and write permissions to this directory.");
        file.close();
        return 0;
    }

    // Create empty file
    QTextStream stream(&file);
    stream << "\0";
    file.close();

    // Open newly created script file
    return (ScriptEditor*)workspace()->openFile(filePath);
}

QsciScintilla *ScriptEditor::scriptTextEdit()
{
    return m_scriptTextEdit;
}

void ScriptEditor::load()
{
    // Open script file
    QFile file(filePath());
    if(!file.open(QIODevice::ReadWrite))
    {
        // Unable to open file
        QMessageBox::critical(workspace(), "Unable to open file",
                              "Could not open " + filePath() + ". Make sure you "
                              "have permissions to read and write to the file.",
                              QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }

    // Setup text edit
    m_scriptTextEdit->setText(file.readAll());
    EditorBase::load();
}

void ScriptEditor::setModified(bool modified)
{
    if(m_scriptTextEdit->isModified() != modified)
        m_scriptTextEdit->setModified(modified);
    EditorBase::setModified(modified);
}

void ScriptEditor::updatePositionLabel(int line, int col)
{
    // Update statusbar
    ui->positionLabel->setText(QString("Line: ") + QString::number(line) + QString(", Col: ") + QString::number(col));
}

void ScriptEditor::aboutToActivate()
{
    disconnect(workspace()->scriptGoTo(), 0, 0, 0);
    connect(workspace()->scriptGoTo(), SIGNAL(gotoLine(int)), this, SLOT(gotoLine(int)));

    disconnect(workspace()->scriptSearch(), 0, 0, 0);
    connect(workspace()->scriptSearch(), SIGNAL(search(QString,bool,bool,bool,bool)), this, SLOT(search(QString,bool,bool,bool,bool)));
    connect(workspace()->scriptSearch(), SIGNAL(next()), this, SLOT(findNext()));

    disconnect(workspace()->scriptReplace(), 0, 0, 0);
    connect(workspace()->scriptReplace(), SIGNAL(search(QString,bool,bool,bool,bool)), this, SLOT(search(QString,bool,bool,bool,bool)));
    connect(workspace()->scriptReplace(), SIGNAL(replace(QString)), this, SLOT(replaceSelection(QString)));
    connect(workspace()->scriptReplace(), SIGNAL(replaceAll()), this, SLOT(replaceAll()));
}

void ScriptEditor::showScriptGoTo()
{
    workspace()->scriptGoTo()->show();
    workspace()->scriptSearch()->hide();
    workspace()->scriptReplace()->hide();
}

void ScriptEditor::gotoLine(int line)
{
    if(line <= 0) return;
    scrollToLine(line-1, 0);
}

void ScriptEditor::showScriptSearch()
{
    workspace()->scriptSearch()->show();
    workspace()->scriptReplace()->hide();
    workspace()->scriptGoTo()->hide();
    workspace()->scriptSearch()->setSearchPharse(m_scriptTextEdit->selectedText());
}

void ScriptEditor::showScriptReplace()
{
    workspace()->scriptReplace()->show();
    workspace()->scriptSearch()->hide();
    workspace()->scriptGoTo()->hide();
    workspace()->scriptReplace()->setSearchPharse(m_scriptTextEdit->selectedText());
}

void ScriptEditor::replaceSelection(const QString &phrase)
{
    m_scriptTextEdit->replace(phrase);
}

void ScriptEditor::replaceAll()
{
//    if(workspace()->scriptReplace()->replaceInAllFiles())
//    {
//        // Check line edit
//        QString phrase = workspace()->scriptReplace()->searchPhrase();

//        // Step 1 - Find all script files
//        QDirIterator dirit(Project::getProjectDir(), QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
//        QStringList files;
//        while(dirit.hasNext())
//        {
//            // Go to next
//            dirit.next();

//            // Only list script files
//            if(dirit.fileInfo().completeSuffix() == "as")
//                files.push_back(dirit.filePath());
//        }

//        // Step 2 - Read and replace
//        foreach(QString file, files)
//        {
//            // Open file
//            QFile f(file);
//            if(f.open(QIODevice::ReadOnly | QIODevice::Text))
//            {
//                // Create text stream
//                QString filestr = f.readAll();
//                QTextStream *stream = new QTextStream(&filestr);

//                // Read and replace
//                QString text = stream->readAll();
//                text.replace(phrase, workspace()->scriptReplace()->replacePhrase());
//                f.close();

//                // Save text to file
//                f.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
//                f.write(text.toLatin1());
//                f.close();
//            }
//        }
//    }else{
//        // Store information
//        QString phrase = workspace()->scriptReplace()->searchPhrase();
//        int pos = m_scriptTextEdit->textCursor().position();
//        QTextCursor cursor = m_scriptTextEdit->textCursor();
//        cursor.setPosition(0);
//        m_scriptTextEdit->setTextCursor(cursor);

//        // Find all occurences
//        int i = 0;
//        while(m_scriptTextEdit->find(phrase))
//        {
//            // Replace text
//            m_scriptTextEdit->textCursor().insertText(workspace()->scriptReplace()->replacePhrase());
//            i++;
//        }

//        if(i == 0)
//        {
//            // No occurences, reset cursor
//            QTextCursor cursor = m_scriptTextEdit->textCursor();
//            cursor.setPosition(pos);
//            m_scriptTextEdit->setTextCursor(cursor);
//            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase");
//        }
//    }
}

void ScriptEditor::scrollToLine(int line, int col)
{
    m_scriptTextEdit->setCursorPosition(line, col);
}

void ScriptEditor::save()
{
    // Open script file
    QFile file(filePath());
    if(file.open(QIODevice::ReadWrite | QFile::Truncate))
    {
        // Write script content to file
        QTextStream stream(&file);
        stream << m_scriptTextEdit->text();
        file.close();
        setModified(false);
    }
    EditorBase::save();
}

int ScriptEditor::breakpointCount() const
{
    return m_breakpoints.size();
}

bool ScriptEditor::isBreakpoint(const int line) const
{
    return m_breakpoints[line];
}

void ScriptEditor::resizeBreakpoints(int at, int dt)
{
    // Resize breakpoints
    if(dt > 0) m_breakpoints.insert(at, dt, false);
    else if(dt < 0) m_breakpoints.remove(at, -dt);
}

//------------------------------------------
// Debugging
//------------------------------------------

void ScriptEditor::toggleBreakpoint(int, int line, Qt::KeyboardModifiers)
{
    // Don't toggle empty lines
    if(m_scriptTextEdit->lineLength(line) > 1)
    {
        // Toggle breakpoint
        if(m_scriptTextEdit->markersAtLine(line) > 0)
        {
            m_scriptTextEdit->markerDelete(line, BREAKPOINT_MARKER);
        }else{
            m_scriptTextEdit->markerAdd(line, BREAKPOINT_MARKER);
        }
    }

//    if(debugger()->isRunning() && m_saved)
//    {
//        // Tell the debugger
//        if(m_breakpoints[line])
//            debugger()->addBreakpoint(m_filePath, line);
//        else
//            debugger()->removeBreakpoint(m_filePath, line);
//    }
}

void ScriptEditor::lineCountChanged(int start, int dt)
{
    resizeBreakpoints(start, dt);
}

//void ScriptEditor::showDebugVariable(QString name, QPoint position)
//{
//    // Check if it is a variable
//    if(!g_debugger)
//        return;
//    if(!g_debugger->isVariable(name))
//        return;

//    Debugger::DebugVariable *variable = g_debugger->variable(name);
//    if(variable->type == X2D::TextVariableType)
//    {
//        // Set tooltip
//        QToolTip::showText(position, name + " = " + variable->value.toString());
//    }
//    /*else if(mVariables[word].type == TextureVar)
//    {
//        // Convert image to HTML
//        QImage image = mVariables[word].image;
//        QByteArray ba;
//        QBuffer buffer(&ba);
//        buffer.open(QIODevice::WriteOnly);
//        image.save(&buffer, "PNG");
//        QString imgStr = QString("<img src=\"data:image/png;base64,%1\">").arg(
//                    QString(buffer.data().toBase64()));

//        // Set tooltip
//        QToolTip::showText(event->globalPos(), imgStr);
//    }*/
//}

//void ScriptEditor::codeFind()
//{
//    codeFinder->show();
//    codeFinder->setFindPharse(m_scriptTextEdit->selectedText());
//}

void ScriptEditor::search(const QString &phrase, bool forward, bool regexp, bool matchCase, bool wholeWords)
{
    // Search for text
    if(!m_scriptTextEdit->findFirst(phrase, regexp, matchCase, wholeWords, true, forward))
    {
        QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase");
    }
}

void ScriptEditor::findNext()
{
    m_scriptTextEdit->findNext();
}

void ScriptEditor::findAll()
{
    // TODO: Add
}

//-------------------------------------------
// ScriptGoTo
// The script go to line dialog
//-------------------------------------------

#include "ui_scriptgoto.h"

ScriptGoTo::ScriptGoTo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScriptGoTo)
{
    // Setup ui
    ui->setupUi(this);

    // Default buttons
    ui->gotoButton->setDefault(true);
    connect(ui->gotoButton, SIGNAL(clicked()), this, SLOT(gotoLine()));

    // Setup dialog
    setFixedSize(size());
    setWindowFlags(Qt::Dialog);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

ScriptGoTo::~ScriptGoTo()
{
    delete ui;
}

void ScriptGoTo::hideEvent(QHideEvent *)
{
    ui->gotoLineEdit->clear();
}

void ScriptGoTo::gotoLine()
{
    int line = QString(ui->gotoLineEdit->text()).toInt();
    if(line >= 0) {
        // Emit signal
        emit gotoLine(line);
        hide();
    }
}

//-------------------------------------------
// ScriptSearch
// The script search dialog
//-------------------------------------------

#include "ui_scriptsearch.h"

ScriptSearch::ScriptSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScriptSearch)
{
    // Setup ui
    ui->setupUi(this);

    // Default buttons
    ui->nextButton->setDefault(true);

    // Connect signals
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(searchForwards()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(setNextDefault()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(searchBackwards()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(setPrevDefault()));
    connect(ui->findAllButton, SIGNAL(clicked()), this, SIGNAL(findAll()));

    // Setup dialog
    setFixedSize(size());
    setWindowFlags(Qt::Dialog);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //setWindowIcon(QIcon(":/editors/script/icons/empty.png"));
}

ScriptSearch::~ScriptSearch()
{
    delete ui;
}

void ScriptSearch::setSearchPharse(QString phrase)
{
    ui->searchPhraseEdit->setText(phrase);
}

QString ScriptSearch::searchPhrase()
{
    return ui->searchPhraseEdit->text();
}

void ScriptSearch::closeEvent(QCloseEvent *e)
{
    hide();
    e->ignore();
}

void ScriptSearch::showEvent(QShowEvent *e)
{
    // Make sure the typing field has focus
    ui->searchPhraseEdit->setFocus();
    QDialog::showEvent(e);
}

void ScriptSearch::find(const QString &phrase, const bool forward)
{
    int flags = (forward ? 1 << 0 : 0 ) |
            (ui->regexpCheck->isChecked() ? 1 << 1 : 0 ) |
            (ui->matchCaseCheck->isChecked() ? 1 << 2 : 0 ) |
            (ui->wholeWordsCheck->isChecked() ? 1 << 3 : 0 );
    if(m_prevParam.phrase != phrase || m_prevParam.flags != flags)
    {
        emit search(phrase, flags & (1 << 0), flags & (1 << 1), flags & (1 << 2), flags & (1 << 3));
    }else{
        emit next();
    }
    m_prevParam.phrase = phrase;
    m_prevParam.flags = flags;
}

void ScriptSearch::searchForwards()
{
    find(ui->searchPhraseEdit->text(), true);
}

void ScriptSearch::searchBackwards()
{
    find(ui->searchPhraseEdit->text(), false);
}

void ScriptSearch::setNextDefault()
{
    ui->nextButton->setDefault(true);
    ui->prevButton->setDefault(false);
}

void ScriptSearch::setPrevDefault()
{
    ui->nextButton->setDefault(false);
    ui->prevButton->setDefault(true);
}

//-------------------------------------------
// ScriptReplace
// The script reaplce dialog
//-------------------------------------------

#include "ui_scriptreplace.h"
ScriptReplace::ScriptReplace(QWidget *parent) :
    ScriptSearch(parent),
    ui(new Ui::ScriptReplace)
{
    // Setup ui
    ui->setupUi(this);

    // Default buttons
    ui->nextButton->setDefault(true);

    // Connect signals
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(searchForwards()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(setNextDefault()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(searchBackwards()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(setPrevDefault()));
    connect(ui->replaceButton, SIGNAL(clicked()), this, SLOT(replaceSelection()));
    //connect(ui->replaceAllButton, SIGNAL(clicked()), this, SLOT(replaceAll()));

    // Setup dialog
    setFixedSize(size());
    setWindowFlags(Qt::Dialog);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //setWindowIcon(QIcon(":/editors/script/icons/empty.png"));
}

ScriptReplace::~ScriptReplace()
{
    delete ui;
}

void ScriptReplace::setReplacePharse(QString phrase)
{
    ui->replacePhraseEdit->setText(phrase);
}

QString ScriptReplace::replacePhrase()
{
    return ui->replacePhraseEdit->text();
}

bool ScriptReplace::replaceInAllFiles()
{
    return ui->tempBox->isChecked();
}

void ScriptReplace::replaceSelection()
{
    emit replace(ui->replacePhraseEdit->text());
}
