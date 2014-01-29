//     _                                     ____  ____
//    / \  _   _ _ __ ___  _ __ __ _  __  __|___ \|  _ \
//   / _ \| | | |  __/ _ \|  __/ _  | \ \/ /  __) | | | |
//  / ___ \ |_| | | | (_) | | | (_| |  >  <  / __/| |_| |
// /_/   \_\__ _|_|  \___/|_|  \__ _| /_/\_\|_____|____/
//		MacroByte (C)

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "project.h"
#include "workspace.h"
#include "projecttree.h"
#include "scripteditor.h"
#include "debugger.h"
#include "settings.h"

#define EDITOR_VERSION 102006

//------------------------------------------------
// MainWindow
// The editor main window
//------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setup main window
    ui->setupUi(this);

    // Setup mdi widget
    new Workspace(this);
    addToolBar(Qt::TopToolBarArea, workspace()->m_toolbar);

    // Setup settings
    new Settings(this);

    // Group actions
    QActionGroup* workspaceModeGroup = new QActionGroup(this);
    workspaceModeGroup->addAction(ui->actionCascade);
    workspaceModeGroup->addAction(ui->actionTabbed);
    connect(workspaceModeGroup, SIGNAL(triggered(QAction*)), this, SLOT(workspaceModeSelected(QAction*)));

    // Create project dialog
    m_projectDialog = new ProjectDialog(this);
    m_projectDialog->show();
    connect(m_projectDialog, SIGNAL(newProject()), this, SLOT(newProject()));
    connect(m_projectDialog, SIGNAL(openProject()), this, SLOT(openProject()));
    connect(m_projectDialog, SIGNAL(loadProject(QString)), this, SLOT(loadProject(QString)));

    // Add game buttons to toolbar
    QToolButton *runButton = new QToolButton(this);
    runButton->setDefaultAction(ui->actionRun);
    workspace()->m_toolbar->addTool("ProjectGroup", runButton);

    QToolButton *restartButton = new QToolButton(this);
    restartButton->setDefaultAction(ui->actionRestart);
    workspace()->m_toolbar->addTool("ProjectGroup", restartButton);

    QToolButton *pauseButton = new QToolButton(this);
    pauseButton->setDefaultAction(ui->actionPause);
    workspace()->m_toolbar->addTool("ProjectGroup", pauseButton);

    QToolButton *stopButton = new QToolButton(this);
    stopButton->setDefaultAction(ui->actionStop);
    workspace()->m_toolbar->addTool("ProjectGroup", stopButton);

    QToolButton *stepOverButton = new QToolButton(this);
    stepOverButton->setDefaultAction(ui->actionStepOver);
    workspace()->m_toolbar->addTool("ProjectGroup", stepOverButton);
    connect(ui->actionStepOver, SIGNAL(triggered()), m_debugger, SLOT(stepOver()));

    QToolButton *stepIntoButton = new QToolButton(this);
    stepIntoButton->setDefaultAction(ui->actionStepInto);
    workspace()->m_toolbar->addTool("ProjectGroup", stepIntoButton);
    connect(ui->actionStepInto, SIGNAL(triggered()), m_debugger, SLOT(stepInto()));

    QToolButton *stepOutButton = new QToolButton(this);
    stepOutButton->setDefaultAction(ui->actionStepOut);
    workspace()->m_toolbar->addTool("ProjectGroup", stepOutButton);
    connect(ui->actionStepOut, SIGNAL(triggered()), m_debugger, SLOT(stepOut()));

    // Setup vertical splitter
    QSplitter *verticalSplitter = new QSplitter(centralWidget());
    centralWidget()->layout()->addWidget(verticalSplitter);
    centralWidget()->setMinimumSize(m_projectDialog->size());

    // Setup project tree
    m_projectTree = new ProjectTree(this);
    m_projectTree->hide();
    connect(m_projectTree, SIGNAL(newFile(QString)), this, SLOT(newFile(QString)));

    QWidget *workspaceArea = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(workspaceArea);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    // Add widgets to splitter (left hand style)
    verticalSplitter->addWidget(m_projectTree);
    verticalSplitter->addWidget(workspaceArea);
    verticalSplitter->setStretchFactor(0, 0);
    verticalSplitter->setStretchFactor(1, 1);
    QList<int> splitterSizes;
    splitterSizes << centralWidget()->width()*0.45f;
    splitterSizes << centralWidget()->width()*0.55f;
    verticalSplitter->setSizes(splitterSizes);

    // Setup horizontal splitter
    QSplitter *horizontalSplitter = new QSplitter(Qt::Vertical, centralWidget());
    workspaceArea->layout()->addWidget(horizontalSplitter);

    // Create info widget
    m_infoWidget = new QTabWidget(this);

    // Create debugger
    m_debugger = new Debugger(m_infoWidget, this);
    connect(m_debugger, SIGNAL(execInitialized()), this, SLOT(enableRuntimeComands()));
    connect(m_debugger, SIGNAL(execInterrupted(QString,int)), this, SLOT(enableResume()));
    connect(m_debugger, SIGNAL(execResumed()), this, SLOT(disableResume()));
    connect(m_debugger, SIGNAL(execEnded()), this, SLOT(disableRuntimeComands()));

    // Add widgets to splitter
    horizontalSplitter->addWidget(workspace());
    horizontalSplitter->addWidget(m_infoWidget);
    horizontalSplitter->setStretchFactor(0, 0);
    horizontalSplitter->setStretchFactor(1, 1);
    splitterSizes.clear();
    splitterSizes << 1000;
    splitterSizes << 15;
    horizontalSplitter->setSizes(splitterSizes);

    // Load workspace settings
    int viewMode = settings()->value("workspace/view_mode", QMdiArea::SubWindowView).toInt();
    if(viewMode == QMdiArea::SubWindowView)
    {
        workspaceModeSelected(ui->actionCascade);
        ui->actionCascade->setChecked(true);
    }else{
        workspaceModeSelected(ui->actionTabbed);
        ui->actionTabbed->setChecked(true);
    }

    // Load window state
    QPoint pos = settings()->value("state/position", QPoint(200, 200)).toPoint();
    QSize size = settings()->value("state/size", QSize(800, 600)).toSize();
    QByteArray state = settings()->value("state/state", QByteArray()).toByteArray();
    bool maximized = settings()->value("state/maximized", false).toBool();
    if(maximized)
    {
        showMaximized();
    }else{
        move(pos);
        resize(size);
    }
    restoreState(state);

    // Update updater
    if(QFile::exists(QCoreApplication::applicationDirPath() + "/Updater_New.exe"))
    {
        QFile::remove(QCoreApplication::applicationDirPath() + "/Updater.exe");
        QFile::copy(QCoreApplication::applicationDirPath() + "/Updater_New.exe",
                    QCoreApplication::applicationDirPath() + "/Updater.exe");
        QFile::remove(QCoreApplication::applicationDirPath() + "/Updater_New.exe");
    }

    // Run update check
    checkForUpdate();

    setWindowTitle(windowTitle() + " " + QString::number(EDITOR_VERSION));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------
