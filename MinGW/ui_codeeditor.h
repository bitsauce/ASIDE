/********************************************************************************
** Form generated from reading UI file 'codeeditor.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEEDITOR_H
#define UI_CODEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeEditor
{
public:
    QAction *actionClose;
    QAction *actionSave_Class;
    QAction *actionNew_Class;
    QAction *actionOpen_Class;
    QAction *actionFind;
    QAction *actionReplace;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *namespaceBox;
    QComboBox *methodBox;
    QMenuBar *menubar;
    QMenu *menuClass;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CodeEditor)
    {
        if (CodeEditor->objectName().isEmpty())
            CodeEditor->setObjectName(QString::fromUtf8("CodeEditor"));
        CodeEditor->resize(417, 255);
        actionClose = new QAction(CodeEditor);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave_Class = new QAction(CodeEditor);
        actionSave_Class->setObjectName(QString::fromUtf8("actionSave_Class"));
        actionNew_Class = new QAction(CodeEditor);
        actionNew_Class->setObjectName(QString::fromUtf8("actionNew_Class"));
        actionOpen_Class = new QAction(CodeEditor);
        actionOpen_Class->setObjectName(QString::fromUtf8("actionOpen_Class"));
        actionFind = new QAction(CodeEditor);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionReplace = new QAction(CodeEditor);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        centralwidget = new QWidget(CodeEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        namespaceBox = new QComboBox(centralwidget);
        namespaceBox->setObjectName(QString::fromUtf8("namespaceBox"));

        horizontalLayout->addWidget(namespaceBox);

        methodBox = new QComboBox(centralwidget);
        methodBox->setObjectName(QString::fromUtf8("methodBox"));

        horizontalLayout->addWidget(methodBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        CodeEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CodeEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 417, 26));
        menuClass = new QMenu(menubar);
        menuClass->setObjectName(QString::fromUtf8("menuClass"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        CodeEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(CodeEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CodeEditor->setStatusBar(statusbar);

        menubar->addAction(menuClass->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuClass->addAction(actionNew_Class);
        menuClass->addAction(actionOpen_Class);
        menuClass->addAction(actionSave_Class);
        menuClass->addSeparator();
        menuClass->addAction(actionClose);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);

        retranslateUi(CodeEditor);
        QObject::connect(actionSave_Class, SIGNAL(triggered()), CodeEditor, SLOT(editSave()));
        QObject::connect(actionClose, SIGNAL(triggered()), CodeEditor, SLOT(close()));
        QObject::connect(actionFind, SIGNAL(triggered()), CodeEditor, SLOT(codeFind()));
        QObject::connect(namespaceBox, SIGNAL(currentIndexChanged(int)), CodeEditor, SLOT(namespaceChanged(int)));
        QObject::connect(methodBox, SIGNAL(activated(int)), CodeEditor, SLOT(methodChanged(int)));
        QObject::connect(actionReplace, SIGNAL(triggered()), CodeEditor, SLOT(codeReplace()));

        QMetaObject::connectSlotsByName(CodeEditor);
    } // setupUi

    void retranslateUi(QMainWindow *CodeEditor)
    {
        CodeEditor->setWindowTitle(QApplication::translate("CodeEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("CodeEditor", "Close", 0, QApplication::UnicodeUTF8));
        actionSave_Class->setText(QApplication::translate("CodeEditor", "Save...", 0, QApplication::UnicodeUTF8));
        actionSave_Class->setShortcut(QApplication::translate("CodeEditor", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionNew_Class->setText(QApplication::translate("CodeEditor", "New...", 0, QApplication::UnicodeUTF8));
        actionNew_Class->setShortcut(QApplication::translate("CodeEditor", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen_Class->setText(QApplication::translate("CodeEditor", "Open...", 0, QApplication::UnicodeUTF8));
        actionOpen_Class->setShortcut(QApplication::translate("CodeEditor", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("CodeEditor", "Find...", 0, QApplication::UnicodeUTF8));
        actionFind->setShortcut(QApplication::translate("CodeEditor", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        actionReplace->setText(QApplication::translate("CodeEditor", "Replace...", 0, QApplication::UnicodeUTF8));
        actionReplace->setShortcut(QApplication::translate("CodeEditor", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        namespaceBox->clear();
        namespaceBox->insertItems(0, QStringList()
         << QApplication::translate("CodeEditor", "( Global Scope )", 0, QApplication::UnicodeUTF8)
        );
        menuClass->setTitle(QApplication::translate("CodeEditor", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("CodeEditor", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CodeEditor: public Ui_CodeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEEDITOR_H
