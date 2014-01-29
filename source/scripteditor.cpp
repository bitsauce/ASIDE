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
#include "scriptintel.h"
#include "settings.h"
#include "debugger.h"

//---------------------------------------
// ScriptEditor
// The default script editor
//---------------------------------------

ScriptEditor::ScriptEditor(QString filePath, QString defaultTitle, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScriptEditor),
    m_filePath(filePath),
    m_defaultTitle(defaultTitle),
    m_saved(true),
    m_changesSinceSave(0)
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
    m_scriptTextEdit = new ScriptTextEdit(this);
    ui->gridLayout->addWidget(m_scriptTextEdit);
    connect(m_scriptTextEdit, SIGNAL(toggleBreakpoint(int)), this, SLOT(toggleBreakpoint(int)));
    connect(m_scriptTextEdit, SIGNAL(textChanged()), this, SLOT(textChanged()));
    connect(m_scriptTextEdit, SIGNAL(undoPerformed()), this, SLOT(textUndo()));
    connect(m_scriptTextEdit, SIGNAL(redoPerformed()), this, SLOT(textRedo()));
    connect(m_scriptTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(updatePositionLabel()));
    connect(m_scriptTextEdit, SIGNAL(lineCountChanged(int,int)), this, SLOT(lineCountChanged(int,int)));

    // Create script intel
    m_scriptIntel = new ScriptIntel(filePath, this);

    // Setup namespace and function lists
    connect(ui->functionList, SIGNAL(activated(QString)), this, SLOT(functionIndexChanged(QString)));
    connect(ui->namedScopeList, SIGNAL(activated(QString)), this, SLOT(namedScopeIndexChanged(QString)));

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

    // Setup the script text edit
    int fontSize = settings()->value("script_editor/font_size", 9).toInt();
    QFont font("Courier New", fontSize, QFont::Light);
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    m_scriptTextEdit->setFont(font);

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
    // Initialize script intel
    ScriptIntel::Init();
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
    editor->updateIntel();

    // Add file to editor
    return editor;
}

ScriptTextEdit *ScriptEditor::scriptTextEdit()
{
    return m_scriptTextEdit;
}

ScriptIntel *ScriptEditor::scriptIntel()
{
    return m_scriptIntel;
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
    resizeBreakpoints(0, m_scriptTextEdit->document()->lineCount());
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
    return m_saved;
}