// Events
//------------------------------------------------

void MainWindow::moveEvent(QMoveEvent *e)
{
    if(m_projectDialog)
    {
        // Make sure the project dialog is in the center
        QPoint center = mapToGlobal(centralWidget()->rect().center());
        QSize size = m_projectDialog->size();
        int offset = ui->menuBar->height();
        m_projectDialog->move(center.x()-size.width()/2,
                              offset+center.y()-size.height()/2);
    }

    QMainWindow::moveEvent(e);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    if(m_projectDialog)
    {
        // Make sure the project dialog is in the center
        QPoint center = mapToGlobal(centralWidget()->rect().center());
        QSize size = m_projectDialog->size();
        int offset = ui->menuBar->height();
        m_projectDialog->move(center.x()-size.width()/2,
                              offset+center.y()-size.height()/2);
    }

    QMainWindow::resizeEvent(e);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    // Prompt save
    if(workspace()->promptSaveChanges() == QMessageBox::Cancel)
    {
        e->ignore();
        return;
    }

    // Close current project
    Project::closeProject();

    // Save workspace settings
    if(ui->actionCascade->isChecked())
        settings()->setValue("workspace/view_mode", QMdiArea::SubWindowView);
    else
        settings()->setValue("workspace/view_mode", QMdiArea::TabbedView);

    // Save window state
    if(isMaximized())
    {
        settings()->setValue("state/maximized", isMaximized());
    }else{
        settings()->setValue("state/position", pos());
        settings()->setValue("state/size", size());
    }
    settings()->setValue("state/state", saveState());

    // Close game if running
    //if(m_workspace->m_gameWidget->isRunning())
    //    m_workspace->m_gameWidget->close();

    QMainWindow::closeEvent(e);
}

//----------------------------------------
// Updating
//----------------------------------------

QString nodeValue(QDomNode node)
{
    QDomNode child = node.childNodes().at(0);
    if(child.isText())
        return child.nodeValue();
    return "";
}

void MainWindow::checkForUpdate()
{
    // Download update info
    downloadUpdate(QUrl("http://mixedgraphics.net/editor/update.xml"));
    m_updateAborted = false;
}

