//     _                                     ____  ____
//    / \  _   _ _ __ ___  _ __ __ _  __  __|___ \|  _ \
//   / _ \| | | |  __/ _ \|  __/ _  | \ \/ /  __) | | | |
//  / ___ \ |_| | | | (_) | | | (_| |  >  <  / __/| |_| |
// /_/   \_\__ _|_|  \___/|_|  \__ _| /_/\_\|_____|____/
//		MacroByte (C)

#include "workspace.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scripteditor.h"

// Global workspace

Workspace *g_workspace = 0;
Workspace *workspace()
{
    return g_workspace;
}

//---------------------------------------
// Workspace
// The workspace area
//---------------------------------------
Workspace::Workspace(MainWindow *parent) :
    QWidget(parent),
    m_window(parent)
{
    // Global workspace
    Q_ASSERT(!g_workspace);
    g_workspace = this;

    // Create the script search and replace
    m_scriptSearch = new ScriptSearch(this);
    m_scriptReplace = new ScriptReplace(this);
    m_scriptGoTo = new ScriptGoTo(this);

    // Create toolbar
    m_toolbar = new WorkspaceToolbar(this);
    m_toolbar->setEnabled(false);
    m_toolbar->setObjectName("Toolbar");

    // Create mdi widget
    m_mdiWidget = new QMdiArea(this);
    m_mdiWidget->setActivationOrder(QMdiArea::ActivationHistoryOrder);
    m_mdiWidget->setBackground(QColor(205, 205, 205, 255));

    // Create file system notifier
    m_fileWatcher = new QFileSystemWatcher(this);
    connect(m_fileWatcher, SIGNAL(fileChanged(const QString&)), this, SLOT(fileChanged(const QString&)));

    // Create anoying timer
    m_resetSavedFilesTimer = new QTimer(this);
    m_resetSavedFilesTimer->setSingleShot(true);
    connect(m_resetSavedFilesTimer, SIGNAL(timeout()), this, SLOT(removeFromRecentlySaved()));

    // Set minimum size
    setMinimumSize(240, 120);
}

//---------------------------------------
// Events
//---------------------------------------
void Workspace::resizeEvent(QResizeEvent *event)
{
    // Set widget sizes
    m_mdiWidget->resize(event->size());

    // Resize toolbar
    m_toolbar->resize(event->size());

    // Send event
    QWidget::resizeEvent(event);
}

ScriptSearch *Workspace::scriptSearch()
{
    return m_scriptSearch;
}

ScriptReplace *Workspace::scriptReplace()
{
    return m_scriptReplace;
}

ScriptGoTo *Workspace::scriptGoTo()
{
    return m_scriptGoTo;
}

#include "settings.h"
ScriptEditor *Workspace::openFile(QString filePath)
{
    QFileInfo fileInfo(filePath);

    // Check if file is a script file
    bool isScriptFile = false;
    foreach(QString fileType, settings()->fileTypes())
    {
        if(fileType.split(";")[1] == fileInfo.suffix())
            isScriptFile = true;
    }

    if(isScriptFile)
    {
        // Check if file is already open
        ScriptEditor *editor = getOpenEditor(filePath);
        if(editor == 0)
        {
            // Not open, open the file
            m_fileWatcher->addPath(filePath);
            editor = ScriptEditor::openFile(filePath);
            connect(editor, SIGNAL(fileClosed(const QString&)), this, SLOT(fileClosed(const QString&)));
            connect(editor, SIGNAL(fileSaved(const QString&)), this, SLOT(fileSaved(const QString&)));

            // Add to open editors
            m_openEditors.push_back(editor);
        }else{
            // The file is already open, make it the current mdi window
            m_mdiWidget->setActiveSubWindow(editor->mdiWindow());
        }

        return editor;
    }else{
       // Check for an external program to open this file
    }
    return 0;
}

