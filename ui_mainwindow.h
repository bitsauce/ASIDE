/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionSave_All;
    QAction *actionEdit;
    QAction *actionPublish;
    QAction *actionRun;
    QAction *actionOptions;
    QAction *actionCascade;
    QAction *actionTabbed;
    QAction *actionCustomize;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionSettings;
    QAction *actionClose_Project;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionRestart;
    QAction *actionBrowse_Project;
    QAction *actionOpen_File;
    QAction *actionSave_File;
    QAction *actionNew_File;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionRename;
    QAction *actionNew;
    QAction *actionStepOver;
    QAction *actionStepInto;
    QAction *actionStepOut;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuProject;
    QMenu *menuWorkspace;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QLatin1String("QMenuBar {\n"
"    background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: #a8a8a8;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background: #888888;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: rgb(40, 40, 40);\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    text-align: center;\n"
"    background: rgb(0, 180, 255);\n"
"}\n"
"\n"
"/*QSplitter::handle {\n"
"	background-color: rgb(100, 100, 100);\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"    width: 2px;\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 2px;\n"
"}*/\n"
"\n"
"QToolBar {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(215, 215, 215, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	padding: 0px;\n"
"	border-bottom: transparent;\n"
"}\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"border-top: 2px solid #C2C7CB;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"left: 5px; /* move to the "
                        "right by 5px */\n"
"}\n"
"/* Style the tab using the tab sub-control. Note that it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"border: 2px solid #C4C4C3;\n"
"border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"border-top-left-radius: 4px;\n"
"border-top-right-radius: 4px;\n"
"min-width: 8ex;\n"
"padding: 2px;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #fafafa, stop: 0.4 #f4f4f4, stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"QTabBar::tab:selected {\n"
"border-color: #9B9B9B;\n"
"border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"QTabBar::tab:!selected {\n"
"margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
""));
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/menubar/icons/new_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Project->setIcon(icon);
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/menubar/icons/open_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon1);
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        actionSave_All->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/menubar/icons/save_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_All->setIcon(icon2);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionPublish = new QAction(MainWindow);
        actionPublish->setObjectName(QStringLiteral("actionPublish"));
        actionPublish->setEnabled(false);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionRun->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/toolbar/icons/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon3);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionOptions->setEnabled(false);
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName(QStringLiteral("actionCascade"));
        actionCascade->setCheckable(true);
        actionCascade->setChecked(true);
        actionTabbed = new QAction(MainWindow);
        actionTabbed->setObjectName(QStringLiteral("actionTabbed"));
        actionTabbed->setCheckable(true);
        actionCustomize = new QAction(MainWindow);
        actionCustomize->setObjectName(QStringLiteral("actionCustomize"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionClose_Project = new QAction(MainWindow);
        actionClose_Project->setObjectName(QStringLiteral("actionClose_Project"));
        actionClose_Project->setEnabled(false);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionPause->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/toolbar/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon4);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/toolbar/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon5);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionRestart->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/toolbar/icons/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon6);
        actionBrowse_Project = new QAction(MainWindow);
        actionBrowse_Project->setObjectName(QStringLiteral("actionBrowse_Project"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionOpen_File->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/menubar/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon7);
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QStringLiteral("actionSave_File"));
        actionSave_File->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/menubar/icons/save_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon8);
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        actionNew_File->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/menubar/icons/new_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon9);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCut->setEnabled(false);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionPaste->setEnabled(false);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionDelete->setEnabled(false);
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        actionRename->setEnabled(false);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionNew->setEnabled(false);
        actionStepOver = new QAction(MainWindow);
        actionStepOver->setObjectName(QStringLiteral("actionStepOver"));
        actionStepOver->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/debugger/icons/dbgstepover.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepOver->setIcon(icon10);
        actionStepInto = new QAction(MainWindow);
        actionStepInto->setObjectName(QStringLiteral("actionStepInto"));
        actionStepInto->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/debugger/icons/dbgstepinto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepInto->setIcon(icon11);
        actionStepOut = new QAction(MainWindow);
        actionStepOut->setObjectName(QStringLiteral("actionStepOut"));
        actionStepOut->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/debugger/icons/dbgstepout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepOut->setIcon(icon12);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
        menuWorkspace = new QMenu(menuBar);
        menuWorkspace->setObjectName(QStringLiteral("menuWorkspace"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuWorkspace->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave_File);
        menuFile->addAction(actionSave_All);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionPublish);
        menuFile->addSeparator();
        menuFile->addAction(actionEdit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionNew);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionRename);
        menuProject->addAction(actionRun);
        menuProject->addSeparator();
        menuProject->addAction(actionRestart);
        menuProject->addAction(actionPause);
        menuProject->addAction(actionStop);
        menuProject->addSeparator();
        menuProject->addAction(actionStepOver);
        menuProject->addAction(actionStepInto);
        menuProject->addAction(actionStepOut);
        menuProject->addSeparator();
        menuProject->addAction(actionOptions);
        menuWorkspace->addAction(actionCascade);
        menuWorkspace->addAction(actionTabbed);
        menuWorkspace->addSeparator();
        menuWorkspace->addAction(actionCustomize);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionSettings);

        retranslateUi(MainWindow);
        QObject::connect(actionEdit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionNew_Project, SIGNAL(triggered()), MainWindow, SLOT(newProject()));
        QObject::connect(actionOpen_Project, SIGNAL(triggered()), MainWindow, SLOT(openProject()));
        QObject::connect(actionRun, SIGNAL(triggered()), MainWindow, SLOT(startApplication()));
        QObject::connect(actionClose_Project, SIGNAL(triggered()), MainWindow, SLOT(closeProject()));
        QObject::connect(actionPause, SIGNAL(triggered()), MainWindow, SLOT(interruptExec()));
        QObject::connect(actionStop, SIGNAL(triggered()), MainWindow, SLOT(stopExec()));
        QObject::connect(actionRestart, SIGNAL(triggered()), MainWindow, SLOT(restartExec()));
        QObject::connect(actionNew_File, SIGNAL(triggered()), MainWindow, SLOT(newFile()));
        QObject::connect(actionOpen_File, SIGNAL(triggered()), MainWindow, SLOT(openFile()));
        QObject::connect(actionSave_File, SIGNAL(triggered()), MainWindow, SLOT(saveFile()));
        QObject::connect(actionSave_All, SIGNAL(triggered()), MainWindow, SLOT(saveAllFiles()));
        QObject::connect(actionSettings, SIGNAL(triggered()), MainWindow, SLOT(showSettings()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AngelScript IDE", 0));
        actionNew_Project->setText(QApplication::translate("MainWindow", "&New Project...", 0));
#ifndef QT_NO_TOOLTIP
        actionNew_Project->setToolTip(QApplication::translate("MainWindow", "Create new project", 0));
#endif // QT_NO_TOOLTIP
        actionNew_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0));
        actionOpen_Project->setText(QApplication::translate("MainWindow", "&Open Project...", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen_Project->setToolTip(QApplication::translate("MainWindow", "Open a project", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+O", 0));
        actionSave_All->setText(QApplication::translate("MainWindow", "&Save All", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_All->setToolTip(QApplication::translate("MainWindow", "Save all open files", 0));
#endif // QT_NO_TOOLTIP
        actionSave_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionEdit->setText(QApplication::translate("MainWindow", "E&xit", 0));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindow", "Exit application", 0));
#endif // QT_NO_TOOLTIP
        actionEdit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionPublish->setText(QApplication::translate("MainWindow", "Publish...", 0));
#ifndef QT_NO_TOOLTIP
        actionPublish->setToolTip(QApplication::translate("MainWindow", "Publish project", 0));
#endif // QT_NO_TOOLTIP
        actionRun->setText(QApplication::translate("MainWindow", "Run", 0));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("MainWindow", "Run game", 0));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options...", 0));
#ifndef QT_NO_TOOLTIP
        actionOptions->setToolTip(QApplication::translate("MainWindow", "Project options", 0));
#endif // QT_NO_TOOLTIP
        actionOptions->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionCascade->setText(QApplication::translate("MainWindow", "Cascade", 0));
#ifndef QT_NO_TOOLTIP
        actionCascade->setToolTip(QApplication::translate("MainWindow", "Show windows in cascade", 0));
#endif // QT_NO_TOOLTIP
        actionTabbed->setText(QApplication::translate("MainWindow", "Tabbed", 0));
#ifndef QT_NO_TOOLTIP
        actionTabbed->setToolTip(QApplication::translate("MainWindow", "Show windows in tabs", 0));
#endif // QT_NO_TOOLTIP
        actionCustomize->setText(QApplication::translate("MainWindow", "Customize...", 0));
#ifndef QT_NO_TOOLTIP
        actionCustomize->setToolTip(QApplication::translate("MainWindow", "Customize workspace", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About", 0));
#endif // QT_NO_TOOLTIP
        actionHelp->setText(QApplication::translate("MainWindow", "Context...", 0));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings...", 0));
        actionClose_Project->setText(QApplication::translate("MainWindow", "Close Project", 0));
#ifndef QT_NO_TOOLTIP
        actionClose_Project->setToolTip(QApplication::translate("MainWindow", "Close the current project", 0));
#endif // QT_NO_TOOLTIP
        actionClose_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+W", 0));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("MainWindow", "Pause game", 0));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stop game", 0));
#endif // QT_NO_TOOLTIP
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0));
#ifndef QT_NO_TOOLTIP
        actionRestart->setToolTip(QApplication::translate("MainWindow", "Restart game", 0));
#endif // QT_NO_TOOLTIP
        actionBrowse_Project->setText(QApplication::translate("MainWindow", "Open in Explorer", 0));
#ifndef QT_NO_TOOLTIP
        actionBrowse_Project->setToolTip(QApplication::translate("MainWindow", "Open project in explorer", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File...", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen_File->setToolTip(QApplication::translate("MainWindow", "Open a file", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave_File->setText(QApplication::translate("MainWindow", "Save File", 0));
        actionSave_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionNew_File->setText(QApplication::translate("MainWindow", "New File...", 0));
        actionNew_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0));
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionRename->setText(QApplication::translate("MainWindow", "Rename", 0));
        actionRename->setShortcut(QApplication::translate("MainWindow", "F2", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionStepOver->setText(QApplication::translate("MainWindow", "Step Over", 0));
        actionStepInto->setText(QApplication::translate("MainWindow", "Step Into", 0));
        actionStepOut->setText(QApplication::translate("MainWindow", "Step Out", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuProject->setTitle(QApplication::translate("MainWindow", "Project", 0));
        menuWorkspace->setTitle(QApplication::translate("MainWindow", "Workspace", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