void ScriptEditor::closeEvent(QCloseEvent *event)
{
    // Check if we need to save
    if(!m_saved)
    {
        // Display the dialog
        int r = QMessageBox::question(this, "Save",
                                      "Do you want to save the changes?",
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
        m_saved = true;
    }
    emit fileClosed(m_filePath);
}

void ScriptEditor::resetSaveState()
{
    m_saved = true;
    m_mdiWindow->setWindowTitle(m_defaultTitle);
    m_changesSinceSave = 0;
}

void ScriptEditor::textChanged()
{
    if(m_saved) {
        m_mdiWindow->setWindowTitle(m_defaultTitle + "*");
        m_saved = false;
    }

    m_changesSinceSave++;
}

void ScriptEditor::textUndo()
{
    m_changesSinceSave--;
    if(m_changesSinceSave == 0)
        resetSaveState();
    else if(m_saved)
    {
        m_mdiWindow->setWindowTitle(m_defaultTitle + "*");
        m_saved = false;
    }
}

void ScriptEditor::textRedo()
{
    m_changesSinceSave++;
    if(m_changesSinceSave == 0)
        resetSaveState();
    else if(m_saved)
    {
        m_mdiWindow->setWindowTitle(m_defaultTitle + "*");
        m_saved = false;
    }
}

void ScriptEditor::updatePositionLabel()
{
    // Update statusbar
    int col = m_scriptTextEdit->textCursor().columnNumber();
    int line = m_scriptTextEdit->textCursor().blockNumber();
    ui->positionLabel->setText(QString("Line: ") + QString::number(line) + QString(", Col: ") + QString::number(col));

    // Finc current namespace
    ScriptIntel::Scope *currScope = m_scriptIntel->scopeAt(m_scriptTextEdit->textCursor().position());
    ScriptIntel::Scope *namedScope = 0;
    ScriptIntel::Scope *funcScope = 0;
    while(currScope->parent != 0)
    {
        if(currScope->type == ScriptIntel::ClassScope)
            namedScope = currScope;
        else if(currScope->type == ScriptIntel::FunctionScope)
            funcScope = currScope;
        currScope = currScope->parent;
    }

    if(namedScope)
    {
        int idx = ui->namedScopeList->findText(namedScope->name);
        if(idx >= 0)
        {
            // Show local scope function list
            ui->functionList->clear();
            ui->functionList->addItem("[ Methods ]");

            // Add all member functions to function list
            foreach(ScriptIntel::Scope *scope, namedScope->scopes)
            {
                if(scope->type  == ScriptIntel::FunctionScope)
                    ui->functionList->addItem(scope->name);
            }

            // Set named scope
            ui->namedScopeList->setCurrentIndex(idx);
        }
    }else{
        // Show global function list
        ui->functionList->clear();
        ui->functionList->addItem("[ Functions ]");

        // Populate list
        ScriptIntel::Scope *globalScope = m_scriptIntel->globalScope();
        foreach(ScriptIntel::Scope *scope, globalScope->scopes)
        {
            if(scope->file == m_filePath && scope->type == ScriptIntel::FunctionScope)
                ui->functionList->addItem(scope->name);
        }

        // Set named scope to global
        ui->namedScopeList->setCurrentIndex(0);
    }

    // Find current function namespace
    if(funcScope)
    {
        int idx = ui->functionList->findText(funcScope->name);
        if(idx >= 0)
        {
            if(idx != ui->functionList->currentIndex())
                ui->functionList->setCurrentIndex(idx);
        }else
            ui->functionList->addItem(funcScope->name);
    }else
        ui->functionList->setCurrentIndex(0);
}

void ScriptEditor::updateIntel()
{
    // Update file by text
    ScriptIntel::phraseFileByText(m_filePath, m_scriptTextEdit->toPlainText());

    // Update scope list
    ui->namedScopeList->clear();
    ui->namedScopeList->addItem("[ Global Scope ]");
    ScriptIntel::Scope *globalScope = m_scriptIntel->globalScope();
    foreach(ScriptIntel::Scope *scope, globalScope->scopes)
    {
        if(scope->file == m_filePath && scope->type == ScriptIntel::ClassScope)
            ui->namedScopeList->addItem(scope->name);
    }
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

void ScriptEditor::functionIndexChanged(QString text)
{
    // Do nothing if global func was selected
    if(ui->functionList->currentIndex() == 0)
        return;

    // Get named scope by definition
    ScriptIntel::Scope *namedScope;
    if(ui->namedScopeList->currentIndex() == 0) namedScope = m_scriptIntel->globalScope();
    else namedScope = ScriptIntel::findNamedScope(m_scriptIntel->globalScope(), ui->namedScopeList->currentText());

    // Get function scope
    ScriptIntel::Scope *funcScope = ScriptIntel::findNamedScope(namedScope, text);
    if(funcScope)
    {
        // Scroll to function
        QTextCursor tc(m_scriptTextEdit->textCursor());
        tc.setPosition(funcScope->begin);
        tc.movePosition(QTextCursor::EndOfLine);
        scrollToLine(tc.blockNumber(), tc.columnNumber());
    }
}

void ScriptEditor::namedScopeIndexChanged(QString text)
{
    // Do nothing if global scope was selected
    if(ui->namedScopeList->currentIndex() == 0)
        return;

    // Get named scope by definition
    ScriptIntel::Scope *namedScope = ScriptIntel::findNamedScope(m_scriptIntel->globalScope(), text);
    if(namedScope)
    {
        // Scroll to function
        QTextCursor tc(m_scriptTextEdit->textCursor());
        tc.setPosition(namedScope->begin);
        tc.movePosition(QTextCursor::EndOfLine);
        scrollToLine(tc.blockNumber(), tc.columnNumber());
    }
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
    workspace()->scriptSearch()->setSearchPharse(m_scriptTextEdit->textCursor().selectedText());
}

void ScriptEditor::showScriptReplace()
{
    workspace()->scriptReplace()->show();
    workspace()->scriptSearch()->hide();
    workspace()->scriptGoTo()->hide();
    workspace()->scriptReplace()->setSearchPharse(m_scriptTextEdit->textCursor().selectedText());
}

void ScriptEditor::replaceSelection()
{
    // Check if phrase matches
    QString selectedText = m_scriptTextEdit->textCursor().selectedText();
    if(selectedText != workspace()->scriptReplace()->searchPhrase())
    {
        QMessageBox::information(this, "Replace selection not equal",
                                 "The selected text is not equal to the replace keyphrase");
        return;
    }

    // Replace text
    m_scriptTextEdit->textCursor().insertText(workspace()->scriptReplace()->replacePhrase());
}

void ScriptEditor::replaceAll()
{
    if(workspace()->scriptReplace()->replaceInAllFiles())
    {
        // Check line edit
        QString phrase = workspace()->scriptReplace()->searchPhrase();

        // Step 1 - Find all script files
        QDirIterator dirit(Project::getProjectDir(), QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
        QStringList files;
        while(dirit.hasNext())
        {
            // Go to next
            dirit.next();

            // Only list script files
            if(dirit.fileInfo().completeSuffix() == "as")
                files.push_back(dirit.filePath());
        }

        // Step 2 - Read and replace
        foreach(QString file, files)
        {
            // Open file
            QFile f(file);
            if(f.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                // Create text stream
                QString filestr = f.readAll();
                QTextStream *stream = new QTextStream(&filestr);

                // Read and replace
                QString text = stream->readAll();
                text.replace(phrase, workspace()->scriptReplace()->replacePhrase());
                f.close();

                // Save text to file
                f.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
                f.write(text.toLatin1());
                f.close();
            }
        }
    }else{
        // Store information
        QString phrase = workspace()->scriptReplace()->searchPhrase();
        int pos = m_scriptTextEdit->textCursor().position();
        QTextCursor cursor = m_scriptTextEdit->textCursor();
        cursor.setPosition(0);
        m_scriptTextEdit->setTextCursor(cursor);

        // Find all occurences
        int i = 0;
        while(m_scriptTextEdit->find(phrase))
        {
            // Replace text
            m_scriptTextEdit->textCursor().insertText(workspace()->scriptReplace()->replacePhrase());
            i++;
        }

        if(i == 0)
        {
            // No occurences, reset cursor
            QTextCursor cursor = m_scriptTextEdit->textCursor();
            cursor.setPosition(pos);
            m_scriptTextEdit->setTextCursor(cursor);
            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase");
        }
    }
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
    // Move text cursor to line
    QTextCursor cursor(m_scriptTextEdit->textCursor());
    cursor.setPosition(0);
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, col);
    m_scriptTextEdit->setTextCursor(cursor);

    // Center the line
    int vscroll = m_scriptTextEdit->fontMetrics().lineSpacing()*line;
    vscroll -= m_scriptTextEdit->height()/2;
    m_scriptTextEdit->verticalScrollBar()->setValue(vscroll);

    // Repaint the editor
    m_scriptTextEdit->repaint();
}

void ScriptEditor::save()
{
    // Open script file
    QFile file(m_filePath);
    if(file.open(QIODevice::ReadWrite | QIODevice::Text | QFile::Truncate))
    {
        // Set saving
        m_saved = true;

        // Write script content to file
        QTextStream stream(&file);
        stream << m_scriptTextEdit->toPlainText();
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

////------------------------------------------
//// Debugging
////------------------------------------------

//void ScriptEditor::updateStatusbar()
//{
//    // Update position label
//    int col = m_scriptTextEdit->textCursor().columnNumber();
//    int line = m_scriptTextEdit->textCursor().blockNumber();
//    posLabel->setText(QString("Line: ") + QString::number(line) + QString(", Col: ") + QString::number(col));
//}

void ScriptEditor::toggleBreakpoint(const int line)
{
    // Sanity check
    if(line >= m_breakpoints.size())
        return;

    // Don't toggle empty lines
    QTextCursor cursor = m_scriptTextEdit->textCursor();
    cursor.setPosition(0);
    cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line);
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    QString lineStr = cursor.selectedText();
    if(lineStr.isEmpty())
        return;

    // Toggle breakpoint
    m_breakpoints[line] = !m_breakpoints[line];

    if(debugger()->isRunning() && m_saved)
    {
        // Tell the debugger
        if(m_breakpoints[line])
            debugger()->addBreakpoint(m_filePath, line);
        else
            debugger()->removeBreakpoint(m_filePath, line);
    }
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
    // Search forwards
    QString phrase;
    if(workspace()->scriptSearch()->isVisible())
        phrase = workspace()->scriptSearch()->searchPhrase();
    else
        phrase = workspace()->scriptReplace()->searchPhrase();
    int pos = m_scriptTextEdit->textCursor().position();
    if(!m_scriptTextEdit->find(phrase))
    {
        // EOF, move to begining
        QTextCursor cursor = m_scriptTextEdit->textCursor();
        cursor.setPosition(0);
        m_scriptTextEdit->setTextCursor(cursor);
        if(!m_scriptTextEdit->find(phrase))
        {
            QTextCursor cur = m_scriptTextEdit->textCursor();
            cur.setPosition(pos);
            m_scriptTextEdit->setTextCursor(cur);
            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase");
        }
    }
}

void ScriptEditor::findPrev()
{
    // Search backwards
    QString phrase;
    if(workspace()->scriptSearch()->isVisible())
        phrase = workspace()->scriptSearch()->searchPhrase();
    else
        phrase = workspace()->scriptReplace()->searchPhrase();
    int pos = m_scriptTextEdit->textCursor().position();
    if(!m_scriptTextEdit->find(phrase, QTextDocument::FindBackward))
    {
        // EOF, move to end
        QTextCursor cursor = m_scriptTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        m_scriptTextEdit->setTextCursor(cursor);
        if(!m_scriptTextEdit->find(phrase, QTextDocument::FindBackward))
        {
            QTextCursor cur = m_scriptTextEdit->textCursor();
            cur.setPosition(pos);
            m_scriptTextEdit->setTextCursor(cur);
            QMessageBox::information(this, "Could not find", "Could not find the spesified keyphrase in the text");
        }
    }
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

//---------------------------------------------------
// ScriptTextEdit
// The script text editor
//---------------------------------------------------

ScriptTextEdit::ScriptTextEdit(ScriptEditor *scriptEdit) :
    QTextEdit(scriptEdit),
    m_scriptEditor(scriptEdit)
{
    // Create line number area
    m_lineNumberArea = new LineNumberArea(this);
    connect(m_lineNumberArea, SIGNAL(clicked(QPoint)), this, SLOT(lineNumberAreaClicked(QPoint)));
    connect(this, SIGNAL(cursorPositionChanged()), m_lineNumberArea, SLOT(repaint()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(matchSymbols()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(stopCompletion()));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateLineNumberArea()));
    connect(document(), SIGNAL(undoCommandAdded()), this, SLOT(undoCommandAdded()));

    // Setup completer
    m_completerList = new QStringListModel(this);
    m_completer = new QCompleter(this);
    m_completer->setModel(m_completerList);
    m_completer->setWidget(this);
    m_completer->setCompletionMode(QCompleter::PopupCompletion);
    m_completer->setCaseSensitivity(Qt::CaseSensitive);
    m_completer->popup()->setItemDelegate(new CompleterDelegate());
    connect(m_completer, SIGNAL(activated(QString)), this, SLOT(insertCompletion(QString)));
    disconnect(m_completer->popup(), SIGNAL(clicked(QModelIndex)), 0, 0);
    connect(m_completer->popup(), SIGNAL(doubleClicked(QModelIndex)), this, SLOT(insertCompletion(QModelIndex)));

    m_checkCompletion = new QTimer(this); m_checkCompletion->setSingleShot(true);
    connect(m_checkCompletion, SIGNAL(timeout()), this, SLOT(checkForCompletion()));

    // Setup text edit
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setLineWrapMode(QTextEdit::NoWrap);
    setTabStopWidth(40);

    // Activate mouse tracking
    setMouseTracking(true);
}

// Cursor
QString ScriptTextEdit::textUnderCursor() const
{
    QTextCursor cursor = textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    return cursor.selectedText();
}

int ScriptTextEdit::tabCountAt(int pos)
{
    QTextCursor cursor(textCursor());
    cursor.setPosition(pos);
    QString str = cursor.block().text();

    int tabCount = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '\t')
            tabCount++;
        else
            break;
    }

    return tabCount;
}

int ScriptTextEdit::findString(const QRegExp str, int pos, QTextDocument::FindFlags flags)
{
    return document()->find(str, pos, flags).position();
}

// Completion
void ScriptTextEdit::showCompletion()
{
    // Update font
    QFont newFont(font());
    newFont.setFixedPitch(true);
    newFont.setFamily(font().family());
    newFont.setWeight(font().weight());
    newFont.setPointSize(font().pointSize());
    m_completer->popup()->setFont(newFont);

    // Popup rect
    QRect cr = cursorRect();
    cr.setX(cr.x()+20);
    cr.setWidth(m_completer->popup()->sizeHintForColumn(0)
                + m_completer->popup()->verticalScrollBar()->sizeHint().width());

    // Popup it up!
    m_completer->complete(cr);
}

void ScriptTextEdit::resizeEvent(QResizeEvent *event)
{
    m_lineNumberArea->resize(m_lineNumberArea->sizeHint().width(),
                             event->size().height());
    QTextEdit::resizeEvent(event);
}

void ScriptTextEdit::keyPressEvent(QKeyEvent *event)
{
    // Undo/Redo tracking
    if(event->matches(QKeySequence::Undo) && document()->isUndoAvailable())
        emit undoPerformed();
    else if(event->matches(QKeySequence::Redo)  && document()->isRedoAvailable())
        emit redoPerformed();

    // Find startline and line dt
    QTextCursor startCursor(textCursor());
    startCursor.setPosition(textCursor().selectionStart());
    int startLine = startCursor.blockNumber();
    startCursor.setPosition(textCursor().selectionEnd());
    int selectLineDelta = startLine-startCursor.blockNumber();

    // Current line count
    int lineCount = document()->lineCount();

    // Enter pressed
    if(event->key() == Qt::Key_Return)
    {
        // Make sure the completer isn't visible
        if(!m_completer->popup()->isVisible())
        {
            // Add the correct amount of tabs to the next line
            int pos = textCursor().position(); // Position before new line

            // Find a { or a }
            int openBracketPos = findString(QRegExp("\\{"), pos, QTextDocument::FindBackward);
            int endBracketPos = findString(QRegExp("\\}"), pos, QTextDocument::FindBackward);
            if(openBracketPos >= 0)
            {
                // Get initial tab count
                int tabCount = 0;
                if(openBracketPos > endBracketPos)
                    tabCount = tabCountAt(openBracketPos)+1;
                else
                    tabCount = tabCountAt(endBracketPos);

                // Count open-bracket statements
                int seekPos = findString(QRegExp("[;{}]"), pos, QTextDocument::FindBackward);
                while(seekPos >= 0)
                {
                    seekPos = findString(QRegExp("\\s*((if|switch|while|for)\\s*\\(.*\\)|(else|do))"), seekPos, 0);
                    if(seekPos > pos || seekPos < 0)
                        break;
                    tabCount++;
                }

                // Add the tabs in a string
                QString tabString;
                for(int i = 0; i < tabCount; i++)
                    tabString += "\t";

                // Insert new line and tabs
                QTextEdit::keyPressEvent(event);
                insertPlainText(tabString);
            }else{
                // Insert the new line
                QTextEdit::keyPressEvent(event);
            }
        }
    }else if(event->key() == Qt::Key_Backspace){

        // Check for smart remove
        if((document()->characterAt(textCursor().position()-1) == '(' &&
                document()->characterAt(textCursor().position()) == ')') ||
                (document()->characterAt(textCursor().position()-1) == '\"' &&
                 document()->characterAt(textCursor().position()) == '\"') ||
                (document()->characterAt(textCursor().position()-1) == '[' &&
                 document()->characterAt(textCursor().position()) == ']'))
        {
            // Move cursor
            QTextCursor cursor(textCursor());
            cursor.movePosition(QTextCursor::NextCharacter);
            cursor.deletePreviousChar();
        }

        // Perform backspace
        QTextEdit::keyPressEvent(event);
    }
    else if(event->text() == "{")
    {
        // Check if we have an if on a earlier line
        int pos = textCursor().position();
        int statementPos = findString(QRegExp("\\s*((if|switch|while|for)\\s*\\(.*\\)|(else|do))"), pos, QTextDocument::FindBackward);
        if(statementPos > findString(QRegExp(";{"), pos, QTextDocument::FindBackward))
        {
            QTextCursor statementCursor(textCursor());
            statementCursor.setPosition(statementPos);
            if(statementCursor.blockNumber() != textCursor().blockNumber())
            {
                // Get tab count
                int tabCount = tabCountAt(pos)-1;
                QString tabString;
                for(int i = 0; i < tabCount; i++)
                    tabString += "\t";

                // Move cursor
                QTextCursor cursor(textCursor());
                cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::KeepAnchor);
                cursor.removeSelectedText();

                // Insert tabs
                insertPlainText(tabString);
            }
        }

        // Insert left brace
        QTextEdit::keyPressEvent(event);

    }else if(event->text() == "}"){

        // Check if there is a tab
        if(document()->characterAt(textCursor().position()-1) == '\t')
        {
            // Remove tab
            textCursor().deletePreviousChar();
        }

        // Insert right brace
        QTextEdit::keyPressEvent(event);

    }/*else if(event->key() == Qt::Key_ParenLeft)
    {
        QTextEdit::keyPressEvent(event);
        if(document()->characterAt(textCursor().position()).isSpace())
        {
            // Auto add right parentesis
            insertPlainText(")");

            // Move cursor
            QTextCursor cursor(textCursor());
            cursor.movePosition(QTextCursor::PreviousCharacter);
            setTextCursor(cursor);
        }
    }else if(event->key() == Qt::Key_ParenRight)
    {
        // Skip if right parentesis to the right
        if(document()->characterAt(textCursor().position()) == ')')
        {
            // Move cursor
            QTextCursor cursor(textCursor());
            cursor.movePosition(QTextCursor::NextCharacter);
            setTextCursor(cursor);
        }else
            QTextEdit::keyPressEvent(event);
    }else if(event->key() == Qt::Key_QuoteDbl)
    {
        if(document()->characterAt(textCursor().position()) != '\"')
        {
            // Auto add quote
            QTextEdit::keyPressEvent(event);
            insertPlainText("\"");

            // Move cursor
            QTextCursor cursor(textCursor());
            cursor.movePosition(QTextCursor::PreviousCharacter);
            setTextCursor(cursor);
        }else{
            // Skip quote
            QTextCursor cursor(textCursor());
            cursor.movePosition(QTextCursor::NextCharacter);
            setTextCursor(cursor);
        }
    }*/else if(event->key() == Qt::Key_Tab || event->key() == Qt::Key_Backtab){

        // Tab
        if(textCursor().selectedText().size() > 0)
        {
            // Check for multi-line tab
            QTextCursor start(document());
            start.setPosition(textCursor().selectionStart());
            int lstart = start.blockNumber();

            QTextCursor end(document());
            end.setPosition(textCursor().selectionEnd());
            int lend = end.blockNumber();
            int lined = lend - lstart;
            if(lined > 0)
            {
                // Multi-line tab
                QTextBlock line = start.block();
                QTextCursor tabc(document());
                if(event->key() == Qt::Key_Tab)
                {
                    // Tab
                    for(int i = 0; i <= lined; i++)
                    {
                        // Add tab
                        tabc.setPosition(line.position());
                        tabc.insertText("\t");
                        line = line.next();
                    }
                }else{
                    // Backtab
                    for(int i = 0; i <= lined; i++)
                    {
                        // Sanity check
                        if(line.length() < 1)
                            continue;

                        // Select text
                        tabc.setPosition(line.position());
                        tabc.setPosition(line.position()+1, QTextCursor::KeepAnchor);

                        // Remove tab
                        if(tabc.selectedText()[0] == '\t')
                            tabc.removeSelectedText();
                        line = line.next();
                    }
                }

            }else{
                // Add tab
                QTextEdit::keyPressEvent(event);
            }

        }else{
            // Add tab
            QTextEdit::keyPressEvent(event);
        }
    }else{
        // Append event
        QTextEdit::keyPressEvent(event);
    }

    // Get line delta
    int lineDelta = document()->lineCount()-lineCount;
    if(lineDelta != 0)
    {
        if(selectLineDelta != 0)
            m_scriptEditor->resizeBreakpoints(startLine, selectLineDelta);
        m_scriptEditor->resizeBreakpoints(startLine, lineDelta-selectLineDelta);
    }
    repaint();

    // Tell the intel it can update "safely"
    if(event->text() == "}" || event->text() == ")" || event->text() == ";")
        m_scriptEditor->updateIntel();

    // Perform autocomplete
    if(event->key() == Qt::Key_Period) {
        checkForCompletion();
    }
    else if(event->text() == "#")
    {
        // Preform a check
        if(!document()->characterAt(textCursor().position()-1).isLetterOrNumber())
        {
            // Show completer
            QStringList list; list << "#include";
            m_completerList->setStringList(list);
            showCompletion();
            m_completerPrefix = "#";
        }
    }
    else if(m_completer->popup()->isVisible())
    {
        bool hide = false;
        switch(event->key())
        {
            case Qt::Key_Left:
            case Qt::Key_Backspace:
            {
                // Move backwards in the completer
                if(m_completerPrefix.size() == 0)
                    hide = true;
                else
                    m_completerPrefix = m_completerPrefix.left(m_completerPrefix.size()-1);
            }
            break;

            case Qt::Key_Right:
            {
                // Read next char
                QTextCursor cursor = textCursor();
                cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor);
                QString prevChar = cursor.selectedText();
                if(prevChar.size() > 0)
                    m_completerPrefix += prevChar[0];
            }
            break;

            case Qt::Key_Return:
            {
                // "DoubleClick" current index
                QString completeString = m_completer->popup()->currentIndex().data().toString();
                insertCompletion(completeString);
                hide = true;
            }
            break;

            default:
            {
                // Add text to prefix
                m_completerPrefix += event->text();
            }
            break;
        }

        // Set prefix
        m_completer->setCompletionPrefix(m_completerPrefix);
        if(m_completer->completionCount() == 0)
            hide = true;

        // Check if there is no alternatives
        if(hide)
        {
            // Hide popup
            m_completerPrefix.clear();
            m_completer->popup()->hide();
            m_completer->setCompletionPrefix("");
        }
    }else if(event->text().size() > 0 && event->text()[0].isLetterOrNumber()){
        m_checkCompletion->start(500);
    }
}

