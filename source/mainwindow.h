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

    // Center splash in the middle fo the screen
    void centerSplash();

private:

    // Properties
    Ui::MainWindow *ui;
    ProjectDialog *m_projectDialog;
    ProjectTree *m_projectTree;
    Debugger *m_debugger;
    QTabWidget *m_infoWidget;

    // Update
    int m_updateProgress;
    bool m_updateAborted;
    QTemporaryFile *m_updateFile;
    QNetworkReply *m_updateReply;

public slots:

    // Updates
    void checkForUpdate();
    void downloadUpdate(QUrl url);
    void downloadUpdateFinish();
    void downloadUpdateReadyRead();
    void downloadUpdateProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadUpdateError(QNetworkReply::NetworkError);
    void processUpdate(int version);

    // Projects
    void createProject();
    void openProject();
    void loadProject(QString projectFile);
    void projectLoaded();

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
