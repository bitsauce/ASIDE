//     _    ____ ___ ____  _____
//    / \  / ___|_ _|  _ \| ____|
//   / _ \ \___ \| || | | |  _|
//  / ___ \ ___) | || |_| | |___
// /_/   \_\____/___|____/|_____|
// Originally written by Marcus Loo Vergara (aka. Bitsauce)
// 2011-2014 (C)

#include "workspace.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scripteditor.h"
#include "settings.h"
#include "project.h"
#include "configeditor.h"

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

EditorBase *Workspace::openFile(QString filePath)
{
    filePath = QDir::fromNativeSeparators(filePath);

    // Check if the file is already open
    EditorBase *editor = getOpenEditor(filePath);
    if(editor)
    {
        m_mdiWidget->setActiveSubWindow(editor->m_mdiWindow);
    }else{
        QFileInfo fileInfo(filePath);

        // Check for script files
        bool isScriptFile = false;
        foreach(QString fileType, settings()->fileTypes())
        {
            if(fileType.split(";")[1] == fileInfo.suffix())
                isScriptFile = true;
        }

        // Open file
        if(isScriptFile)
        {
            // Get title string
            QString title = filePath;
            if(Project::isLoaded()) {
                title.remove(Project::getDirectory());
            }else{
                title = title.right(title.size() - title.lastIndexOf('/') - 1);
            }

            // Open file in script editor
            editor = new ScriptEditor(filePath, title);
        }else if(fileInfo.suffix() == PROJECT_FILE_EXT)
        {
            // Display project configuration file
            editor = new ConfigEditor(filePath, "Project Config");
        }else
        {
            // Check for an external program to open this file
            QDesktopServices::openUrl(QUrl("file:///" + filePath));
        }

        // If an editor was created:
        if(editor)
        {
            // Add file to file watcher
            m_fileWatcher->addPath(filePath);
            connect(editor, SIGNAL(fileClosed(const QString&)), this, SLOT(fileClosed(const QString&)));
            connect(editor, SIGNAL(fileSaved(const QString&)), this, SLOT(fileSaved(const QString&)));

            // Add editor to open editors
            m_openEditors.push_back(editor);
        }
    }
    return editor;
}

EditorBase *Workspace::getOpenEditor(const QString filePath)
{
    foreach(EditorBase *editor, m_openEditors)
    {
        if(editor->m_filePath == filePath) {
            return editor;
        }
    }
    return 0;
}

EditorBase *Workspace::getCurrentEditor()
{
    foreach(EditorBase *editor, m_openEditors)
    {
        if(editor->m_mdiWindow == m_mdiWidget->activeSubWindow()) {
            return editor;
        }
    }
    return 0;
}

QMdiSubWindow *Workspace::createMdiWindow(QWidget *content)
{
    // Create mdi sub window
    QMdiSubWindow *mdiWindow = m_mdiWidget->addSubWindow(content);

    // Setup window
    QAction *closeAll = mdiWindow->systemMenu()->addAction("Close All");
    connect(closeAll, SIGNAL(triggered()), this, SLOT(promptCloseAll()));
    mdiWindow->systemMenu()->removeAction(mdiWindow->systemMenu()->actions()[0]);

    // Return window
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
    foreach(EditorBase *editor, m_openEditors)
    {
        if(editor->isModified())
        {
            r = QMessageBox::question(this, "Save Changes?", "Unsaved changes have been made. Do you want to save all the changes?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            break;
        }
    }

    // Save unsaved changes?
    if(r == QMessageBox::Yes)
    {
        saveAll();
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
        foreach(EditorBase *editor, m_openEditors)
        {
            editor->setModified(false);
            editor->m_mdiWindow->close();
        }
    }
    return r;
}

void Workspace::saveAll()
{
    // Save all open files
    foreach(EditorBase *editor, m_openEditors)
    {
        editor->save();
    }
}

void Workspace::saveCurrent()
{
    // Save current file
    EditorBase *editor = getCurrentEditor();
    if(editor) editor->save();
}

void Workspace::openFile()
{

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
    EditorBase *editor = getOpenEditor(filePath);
    if(r == QMessageBox::Yes)
    {
        // Reload file content
        editor->load();
    }
    else
    {
        // Tell the editor the text was changed
        editor->setModified(true);
    }
}

void Workspace::fileClosed(const QString &filePath)
{
    m_fileWatcher->removePath(filePath);
    m_openEditors.removeOne(getOpenEditor(filePath));
}