void MainWindow::downloadUpdate(QUrl url)
{
    // Create temp file
    m_updateFile = new QTemporaryFile(this);
    if(!m_updateFile->open())
        return; // Unable to create temporary file

    // Download file
    QNetworkAccessManager *downloader = new QNetworkAccessManager(this);
    m_updateReply = downloader->get(QNetworkRequest(url));
    connect(m_updateReply, SIGNAL(finished()), this, SLOT(downloadUpdateFinish()));
    connect(m_updateReply, SIGNAL(readyRead()), this, SLOT(downloadUpdateReadyRead()));
    connect(m_updateReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadUpdateProgress(qint64, qint64)));
    connect(m_updateReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadUpdateError(QNetworkReply::NetworkError)));
}

void MainWindow::downloadUpdateFinish()
{
    // Check if update was aborted
    if(m_updateAborted)
        return; // Update aborted

    // Open update file
    m_updateFile->close();
    if(!m_updateFile->open())
        return; // Unable to download file

    // Setup xml file
    QDomDocument *updateXml = new QDomDocument;
    if(!updateXml->setContent(m_updateFile))
        return; // Unable to create xml file

    // Read version and return update version
    QDomNode versionNode = updateXml->firstChildElement("update").elementsByTagName("version").at(0);
    processUpdate(nodeValue(versionNode).toInt());

    delete updateXml;
}

void MainWindow::downloadUpdateReadyRead()
{
    m_updateFile->write(m_updateReply->readAll());
}

void MainWindow::downloadUpdateProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    // TODO: Show progress update
}

void MainWindow::downloadUpdateError(QNetworkReply::NetworkError)
{
    // Update failed, shedule new check
    QTimer::singleShot(1800000, this, SLOT(checkForUpdate())); // 30 min
}

