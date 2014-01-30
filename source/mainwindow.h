#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>
#include <QtXml>

namespace Ui {
class MainWindow;
}
class ConsoleLog;
class ProjectDialog;
class ProjectTree;
class Debugger;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Workspace;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Events
    void moveEvent(QMoveEvent *e);
    void resizeEvent(QResizeEvent * e);
    void closeEvent(QCloseEvent *e);

private:

    // Game
    //static void showException(X2DApp *app, X2D::ErrorCode error, const char* message);
    //static void printOutput(X2DApp *app, const char* message);

private:
    // Properties
    Ui::MainWindow *ui;
    ProjectDialog *m_projectDialog;
    ProjectTree *m_projectTree;

    // Update
    int m_updateProgress;
    bool m_updateAborted;
    QTemporaryFile *m_updateFile;
    QNetworkReply *m_updateReply;

    Debugger *m_debugger;
    QTabWidget *m_infoWidget;

public slots:
    // Updates
    void checkForUpdate();
    void downloadUpdate(QUrl url);
    void downloadUpdateFinish();
    void downloadUpdateReadyRead();
    void downloadUpdateProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadUpdateError(QNetworkReply::NetworkError);
    void processUpdate(int version);

    // File
    void newProject();
    void openProject();
    void loadProject(QString projectFile);
    void projectLoaded();

    void newFile();
    void newFile(QString defaultPath);
    void saveFile();
    void openFile();
    void saveAllFiles();

    void closeProject();
    void publishProject();

    // Application
    void startApplication();
    void applicationClosed();

    // Debug
    void resumeExec();
    void interruptExec();
    void restartExec();
    void stopExec();

    void enableRuntimeComands();
    void disableRuntimeComands();
    void enableStepCommands();
    void disableStepCommands();
    void enableResume();
    void disableResume();

    // Settings
    void showSettings();

    // Workspace
    void workspaceModeSelected(QAction *selection);

    // Single instance application
    void applicationMessage(const QString &message);
};

#endif // MAINWINDOW_H