void ScriptTextEdit::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier)
    {
        // Resize font
        QFont newFont(font());
        newFont.setFixedPitch(true);
        newFont.setFamily(font().family());
        newFont.setWeight(font().weight());
        if(event->delta() > 0)
            newFont.setPointSize(font().pointSize()-1);
        else
            newFont.setPointSize(font().pointSize()+1);
        setFont(newFont);
        m_lineNumberArea->resize(m_lineNumberArea->sizeHint().width(), height());
        updateLineNumberArea();
    }
    QTextEdit::wheelEvent(event);
}

void ScriptTextEdit::mouseMoveEvent(QMouseEvent *event)
{
    /*if(g_debugger && g_debugger->activeLine() >= 0)
    {
        // Get word under cursor
        QTextCursor cursor = cursorForPosition(event->pos());
        cursor.select(QTextCursor::WordUnderCursor);
        QString word = cursor.selection().toPlainText();

        // Emit signal
        emit showDebugVariable(word, event->globalPos());
    }*/

    // Pass the event
    QTextEdit::mouseMoveEvent(event);
}

void ScriptTextEdit::mousePressEvent(QMouseEvent *event)
{
    // Check if completer is active
    if(!m_completer->popup()->isVisible())
    {
        // TODO: What if i press the completer?
        // Clear prefix
        m_completerPrefix.clear();
        m_completer->setCompletionPrefix("");
    }

    // Perform event
    QTextEdit::mousePressEvent(event);
}

