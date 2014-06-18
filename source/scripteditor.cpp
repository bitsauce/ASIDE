//     _                                     ____  ____
//    / \  _   _ _ __ ___  _ __ __ _  __  __|___ \|  _ \
//   / _ \| | | |  __/ _ \|  __/ _  | \ \/ /  __) | | | |
//  / ___ \ |_| | | | (_) | | | (_| |  >  <  / __/| |_| |
// /_/   \_\__ _|_|  \___/|_|  \__ _| /_/\_\|_____|____/
//		MixedGraphics (C)

#include "ui_scripteditor.h"
#include "scripteditor.h"
#include "workspace.h"
#include "project.h"
#include "settings.h"
#include "debugger.h"

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>

const int BREAKPOINT_MARKER = 1;
const int LINE_MARKER = 2;

//---------------------------------------
// ScriptEditor
// The default script editor
//---------------------------------------

ScriptEditor::ScriptEditor(QString filePath, QString defaultTitle, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScriptEditor),
    m_filePath(filePath),
    m_defaultTitle(defaultTitle)
{
    // Setup ui
    ui->setupUi(this);

    // Create mdi window
    m_mdiWindow = workspace()->createMdiWindow(this);
    m_mdiWindow->setWindowTitle(defaultTitle);
    m_mdiWindow->resize(settings()->value("script_editor/subwindow_size", QSize(540, 400)).toSize());
    m_mdiWindow->show();
    QObject::connect(m_mdiWindow, SIGNAL(aboutToActivate()), this, SLOT(aboutToActivate()));

    // Create the script text edit
    m_scriptTextEdit = new QsciScintilla(this);
    ui->gridLayout->addWidget(m_scriptTextEdit);
    connect(m_scriptTextEdit, SIGNAL(marginClicked(int,int,Qt::KeyboardModifiers)), this, SLOT(toggleBreakpoint(int,int,Qt::KeyboardModifiers)));
    connect(m_scriptTextEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));
    connect(m_scriptTextEdit, SIGNAL(modificationChanged(bool)), this, SLOT(updateSaveState(bool)));
    connect(m_scriptTextEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(updatePositionLabel(int, int)));
    connect(m_scriptTextEdit, SIGNAL(lineCountChanged(int,int)), this, SLOT(lineCountChanged(int,int)));

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
    connect(workspace()->scriptSearch(), SIGNAL(findNext()), this, SLOT(findNext()));
    connect(workspace()->scriptSearch(), SIGNAL(findPrev()), this, SLOT(findPrev()));
    connect(workspace()->scriptSearch(), SIGNAL(findAll()), this, SLOT(findAll()));

    // Setup script replace
    ui->replaceButton->setDefaultAction(ui->actionReplace);
    connect(ui->actionReplace, SIGNAL(triggered()), this, SLOT(showScriptReplace()));
    disconnect(workspace()->scriptReplace(), 0, 0, 0);
    connect(workspace()->scriptReplace(), SIGNAL(findNext()), this, SLOT(findNext()));
    connect(workspace()->scriptReplace(), SIGNAL(findPrev()), this, SLOT(findPrev()));
    connect(workspace()->scriptReplace(), SIGNAL(replace()), this, SLOT(replaceSelection()));
    connect(workspace()->scriptReplace(), SIGNAL(replaceAll()), this, SLOT(replaceAll()));

    // Load file
    loadFile(filePath);
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

void ScriptEditor::loadProject(QString projectPath, QString projectName)
{
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
    return openFile(filePath);
}

ScriptEditor *ScriptEditor::openFile(QString filePath)
{
    // Get title string
    QString title = filePath;
    title.remove(Project::getProjectDir() + "/");

    // Create a script editor
    ScriptEditor *editor = new ScriptEditor(filePath, title, workspace());

    // Add file to editor
    return editor;
}

QsciScintilla *ScriptEditor::scriptTextEdit()
{
    return m_scriptTextEdit;
}

void ScriptEditor::loadFile(const QString &filePath)
{
    // Open script file
    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        // Unable to open file
        QMessageBox::critical(workspace(), "Unable to open file",
                              "Could not open " + filePath + ". Make sure you "
                              "have permissions to read and write to the file.",
                              QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }

    // Read updated file
    m_scriptTextEdit->setText(file.readAll());
    resetSaveState();
    m_filePath = filePath;

    // Resize breakpoints
    //resizeBreakpoints(0, m_scriptTextEdit->document()->lineCount());
}

QString ScriptEditor::filePath() const
{
    return m_filePath;
}

QMdiSubWindow *ScriptEditor::mdiWindow() const
{
    return m_mdiWindow;
}

bool ScriptEditor::isSaved() const
{
    return !m_scriptTextEdit->isModified();
}

