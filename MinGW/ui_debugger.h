/********************************************************************************
** Form generated from reading UI file 'debugger.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGGER_H
#define UI_DEBUGGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Debugger
{
public:
    QAction *actionContinue;
    QAction *actionStepOver;
    QAction *actionStepInto;
    QAction *actionStepOut;
    QAction *actionPause;
    QAction *actionStop;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *debugOut;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Debugger)
    {
        if (Debugger->objectName().isEmpty())
            Debugger->setObjectName(QString::fromUtf8("Debugger"));
        Debugger->resize(516, 363);
        actionContinue = new QAction(Debugger);
        actionContinue->setObjectName(QString::fromUtf8("actionContinue"));
        actionContinue->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/editors/script/icons/dbgcontinue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContinue->setIcon(icon);
        actionStepOver = new QAction(Debugger);
        actionStepOver->setObjectName(QString::fromUtf8("actionStepOver"));
        actionStepOver->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/editors/script/icons/dbgstepover.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepOver->setIcon(icon1);
        actionStepInto = new QAction(Debugger);
        actionStepInto->setObjectName(QString::fromUtf8("actionStepInto"));
        actionStepInto->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/editors/script/icons/dbgstepinto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepInto->setIcon(icon2);
        actionStepOut = new QAction(Debugger);
        actionStepOut->setObjectName(QString::fromUtf8("actionStepOut"));
        actionStepOut->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/editors/script/icons/dbgstepout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStepOut->setIcon(icon3);
        actionPause = new QAction(Debugger);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionPause->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/editors/script/icons/dbgpause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon4);
        actionStop = new QAction(Debugger);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/editors/script/icons/dbgstop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon5);
        centralwidget = new QWidget(Debugger);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        debugOut = new QTextEdit(centralwidget);
        debugOut->setObjectName(QString::fromUtf8("debugOut"));
        debugOut->setEnabled(false);
        debugOut->setReadOnly(true);

        gridLayout->addWidget(debugOut, 0, 0, 1, 1);

        Debugger->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Debugger);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 516, 26));
        Debugger->setMenuBar(menubar);
        statusbar = new QStatusBar(Debugger);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Debugger->setStatusBar(statusbar);
        toolBar = new QToolBar(Debugger);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMinimumSize(QSize(0, 26));
        toolBar->setMaximumSize(QSize(16777215, 26));
        toolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        Debugger->addToolBar(Qt::BottomToolBarArea, toolBar);
        Debugger->insertToolBarBreak(toolBar);

        toolBar->addAction(actionContinue);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();
        toolBar->addAction(actionStepInto);
        toolBar->addAction(actionStepOver);
        toolBar->addAction(actionStepOut);

        retranslateUi(Debugger);
        QObject::connect(actionContinue, SIGNAL(triggered()), Debugger, SLOT(debugContinue()));
        QObject::connect(actionPause, SIGNAL(triggered()), Debugger, SLOT(debugPause()));
        QObject::connect(actionStepInto, SIGNAL(triggered()), Debugger, SLOT(debugStepInto()));
        QObject::connect(actionStepOut, SIGNAL(triggered()), Debugger, SLOT(debugStepOut()));
        QObject::connect(actionStepOver, SIGNAL(triggered()), Debugger, SLOT(debugStepOver()));
        QObject::connect(actionStop, SIGNAL(triggered()), Debugger, SLOT(debugStop()));

        QMetaObject::connectSlotsByName(Debugger);
    } // setupUi

    void retranslateUi(QMainWindow *Debugger)
    {
        Debugger->setWindowTitle(QApplication::translate("Debugger", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionContinue->setText(QApplication::translate("Debugger", "Continue", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionContinue->setToolTip(QApplication::translate("Debugger", "Continue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStepOver->setText(QApplication::translate("Debugger", "StepOver", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStepOver->setToolTip(QApplication::translate("Debugger", "Step Over", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStepInto->setText(QApplication::translate("Debugger", "StepInto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStepInto->setToolTip(QApplication::translate("Debugger", "Step Into", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStepOut->setText(QApplication::translate("Debugger", "StepOut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStepOut->setToolTip(QApplication::translate("Debugger", "Step Out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPause->setText(QApplication::translate("Debugger", "Pause", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("Debugger", "Pause", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("Debugger", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("Debugger", "Stop", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("Debugger", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Debugger: public Ui_Debugger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGGER_H