void ScriptTextEdit::scrollContentsBy(int dx, int dy)
{
    // Scroll line number area
    m_lineNumberArea->scroll(0, dy);
    QAbstractScrollArea::scrollContentsBy(dx, dy);
}

void ScriptTextEdit::insertCompletion(QModelIndex index)
{
    insertCompletion(index.data().toString());
    m_completer->popup()->hide();
}

void ScriptTextEdit::insertCompletion(QString string)
{
    // Insert completion
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::Left);
    cursor.movePosition(QTextCursor::EndOfWord);
    cursor.insertText(string.right(string.length()-m_completerPrefix.length()));
    setTextCursor(cursor);
}

void ScriptTextEdit::stopCompletion()
{
    m_checkCompletion->stop();
}

void ScriptTextEdit::checkForCompletion()
{
    // Call update
    m_scriptEditor->updateIntel();

    // Check if we have a object
    int pos = textCursor().position();
    QChar c = document()->characterAt(pos-1);
    QStringList list;
    if(c == '.')
    {
        // Get variable name
        QString objectName;
        int idx = pos-2;
        while(idx >= 0)
        {
            // Read backwards
            c = document()->characterAt(idx);
            if(c.isLetterOrNumber()) objectName.push_front(c);
            else break;
            idx--;
        }

        // Get curr scope
        ScriptIntel::Scope *scope = m_scriptEditor->scriptIntel()->scopeAt(idx);

        // Find variable with object name
        ScriptIntel::Scope *varType = 0;
        foreach(ScriptIntel::Variable *var, scope->variables)
        {
            // Check if object name and var name match
            if(var->name == objectName)
            {
                // Variable found, find the named scope of the type
                varType = m_scriptEditor->scriptIntel()->findNamedScope(m_scriptEditor->scriptIntel()->globalScope(), var->type);
                break;
            }
        }

        if(varType)
        {
            // List member variables
            foreach(ScriptIntel::Variable *var, varType->variables)
                list << var->name;

            // List object methods
            foreach(ScriptIntel::Scope *func, varType->scopes)
            {
                if(func->type == ScriptIntel::FunctionScope)
                    list << func->name;
            }
        }
    }else if(c.isLetterOrNumber()){
        // Check global scope
        QString objectName;
        int idx = pos-1;
        while(idx >= 0)
        {
            // Read backwards
            c = document()->characterAt(idx);
            if(c.isLetterOrNumber()) objectName.push_front(c);
            else break;
            idx--;
        }
        m_completerPrefix = objectName;

        // Fill list with definitions in scope
        ScriptIntel::Scope *currScope = m_scriptEditor->scriptIntel()->scopeAt(idx);
        while(currScope)
        {
            foreach(ScriptIntel::Variable *var, currScope->variables)
            {
                list << var->name;
            }

            foreach(ScriptIntel::Scope *scope, currScope->scopes)
            {
                if(scope->type == ScriptIntel::FunctionScope || scope->type == ScriptIntel::ClassScope)
                    list << scope->name;
            }

            currScope = currScope->parent;
        }
    }

    // Show completer
    m_completerList->setStringList(list);
    showCompletion();

    // Set prefix
    m_completer->setCompletionPrefix(m_completerPrefix);
    if(m_completer->completionCount() == 0)
    {
        // Hide popup
        m_completerPrefix.clear();
        m_completer->popup()->hide();
        m_completer->setCompletionPrefix("");
    }
}

