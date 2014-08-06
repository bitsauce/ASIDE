#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QtCore>
#include <QtWidgets>

//---------------------------------------------
// Workspace
// The workspace of the editor
//---------------------------------------------

class GameWidget;
class MainWindow;
class WorkspaceToolbar;
class EditorBase;
class ScriptSearch;
class ScriptReplace;
class ScriptGoTo;

class Workspace : public QWidget
{
    friend class MainWindow;
    friend class EditorBase;
    Q_OBJECT
public:
    explicit Workspace(MainWindow *parent = 0);

    // Events
    void resizeEvent(QResizeEvent *event);

    // Search dialogs
    ScriptSearch *scriptSearch();
    ScriptReplace *scriptReplace();
    ScriptGoTo *scriptGoTo();

    // Files
    EditorBase *openFile(QString filePath);
    EditorBase *getOpenEditor(const QString filePath);
    EditorBase *getCurrentEditor();

    // Mdi area
    void setCurrentEditor(EditorBase *editor);

    // Actions
    QAction *cutAction();
    QAction *copyAction();
    QAction *pasteAction();
    QAction *newAction();
    QAction *deleteAction();
    QAction *renameAction();

private:

    // Create a mdi window
    void setCurrentMdiWindow(QMdiSubWindow *subWindow);
    QMdiSubWindow *createMdiWindow(QWidget *content);

public slots:

    // Mdi area
    int promptSaveChanges();
    int promptCloseAll();

    // File saving
    void saveAll();
    void saveCurrent();
    //void closeCurrent();
    void openFile();

    // File changed
    void fileSaved(const QString &filePath);
    void fileChanged(const QString &filePath);
    void fileClosed(const QString &filePath);

    // Anoying helper
    void removeFromRecentlySaved();

protected:
    // Widgets
    QMdiArea *m_mdiWidget;
    WorkspaceToolbar *m_toolbar;
    QStatusBar *m_statusbar;

    MainWindow *m_window;

    // Search dialogs
    ScriptSearch *m_scriptSearch;
    ScriptReplace *m_scriptReplace;
    ScriptGoTo *m_scriptGoTo;

    // File watcher
    QFileSystemWatcher *m_fileWatcher;
    QTimer *m_resetSavedFilesTimer;
    QStringList m_alreadyCalledFiles;
    QStringList m_recentlySavedFiles;

    // Open editors
    QList<EditorBase*> m_openEditors;
};

extern Workspace *workspace();

//---------------------------------------------
// WorkspaceToolbar
// The toolbar of the workspace
//---------------------------------------------

const int toolbarSize = 60;

class WorkspaceToolbar : public QToolBar
{
    Q_OBJECT
public:
    explicit WorkspaceToolbar(QWidget *parent = 0) :
        QToolBar(parent)
    {
        // Setup toolbar
        setFloatable(false);
        setMovable(false);
        setOrientation(Qt::Horizontal);
        setMaximumHeight(toolbarSize+1);
        layout()->setContentsMargins(0, 0, 0, 0);
        layout()->setSpacing(0);
    }

    QAction *addTool(QString group, QWidget *widget)
    {
        m_toggleButtons.push_back(widget);
        widget->setMinimumSize(toolbarSize, 52);
        return addWidget(widget);
    }

private:
    QVector<QWidget*> m_toggleButtons;
};

#endif // WORKSPACE_H