void MainWindow::processUpdate(int version)
{
    // Check if version is newer
    if(version > EDITOR_VERSION)
    {
        if(QMessageBox::question(this, "Update available", "An newer update is available. "
                                 "Do you want to close the editor and update now?",
                                 QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
        {
            // Check for save
            if(workspace()->promptSaveChanges() == QMessageBox::Cancel)
            {
                // Schedule new check
                QTimer::singleShot(1800000, this, SLOT(checkForUpdate()));
                return;
            }

            // Launch updater
            QProcess *updater = new QProcess(this);
            QString program = QCoreApplication::applicationDirPath() + "/Updater.exe";

            // Set version argument
            QStringList args;
            args.push_back("-version=" + QString::number(EDITOR_VERSION));

            // Start process
            updater->startDetached(program, args);

            // Close this application
            close();
        }
    }else{
        // Up to date, schedule new check
        QTimer::singleShot(1800000, this, SLOT(checkForUpdate())); // 30 min
    }
}

//----------------------------------------
// Project
//----------------------------------------

void MainWindow::newProject()
{
    // Show new project dialog
    NewProjectDialog *newDialog = new NewProjectDialog(this);
    while(true) // Keep open
    {
        if(newDialog->exec() == 1)
        {
            // Create project
            int r = Project::createProject(newDialog->projectName(), newDialog->projectPath());
            if(r == PROJECT_ALREADY_EXSISTS)
            {
                // Project already exsists
                QMessageBox::warning(this, "An error occured", "A project with the selected name already "
                                     "exsists in the project directory. Please select a different name or directory.",
                                     QMessageBox::Ok, QMessageBox::NoButton);
                continue;
            }else if(r < 0)
            {
                // Failed to read or write file
                QMessageBox::warning(this, "An error occured", "The project files could not be created. "
                                     "Make sure you have read and write permissions to the directory.",
                                     QMessageBox::Ok, QMessageBox::NoButton);
            }else{
                // Load project
                loadProject(newDialog->projectPath() + "/" + newDialog->projectName() + ".x2d");
            }
        }
        break;
    }
    delete newDialog;
}

void MainWindow::openProject()
{
    // Open file
    QString projectFile = QFileDialog::getOpenFileName(this, "Open Project", QDir::homePath(),
                                                       tr("Project Files (*.x2d)"));

    // Load project
    if(!projectFile.isEmpty())
        loadProject(projectFile);
}

void MainWindow::loadProject(QString projectFile)
{
    // Close project, in case a project is already loaded
    Project::closeProject();

    // Load the project
    int r = Project::loadProject(projectFile);
    if(r < 0)
    {
        // Failed
        QMessageBox::warning(this, "An error occured", "The project file could not be read. "
                             "Please make sure you have read and write permissions to the directory, "
                             "and that the file exsists.", QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }

    // Load session
    /*QSettings session(Project::getProjectDir() + "/" + Project::getProjectName() + ".session", QSettings::IniFormat);

    int i = 0;
    while(true)
    {
        // Get next file in the session
        QString filePath = session.value("file_" + QString::number(i) + "/filePath").toString();
        if(filePath.isEmpty())
            break; // No more files in the session

        // Open the script file
        ScriptEditor *editor = ScriptEditor::openFile(filePath);
        if(!editor) {
            // The file couldn't open, continue
            i++; continue;
        }

        // Restore cursor position
        int pos = session.value("file_" + QString::number(i) + "/pos").toInt();
        QTextCursor c = editor->scriptTextEdit()->textCursor();
        c.setPosition(pos);
        editor->scriptTextEdit()->setTextCursor(c);

        // Restore scroll values
        int vscroll = session.value("file_" + QString::number(i) + "/vscroll").toInt();
        editor->scriptTextEdit()->verticalScrollBar()->setValue(vscroll);

        int hscroll = session.value("file_" + QString::number(i) + "/hscroll").toInt();
        editor->scriptTextEdit()->horizontalScrollBar()->setValue(hscroll);

        // Next file
        i++;
    }*/

    ScriptEditor::loadProject("","");

    // Project loaded
    projectLoaded();
}

void MainWindow::projectLoaded()
{
    // Set window title
    setWindowTitle("AngelScript IDE - " + Project::getProjectName());

    // Enable workspace
    workspace()->setEnabled(true);
    workspace()->m_toolbar->setEnabled(true);

    // Enable file buttons
    ui->actionNew_File->setEnabled(true);
    ui->actionOpen_File->setEnabled(true);
    ui->actionSave_File->setEnabled(true);

    // Enable game buttons
    ui->actionRun->setEnabled(true);

    // Enable project buttons
    ui->actionSave_All->setEnabled(true);
    ui->actionClose_Project->setEnabled(true);

    // Setup project tree
    m_projectTree->setRootPath(Project::getProjectDir());
    m_projectTree->show();

    // Delete project dialog, if any
    if(m_projectDialog)
    {
        m_projectDialog->hide();
        m_projectDialog->deleteLater();
        m_projectDialog = 0;
    }
}

void MainWindow::newFile()
{
    m_projectTree->newFileItem();
}

void MainWindow::newFile(QString defaultPath)
{
    // Get the file type filter for the editor
    QString filter;
    foreach(QString fileType, settings()->fileTypes())
    {
        QStringList list = fileType.split(";");
        filter += QString("%1 (*.%2);;").arg(list[0]).arg(list[1]);
    }

    // Get new file name
    QString newFile = QFileDialog::getSaveFileName(this, "New File", defaultPath, filter);
    if(!newFile.isEmpty()) {
        // Create the script file
        ScriptEditor::createFile(newFile);
    }
}

void MainWindow::saveFile()
{
    // Get current script file and save it
    ScriptEditor *editor = workspace()->getCurrentEditor();
    if(editor)
        editor->save();
}

void MainWindow::openFile()
{
}

void MainWindow::saveAllFiles()
{
    // Save unsaved changes
//    foreach(ScriptEditor *editor, ScriptEditor::getOpenEditors())
//    {
//        if(!editor->isSaved())
//            editor->save();
//    }
}

void MainWindow::publishProject()
{
}

void MainWindow::closeProject()
{
    // Close all mdi windows
    if(workspace()->promptCloseAll() == QMessageBox::Cancel)
        return;

    // Stop game
    stopExec();

    // Save session
    QSettings session(Project::getProjectDir() + "/" + Project::getProjectName() + ".session", QSettings::IniFormat);
    session.clear();

//    int i = 0;
//    foreach(ScriptEditor *editor, ScriptEditor::getOpenEditors())
//    {
//        int hscroll = editor->scriptTextEdit()->horizontalScrollBar()->value();
//        int vscroll = editor->scriptTextEdit()->verticalScrollBar()->value();
//        int pos = editor->scriptTextEdit()->textCursor().position();

//        session.setValue("file_" + QString::number(i) + "/filePath", editor->filePath());
//        session.setValue("file_" + QString::number(i) + "/pos", pos);
//        session.setValue("file_" + QString::number(i) + "/hscroll", hscroll);
//        session.setValue("file_" + QString::number(i) + "/vscroll", vscroll);

//        i++;
//    }

    // Close project
    Project::closeProject();

    // Disable workspace
    workspace()->setEnabled(false);
    workspace()->m_toolbar->setEnabled(false);
    m_projectTree->hide();

    // Disable file buttons
    ui->actionNew_File->setEnabled(false);
    ui->actionOpen_File->setEnabled(false);
    ui->actionSave_File->setEnabled(false);
    ui->actionPublish->setEnabled(false);

    // Disable game buttons
    ui->actionRun->setEnabled(false);
    ui->actionRestart->setEnabled(false);
    ui->actionStop->setEnabled(false);
    ui->actionPause->setEnabled(false);
    ui->actionOptions->setEnabled(false);

    // Disable project buttons
    ui->actionSave_All->setEnabled(false);
    ui->actionClose_Project->setEnabled(false);

    // Create project dialog
    m_projectDialog = new ProjectDialog(this);
    m_projectDialog->show();
    connect(m_projectDialog, SIGNAL(newProject()), this, SLOT(newProject()));
    connect(m_projectDialog, SIGNAL(openProject()), this, SLOT(openProject()));
    connect(m_projectDialog, SIGNAL(loadProject(QString)), this, SLOT(loadProject(QString)));
}

void MainWindow::startApplication()
{
    // Check for unsaved changes
    if(workspace()->promptSaveChanges() == QMessageBox::Cancel)
        return;

    // Disable the run button
    ui->actionRun->setEnabled(false);

    // Connect it to resume
    disconnect(ui->actionRun, SIGNAL(triggered()));
    connect(ui->actionRun, SIGNAL(triggered()), this, SLOT(resumeExec()));

    // Launch game
    QProcess *game = new QProcess(this);
    connect(game, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(applicationClosed()));
    connect(game, SIGNAL(finished(int,QProcess::ExitStatus)), m_debugger, SLOT(gameEnded(int,QProcess::ExitStatus)));
    QString program = Project::getProjectDir() + "/" + Project::getProjectName() + ".exe";

    // Set version argument
    QStringList args;
    args.push_back("-debug"); // Run debug by default

    // Start process
    game->start(program, args);

    // Setup debugger
    m_debugger->reset();
    m_debugger->connectToHost();
}

void MainWindow::applicationClosed()
{
    // Enable the run button
    ui->actionRun->setEnabled(true);

    // Connect it to start application
    disconnect(ui->actionRun, SIGNAL(triggered()));
    connect(ui->actionRun, SIGNAL(triggered()), this, SLOT(startApplication()));

    // Disable debug commands
    disableRuntimeComands();
    disableStepCommands();
}

void MainWindow::enableRuntimeComands()
{
    ui->actionPause->setEnabled(true);
    ui->actionStop->setEnabled(true);
    ui->actionRestart->setEnabled(true);
}

void MainWindow::disableRuntimeComands()
{
    ui->actionPause->setEnabled(false);
    ui->actionStop->setEnabled(false);
    ui->actionRestart->setEnabled(false);
}

void MainWindow::enableStepCommands()
{
    ui->actionStepOver->setEnabled(true);
    ui->actionStepInto->setEnabled(true);
    ui->actionStepOut->setEnabled(true);
}

void MainWindow::disableStepCommands()
{
    ui->actionStepOver->setEnabled(false);
    ui->actionStepInto->setEnabled(false);
    ui->actionStepOut->setEnabled(false);
}

void MainWindow::enableResume()
{
    ui->actionRun->setEnabled(true);
    ui->actionPause->setEnabled(false);
}

void MainWindow::disableResume()
{
    ui->actionRun->setEnabled(false);
    ui->actionPause->setEnabled(true);
}

void MainWindow::showSettings()
{
    SettingsDialog *dialog = new SettingsDialog(this);
    dialog->exec();
}

void MainWindow::stopExec()
{
    m_debugger->stop();
}

void MainWindow::resumeExec()
{
    m_debugger->resume();
}

void MainWindow::interruptExec()
{
    m_debugger->interrupt();
}

void MainWindow::restartExec()
{
    // TODO
}

void MainWindow::workspaceModeSelected(QAction *selection)
{
    if(selection == ui->actionCascade)
    {
        // Cascade selected
        workspace()->m_mdiWidget->setViewMode(QMdiArea::SubWindowView);
    }
    else if(selection == ui->actionTabbed)
    {
        // Tabbed selected
        workspace()->m_mdiWidget->setViewMode(QMdiArea::TabbedView);
        workspace()->m_mdiWidget->setTabsClosable(true);
        workspace()->m_mdiWidget->setTabsMovable(true);

        // Setup tabs
        Q_FOREACH(QTabBar* tab, workspace()->m_mdiWidget->findChildren<QTabBar*>())
            tab->setExpanding(false);
    }
}