// LineNumberArea
void ScriptTextEdit::lineNumberAreaClicked(QPoint pos)
{
    // Get line
    int offset = verticalScrollBar()->value();
    int line = floor((float)(pos.y()+offset)/fontMetrics().lineSpacing());

    // Toogle breakpoint
    emit toggleBreakpoint(line);

    // Repaint line number area
    m_lineNumberArea->repaint();
}

void ScriptTextEdit::undoCommandAdded()
{
    emit insertPerformed();
}

void ScriptTextEdit::setMatchFormat(int pos)
{
    QList<QTextEdit::ExtraSelection> selections = extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    //format.setBackground(Qt::lightGray);
    format.setForeground(Qt::red);
    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    selection.cursor = cursor;

    selections.append(selection);

    setExtraSelections(selections);
}

void ScriptTextEdit::matchSymbols()
{
    // Clear format
    QList<QTextEdit::ExtraSelection> selections;
    setExtraSelections(selections);

    // Show matching parenthesises and braces
    int idx = textCursor().position();
    if(idx > 0 && document()->characterAt(idx-1) == ')')
    {
        // Find matching
        int parenthesisCount = 1;
        setMatchFormat(idx-1);
        idx -= 2; // Skip this char
        while(idx >= 0)
        {
            if(document()->characterAt(idx) == '(')
            {
                parenthesisCount--;
                if(parenthesisCount == 0)
                    break;
            }else if(document()->characterAt(idx-1) == ')')
                parenthesisCount++;
            idx--;
        }
        setMatchFormat(idx);
    }else if(document()->characterAt(idx) == '(')
    {
        // Find matching
        int parenthesisCount = 1;
        setMatchFormat(idx);
        idx++; // Skip this char
        while(idx < document()->characterCount())
        {
            if(document()->characterAt(idx-1) == ')')
            {
                parenthesisCount--;
                if(parenthesisCount == 0)
                    break;
            }else if(document()->characterAt(idx) == '(')
                parenthesisCount++;
            idx++;
        }
        setMatchFormat(idx-1);
    }else if(document()->characterAt(idx) == '{')
    {
        // Find matching
        int braceCount = 1;
        setMatchFormat(idx);
        idx++; // Skip this char
        while(idx < document()->characterCount())
        {
            if(document()->characterAt(idx-1) == '}')
            {
                braceCount--;
                if(braceCount == 0)
                    break;
            }else if(document()->characterAt(idx) == '{')
                braceCount++;
            idx++;
        }
        setMatchFormat(idx-1);
    }else if(idx > 0 && document()->characterAt(idx-1) == '}')
    {
        // Find matching
        int braceCount = 1;
        setMatchFormat(idx-1);
        idx -= 2; // Skip this char
        while(idx >= 0)
        {
            if(document()->characterAt(idx) == '{')
            {
                braceCount--;
                if(braceCount == 0)
                    break;
            }else if(document()->characterAt(idx-1) == '}')
                braceCount++;
            idx--;
        }
        setMatchFormat(idx);
    }
}

