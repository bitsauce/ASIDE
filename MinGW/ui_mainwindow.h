/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewProject;
    QAction *actionOpenProject;
    QAction *actionSaveProject;
    QAction *actionEdit;
    QAction *actionPublish;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRun;
    QAction *actionDebug;
    QAction *actionPreview;
    QAction *actionOptions;
    QAction *actionTiled;
    QAction *actionCasade;
    QAction *actionTabbed;
    QAction *actionHorizontonal_Splitt;
    QAction *actionVertical_Splitt;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionSettings;
    QAction *actionNew_Sprite;
    QAction *actionNew_Script;
    QAction *actionClose_Project;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionRestart;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuProject;
    QMenu *menuWorkspace;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionOpenProject = new QAction(MainWindow);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        actionSaveProject = new QAction(MainWindow);
        actionSaveProject->setObjectName(QString::fromUtf8("actionSaveProject"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionPublish = new QAction(MainWindow);
        actionPublish->setObjectName(QString::fromUtf8("actionPublish"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QString::fromUtf8("actionPreview"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionTiled = new QAction(MainWindow);
        actionTiled->setObjectName(QString::fromUtf8("actionTiled"));
        actionCasade = new QAction(MainWindow);
        actionCasade->setObjectName(QString::fromUtf8("actionCasade"));
        actionTabbed = new QAction(MainWindow);
        actionTabbed->setObjectName(QString::fromUtf8("actionTabbed"));
        actionHorizontonal_Splitt = new QAction(MainWindow);
        actionHorizontonal_Splitt->setObjectName(QString::fromUtf8("actionHorizontonal_Splitt"));
        actionVertical_Splitt = new QAction(MainWindow);
        actionVertical_Splitt->setObjectName(QString::fromUtf8("actionVertical_Splitt"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionNew_Sprite = new QAction(MainWindow);
        actionNew_Sprite->setObjectName(QString::fromUtf8("actionNew_Sprite"));
        actionNew_Script = new QAction(MainWindow);
        actionNew_Script->setObjectName(QString::fromUtf8("actionNew_Script"));
        actionClose_Project = new QAction(MainWindow);
        actionClose_Project->setObjectName(QString::fromUtf8("actionClose_Project"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QString::fromUtf8("actionRestart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuBar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"						stop:0 lightgray, stop:1 darkgray);\n"
"}\n"
"\n"
" QMenuBar::item {\n"
"     spacing: 3px; /* spacing between menu bar items */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
" }\n"
"\n"
" QMenuBar::item:selected { /* when selected using mouse or keyboard */\n"
"     background: #a8a8a8;\n"
" }\n"
"\n"
" QMenuBar::item:pressed {\n"
"     background: #888888;\n"
" }"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        menuWorkspace = new QMenu(menuBar);
        menuWorkspace->setObjectName(QString::fromUtf8("menuWorkspace"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAcceptDrops(false);
        mainToolBar->setStyleSheet(QString::fromUtf8("QToolBar {\n"
"	background: rgb(129, 129, 129);\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"	border: 1px solid;\n"
"	\n"
"	border-color: rgb(90, 90, 90);\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"}\n"
"\n"
"QToolBar::handle {\n"
"	image: url(handle.png);\n"
"}"));
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuWorkspace->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionOpenProject);
        menuFile->addAction(actionSaveProject);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionPublish);
        menuFile->addSeparator();
        menuFile->addAction(actionEdit);
        menuEdit->addSeparator();
        menuProject->addAction(actionRun);
        menuProject->addAction(actionDebug);
        menuProject->addAction(actionPreview);
        menuProject->addSeparator();
        menuProject->addAction(actionRestart);
        menuProject->addAction(actionPause);
        menuProject->addAction(actionStop);
        menuProject->addSeparator();
        menuProject->addAction(actionOptions);
        menuWorkspace->addAction(actionTiled);
        menuWorkspace->addAction(actionCasade);
        menuWorkspace->addAction(actionTabbed);
        menuWorkspace->addSeparator();
        menuWorkspace->addAction(actionHorizontonal_Splitt);
        menuWorkspace->addAction(actionVertical_Splitt);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionSettings);
        mainToolBar->addAction(actionNew_Sprite);
        mainToolBar->addAction(actionNew_Script);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionRestart);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionStop);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionEdit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionNewProject, SIGNAL(triggered()), MainWindow, SLOT(newProject()));
        QObject::connect(actionOpenProject, SIGNAL(triggered()), MainWindow, SLOT(openProject()));
        QObject::connect(actionSaveProject, SIGNAL(triggered()), MainWindow, SLOT(saveProject()));
        QObject::connect(actionRun, SIGNAL(triggered()), MainWindow, SLOT(runProject()));
        QObject::connect(actionNew_Sprite, SIGNAL(triggered()), MainWindow, SLOT(editorNewSprite()));
        QObject::connect(actionNew_Script, SIGNAL(triggered()), MainWindow, SLOT(editorNewClass()));
        QObject::connect(actionClose_Project, SIGNAL(triggered()), MainWindow, SLOT(closeProject()));
        QObject::connect(actionDebug, SIGNAL(triggered()), MainWindow, SLOT(debugProject()));
        QObject::connect(actionPreview, SIGNAL(triggered()), MainWindow, SLOT(runDetachProject()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Aurora x2D Editor", 0, QApplication::UnicodeUTF8));
        actionNewProject->setText(QApplication::translate("MainWindow", "&New Project...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewProject->setToolTip(QApplication::translate("MainWindow", "Create a New Project", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpenProject->setText(QApplication::translate("MainWindow", "&Open Project...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpenProject->setToolTip(QApplication::translate("MainWindow", "Open an Existing Project", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpenProject->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+O", 0, QApplication::UnicodeUTF8));
        actionSaveProject->setText(QApplication::translate("MainWindow", "&Save Project...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveProject->setToolTip(QApplication::translate("MainWindow", "Save Current Project", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSaveProject->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionEdit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionEdit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionPublish->setText(QApplication::translate("MainWindow", "Publish...", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        actionRun->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        actionDebug->setText(QApplication::translate("MainWindow", "Debug", 0, QApplication::UnicodeUTF8));
        actionDebug->setShortcut(QApplication::translate("MainWindow", "F6", 0, QApplication::UnicodeUTF8));
        actionPreview->setText(QApplication::translate("MainWindow", "Run Detached", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options...", 0, QApplication::UnicodeUTF8));
        actionOptions->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionTiled->setText(QApplication::translate("MainWindow", "Tiled", 0, QApplication::UnicodeUTF8));
        actionCasade->setText(QApplication::translate("MainWindow", "Casade", 0, QApplication::UnicodeUTF8));
        actionTabbed->setText(QApplication::translate("MainWindow", "Tabbed", 0, QApplication::UnicodeUTF8));
        actionHorizontonal_Splitt->setText(QApplication::translate("MainWindow", "Horizontonal Splitt", 0, QApplication::UnicodeUTF8));
        actionVertical_Splitt->setText(QApplication::translate("MainWindow", "Vertical Splitt", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help...", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings...", 0, QApplication::UnicodeUTF8));
        actionNew_Sprite->setText(QApplication::translate("MainWindow", "New Sprite", 0, QApplication::UnicodeUTF8));
        actionNew_Script->setText(QApplication::translate("MainWindow", "New Script", 0, QApplication::UnicodeUTF8));
        actionClose_Project->setText(QApplication::translate("MainWindow", "Close Project", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuProject->setTitle(QApplication::translate("MainWindow", "Project", 0, QApplication::UnicodeUTF8));
        menuWorkspace->setTitle(QApplication::translate("MainWindow", "Workspace", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Aurora x2D", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