void ScriptEditor::closeEvent(QCloseEvent *event)
{
    // Check if we need to save
    if(m_scriptTextEdit->isModified())
    {
        // Display the dialog
        int r = QMessageBox::question(this, "Save", "Do you want to save the changes?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(r == QMessageBox::Yes)
        {
            // Yes, save here
            save();
        } else if(r == QMessageBox::Cancel) {
            // Cancel the close operation
            event->ignore();
            return;
        }

        // No need for saving
        m_scriptTextEdit->setModified(false);;
    }
    emit fileClosed(m_filePath);
}

void ScriptEditor::resetSaveState()
{
    m_scriptTextEdit->setModified(false);
    updateSaveState(false);
}

void ScriptEditor::updateSaveState(bool modified)
{
    if(modified)
    {
        m_mdiWindow->setWindowTitle(m_defaultTitle + "*");
    }else{
        m_mdiWindow->setWindowTitle(m_defaultTitle);
    }
}

void ScriptEditor::textChanged()
{
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
    connect(workspace()->scriptSearch(), SIGNAL(findNext()), this, SLOT(findNext()));
    connect(workspace()->scriptSearch(), SIGNAL(findPrev()), this, SLOT(findPrev()));
    connect(workspace()->scriptSearch(), SIGNAL(findAll()), this, SLOT(findAll()));

    disconnect(workspace()->scriptReplace(), 0, 0, 0);
    connect(workspace()->scriptReplace(), SIGNAL(findNext()), this, SLOT(findNext()));
    connect(workspace()->scriptReplace(), SIGNAL(findPrev()), this, SLOT(findPrev()));
    connect(workspace()->scriptReplace(), SIGNAL(replace()), this, SLOT(replaceSelection()));
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
//    workspace()->scriptSearch()->show();
//    workspace()->scriptReplace()->hide();
//    workspace()->scriptGoTo()->hide();
//    workspace()->scriptSearch()->setSearchPharse(m_scriptTextEdit->textCursor().selectedText());
}

void ScriptEditor::showScriptReplace()
{
//    workspace()->scriptReplace()->show();
//    workspace()->scriptSearch()->hide();
//    workspace()->scriptGoTo()->hide();
//    workspace()->scriptReplace()->setSearchPharse(m_scriptTextEdit->textCursor().selectedText());
}

void ScriptEditor::replaceSelection()
{
//    // Check if phrase matches
//    QString selectedText = m_scriptTextEdit->textCursor().selectedText();
//    if(selectedText != workspace()->scriptReplace()->searchPhrase())
//    {
//        QMessageBox::information(this, "Replace selection not equal",
//                                 "The selected text is not equal to the replace keyphrase");
//        return;
//    }

//    // Replace text
//    m_scriptTextEdit->textCursor().insertText(workspace()->scriptReplace()->replacePhrase());
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

//---------------------------------------
// Editor
//---------------------------------------

//void ScriptEditor::editChanged()
//{
//    // Set need save
//    if(!m_needSave)
//    {
//        m_mdiWindow->setWindowTitle(m_title + "*");
//        m_needSave = true;
//    }

//    // Update line nuber area
//    m_scriptTextEdit->updateLineCount();
//}

////
////  Debug
////

void ScriptEditor::scrollToLine(int line, int col)
{
//    // Move text cursor to line
//    QTextCursor cursor(m_scriptTextEdit->textCursor());
//    cursor.setPosition(0);
//    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line);
//    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, col);
//    m_scriptTextEdit->setTextCursor(cursor);

//    // Center the line
//    int vscroll = m_scriptTextEdit->fontMetrics().lineSpacing()*line;
//    vscroll -= m_scriptTextEdit->height()/2;
//    m_scriptTextEdit->verticalScrollBar()->setValue(vscroll);

//    // Repaint the editor
//    m_scriptTextEdit->repaint();
}

void ScriptEditor::save()
{
    // Open script file
    QFile file(m_filePath);
    if(file.open(QIODevice::ReadWrite | QIODevice::Text | QFile::Truncate))
    {
        // Write script content to file
        QTextStream stream(&file);
        stream << m_scriptTextEdit->text();
        file.close();
        resetSaveState();
    }
    emit fileSaved(m_filePath);

    // TODO: Save breakpoints
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

void ScriptEditor::findNext()
{
//    // Search forwards
//    QString phrase;
//    if(workspace()->scriptSearch()->isVisible())
//        phrase = workspace()->scriptSearch()->searchPhrase();
//    else
//        phrase = workspace()->scriptReplace()->searchPhrase();
//    int pos = m_scriptTextEdit->textCursor().position();
//    if(!m_scriptTextEdit->find(phrase))
//    {
//        // EOF, move to begining
//        QTextCursor cursor = m_scriptTextEdit->textCursor();
//        cursor.setPosition(0);
//        m_scriptTextEdit->setTextCursor(cursor);
//        if(!m_scriptTextEdit->find(phrase))
//        {
//            QTextCursor cur = m_scriptTextEdit->textCursor();
//            cur.setPosition(pos);
//            m_scriptTextEdit->setTextCursor(cur);
//            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase");
//        }
//    }
}

void ScriptEditor::findPrev()
{
//    // Search backwards
//    QString phrase;
//    if(workspace()->scriptSearch()->isVisible())
//        phrase = workspace()->scriptSearch()->searchPhrase();
//    else
//        phrase = workspace()->scriptReplace()->searchPhrase();
//    int pos = m_scriptTextEdit->textCursor().position();
//    if(!m_scriptTextEdit->find(phrase, QTextDocument::FindBackward))
//    {
//        // EOF, move to end
//        QTextCursor cursor = m_scriptTextEdit->textCursor();
//        cursor.movePosition(QTextCursor::End);
//        m_scriptTextEdit->setTextCursor(cursor);
//        if(!m_scriptTextEdit->find(phrase, QTextDocument::FindBackward))
//        {
//            QTextCursor cur = m_scriptTextEdit->textCursor();
//            cur.setPosition(pos);
//            m_scriptTextEdit->setTextCursor(cur);
//            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase in the text");
//        }
//    }
}

void ScriptEditor::findAll()
{
    // TODO: Add
}

//---------------------------------------------------
// AngelScriptHL
// The script highligter and praser
//---------------------------------------------------

AngelScriptPraser::AngelScriptPraser(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    // Keyword format
    datatypeFormat.setForeground(Qt::blue);
    QStringList datatypeKeywords;
    datatypeKeywords << "\\bvoid\\b" << "\\bint8\\b" << "\\bint16\\b"
                    << "\\bint\\b" << "\\bint64\\b" << "\\buint8\\b"
                    << "\\buint16\\b" << "\\buint\\b" << "\\buint64\\b"
                    << "\\bfloat\\b" << "\\bdouble\\b" << "\\bbool\\b"
                    << "\\bstring\\b" << "\\bprivate\\b" << "\\bvec2\\b"
                    << "\\bvec3\\b" << "\\bvec4\\b" << "\\brect2\\b"
                    << "\\brect2i\\b" ;

    // Phrase keywords
    foreach(const QString &keyword, datatypeKeywords)
        datatypeExpressions.append(QRegExp(keyword));

    // Keyword format
    statementFormat.setForeground(Qt::darkYellow);
    QStringList statementKeywords;
    statementKeywords << "\\bconst\\b" << "\\bcase\\b" << "\\bdefault\\b"
                      << "\\breturn\\b" << "\\bbreak\\b" << "\\bcontinue\\b"
                      << "\\bthis\\b" << "\\bnull\\b" << "\\btrue\\b"
                      << "\\bfalse\\b" << "\\bif\\b" << "\\belse\\b"
                      << "\\bfor\\b" << "\\bwhile\\b" << "\\bswitch\\b"
                      << "\\bclass\\b" << "\\benum\\b" << "\\bnamespace\\b"
                      << "\\bset\\b" << "\\bget\\b" << "\\band\\b" << "\\bcast\\b";

    // Phrase keywords
    foreach(const QString &keyword, statementKeywords)
        statementExpressions.append(QRegExp(keyword));

    // Include format
    includeFormat.setForeground(Qt::darkBlue);
    includeExpression = QRegExp("include");

    // Single line format
    commentFormat.setForeground(Qt::darkGreen);
    singleLineExpression = QRegExp("//[^\n]*");

    // Multi line format
    multiLineStartExpression = QRegExp("/\\*");
    multiLineEndExpression = QRegExp("\\*/");

    // Quotation format
    quotationFormat.setForeground(Qt::darkGreen);
    quotationExpression = QRegExp("\"");
}

#define MULTI_LINE_STATE    (1 << 0)

void AngelScriptPraser::highlightBlock(const QString &text)
{
    // Define vars
    int begin, end, len;
    int blockNum = currentBlock().blockNumber();
    int blockState = 0;
    int prevBlockState = previousBlockState();
    if(prevBlockState < 0)
        prevBlockState = 0;

    // Apply #include
    begin = includeExpression.indexIn(text);
    if(begin-1 >= 0)
    {
        len = 8;
        if(text.at(begin-1) == '#')
            setFormat(begin-1, len, includeFormat);
    }

    // Apply datatype highlighting
    foreach(const QRegExp &expression, datatypeExpressions)
    {
        begin = expression.indexIn(text);
        while(begin >= 0)
        {
            len = expression.matchedLength();
            setFormat(begin, len, datatypeFormat);
            begin = expression.indexIn(text, begin + len);
        }
    }

    // Apply statement highlighting
    foreach(const QRegExp &expression, statementExpressions)
    {
        begin = expression.indexIn(text);
        while(begin >= 0)
        {
            len = expression.matchedLength();
            setFormat(begin, len, statementFormat);
            begin = expression.indexIn(text, begin + len);
        }
    }

    // Apply quotations
    begin = quotationExpression.indexIn(text);
    while(begin >= 0)
    {
        len = quotationExpression.matchedLength();
        if(begin-1 < 0 || text.at(begin-1) != '\\')
        {
            end = quotationExpression.indexIn(text, begin+1);
            while(end >= 0)
            {
                if(text.at(end-1) == '\\')
                    end = quotationExpression.indexIn(text, end+1);
                else break;
            }

            if(end != -1)
                len = end - begin + quotationExpression.matchedLength();
            else
                len = text.size() - begin;
            setFormat(begin, len, quotationFormat);
        }
        begin = quotationExpression.indexIn(text, begin + len);
    }

    // Remove comments from block
    comments.remove(blockNum);

    // Apply comments
    begin = 0;
    if((prevBlockState & MULTI_LINE_STATE) == 0)
        begin = multiLineStartExpression.indexIn(text);
    if(begin >= 0)
    {
        // We might have a multi-line comment,
        // check for single-line comment override
        int singleLineBegin = singleLineExpression.indexIn(text);
        if(singleLineBegin < begin && singleLineBegin != -1)
        {
            // Apply single line override
            setFormat(singleLineBegin, text.size(), commentFormat);
            Comment comment = { singleLineBegin, text.size() };
            comments.insert(blockNum, comment);
        }else{
            while(begin >= 0)
            {
                if((prevBlockState & MULTI_LINE_STATE) == 0)
                    end = multiLineEndExpression.indexIn(text, begin+2);
                else
                    end = multiLineEndExpression.indexIn(text, begin);
                if(end == -1)
                {
                    blockState |= MULTI_LINE_STATE;
                    //setCurrentBlockState(MULTI_LINE_STATE);
                    len = text.length() - begin;
                }else{
                    len = end - begin + multiLineEndExpression.matchedLength();
                }
                setFormat(begin, len, commentFormat);
                Comment comment = { begin, end+1 };
                comments.insert(blockNum, comment);

                // Check for single-line comment
                begin = multiLineStartExpression.indexIn(text, begin + len);
                if(end != -1)
                {
                    singleLineBegin = singleLineExpression.indexIn(text, end);
                    if((begin == -1 || (begin != -1 && singleLineBegin < begin)) && singleLineBegin != -1)
                    {
                        // Apply single line override
                        setFormat(singleLineBegin, text.size(), commentFormat);
                        Comment comment = { singleLineBegin, text.size() };
                        comments.insert(blockNum, comment);
                        break;
                    }
                }
            }
        }
    }else{
        // There is no multiline comment,
        // check for single-line comment
        int singleLineBegin = singleLineExpression.indexIn(text);
        if(singleLineBegin >= 0)
        {
            setFormat(singleLineBegin, text.size(), commentFormat);
            Comment comment = { singleLineBegin, text.size() };
            comments.insert(blockNum, comment);
        }
    }

    setCurrentBlockState(blockState);
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
    connect(ui->nextButton, SIGNAL(clicked()), this, SIGNAL(findNext()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(setNextDefault()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SIGNAL(findPrev()));
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
    QDialog(parent),
    ui(new Ui::ScriptReplace)
{
    // Setup ui
    ui->setupUi(this);

    // Default buttons
    ui->nextButton->setDefault(true);

    // Connect signals
    connect(ui->nextButton, SIGNAL(clicked()), this, SIGNAL(findNext()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(setNextDefault()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SIGNAL(findPrev()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(setPrevDefault()));
    connect(ui->replaceButton, SIGNAL(clicked()), this, SIGNAL(replace()));
    connect(ui->replaceAllButton, SIGNAL(clicked()), this, SIGNAL(replaceAll()));

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

void ScriptReplace::setSearchPharse(QString phrase)
{
    ui->searchPhraseEdit->setText(phrase);
}

QString ScriptReplace::searchPhrase()
{
    return ui->searchPhraseEdit->text();
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

void ScriptReplace::closeEvent(QCloseEvent *e)
{
    hide();
    e->ignore();
}

void ScriptReplace::showEvent(QShowEvent *e)
{
    // Make sure the typing field has focus
    ui->searchPhraseEdit->setFocus();
    QDialog::showEvent(e);
}

void ScriptReplace::setNextDefault()
{
    ui->nextButton->setDefault(true);
    ui->prevButton->setDefault(false);
}

void ScriptReplace::setPrevDefault()
{
    ui->nextButton->setDefault(false);
    ui->prevButton->setDefault(true);
}