void ScriptTextEdit::updateLineNumberArea()
{
    setViewportMargins(m_lineNumberArea->sizeHint().width(), 0, 0, 0);
    m_lineNumberArea->repaint();
}

//-----------------------------------------
// LineNumberArea
// Displays the line numbers
//-----------------------------------------

LineNumberArea::LineNumberArea(ScriptTextEdit *textEdit) :
    QWidget(textEdit),
    m_textEditor(textEdit)
{
}

QSize LineNumberArea::sizeHint() const
{
    return QSize(m_textEditor->fontMetrics().width(QLatin1Char('9')) *
                 QString::number(m_textEditor->document()->lineCount()).count() +
                 20, 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Draw margin
    painter.fillRect(event->rect(), QColor(240, 240, 240));

    // Get scroll value
    int offset = m_textEditor->verticalScrollBar()->value();
    int lineBegin = offset/m_textEditor->fontMetrics().lineSpacing();
    int lineEnd = floor((float)(offset+height())/m_textEditor->fontMetrics().lineSpacing());

    // Create font
    QFont paintFont;
    paintFont.setFamily(m_textEditor->font().family());
    paintFont.setPointSize(m_textEditor->font().pointSize());
    paintFont.setWeight(QFont::Light);

    // Set text color and font
    painter.setFont(paintFont);
    painter.setPen(QColor(160, 160, 160));

    // Draw line numbers
    QTextCursor cursor(m_textEditor->textCursor());
    cursor.setPosition(m_textEditor->textCursor().selectionStart());
    int currentLineBegin = cursor.blockNumber();
    cursor.setPosition(m_textEditor->textCursor().selectionEnd());
    int currentLineEnd = cursor.blockNumber();
    for(int i = lineBegin; i <= lineEnd; i++)
    {
        // Make sure we dont render too many lines
        if(i+1 > m_textEditor->document()->lineCount())
            break;

        // Draw current line numbers later
        if(i >= currentLineBegin && i <= currentLineEnd)
            continue;

        // Draw line number
        painter.drawText(0, (m_textEditor->fontMetrics().lineSpacing()*i)-offset+4,
                         sizeHint().width(), m_textEditor->fontMetrics().height()*(i+1),
                         Qt::AlignRight, QString::number(i+1));
    }

    // Draw current line numbers
    paintFont.setWeight(QFont::Bold);
    painter.setFont(paintFont);
    painter.setPen(QColor(128, 128, 128));
    for(int i = currentLineBegin; i <= currentLineEnd; i++)
    {
        // Make sure we dont render too many lines
        if(i+1 > m_textEditor->document()->lineCount())
            break;

        // Draw line number
        painter.drawText(0, (m_textEditor->fontMetrics().lineSpacing()*i)-offset+4,
                         sizeHint().width(), m_textEditor->fontMetrics().height()*(i+1),
                         Qt::AlignRight, QString::number(i+1));
    }

    // Draw breakpoints
    painter.setBrush(Qt::red);
    for(int i = lineBegin; i <= lineEnd; i++)
    {
        // Make sure we dont render too many lines
        if(i+1 > m_textEditor->m_scriptEditor->breakpointCount())
            break;

        // Draw breakpoint, if any
        if(m_textEditor->m_scriptEditor->isBreakpoint(i))
            painter.drawEllipse(2, (m_textEditor->fontMetrics().lineSpacing()*i)-offset+4, 13, 13);
    }

    // Draw current pos arrow
    QString file;
    int line;
    debugger()->currentBreakLocation(file, line);
    if(m_textEditor->m_scriptEditor->filePath() == file)
    {
        painter.drawPixmap(2, (m_textEditor->fontMetrics().lineSpacing()*line)-offset+4, 13, 13, QPixmap(":/toolbar/icons/restart.png"));
    }
}

void LineNumberArea::resizeEvent(QResizeEvent *event)
{
    // Resize line number area
    QRect rect = m_textEditor->contentsRect();
    setGeometry(QRect(rect.left(), rect.top(), sizeHint().width(), rect.height()));
    QWidget::resizeEvent(event);
}

void LineNumberArea::mouseReleaseEvent(QMouseEvent *event)
{
    emit clicked(event->pos());
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