ScriptEditor *Workspace::getOpenEditor(const QString filePath)
{
    foreach(ScriptEditor *editor, m_openEditors)
    {
        if(editor->filePath() == filePath) {
            return editor;
        }
    }
    return 0;
}

ScriptEditor *Workspace::getCurrentEditor()
{
    foreach(ScriptEditor *editor, m_openEditors)
    {
        if(editor->mdiWindow() == m_mdiWidget->activeSubWindow()) {
            return editor;
        }
    }
    return 0;
}

QMdiSubWindow *Workspace::createMdiWindow(QWidget *content)
{
    QMdiSubWindow *mdiWindow = m_mdiWidget->addSubWindow(content);
    QAction *closeAll = mdiWindow->systemMenu()->addAction("Close All");
    connect(closeAll, SIGNAL(triggered()), this, SLOT(promptCloseAll()));
    mdiWindow->systemMenu()->removeAction(mdiWindow->systemMenu()->actions()[0]);
    QObject::connect(content, SIGNAL(destroyed()), mdiWindow, SLOT(close()));
    return mdiWindow;
}

QAction *Workspace::cutAction()
{
    return m_window->ui->actionCut;
}

QAction *Workspace::copyAction()
{
    return m_window->ui->actionCopy;
}

QAction *Workspace::pasteAction()
{
    return m_window->ui->actionPaste;
}

QAction *Workspace::newAction()
{
    return m_window->ui->actionNew;
}

QAction *Workspace::deleteAction()
{
    return m_window->ui->actionDelete;
}

QAction *Workspace::renameAction()
{
    return m_window->ui->actionRename;
}

void Workspace::removeFromRecentlySaved()
{
    m_alreadyCalledFiles.clear();
}

//---------------------------------------
// Slots
//---------------------------------------
int Workspace::promptSaveChanges()
{
    // Check for unsaved changes
    int r = 0;
    foreach(ScriptEditor *editor, m_openEditors)
    {
        if(!editor->isSaved()) {
            r = QMessageBox::question(this, "Save Changes?", "Unsaved changes have been made. Do you want to save all the changes?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            break;
        }
    }

    // Save unsaved changes?
    if(r == QMessageBox::Yes)
    {
        // Save
        foreach(ScriptEditor *editor, m_openEditors)
            editor->save();
    }
    return r;
}

int Workspace::promptCloseAll()
{
    // Save changes
    int r = promptSaveChanges();
    if(r != QMessageBox::Cancel)
    {
        // Close all mdi windows
        foreach(ScriptEditor *editor, m_openEditors) {
            editor->resetSaveState();
            editor->mdiWindow()->close();
        }
    }
    return r;
}

void Workspace::fileSaved(const QString &filePath)
{
    qDebug() << QString("File Saved: %1").arg(filePath);
    m_recentlySavedFiles << filePath;
}

void Workspace::fileChanged(const QString &filePath)
{
    qDebug() << QString("File Changed: %1").arg(filePath);

    // Skip duplicate calls
    if(m_alreadyCalledFiles.contains(filePath))
        return;
    m_alreadyCalledFiles << filePath;

    // File was modified by this application
    if(m_recentlySavedFiles.contains(filePath))
    {
        m_recentlySavedFiles.removeOne(filePath);
        m_resetSavedFilesTimer->start(100);
        return;
    }

    // File was modified externaly
    int r = QMessageBox::question(this, "Reload", "" + filePath + "\n\nThis file has been modified by an external program.\n"
                         "Do you wish to reload it?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    ScriptEditor *editor = getOpenEditor(filePath);
    if(r == QMessageBox::Yes)
    {
        // Reload file content
        editor->loadFile(filePath);
    }else{
        // Tell the editor the text was changed
        editor->textChanged();
    }
}

void Workspace::fileClosed(const QString &filePath)
{
    qDebug() << QString("File Closed: %1").arg(filePath);
    m_fileWatcher->removePath(filePath);
    m_openEditors.removeOne(getOpenEditor(filePath));
}
