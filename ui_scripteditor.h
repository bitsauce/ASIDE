/********************************************************************************
** Form generated from reading UI file 'scripteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTEDITOR_H
#define UI_SCRIPTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptEditor
{
public:
    QAction *actionSearch;
    QAction *actionReplace;
    QAction *actionGo_To;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *namedScopeList;
    QComboBox *functionList;
    QToolButton *searchButton;
    QToolButton *replaceButton;
    QToolButton *gotoButton;
    QLabel *positionLabel;

    void setupUi(QWidget *ScriptEditor)
    {
        if (ScriptEditor->objectName().isEmpty())
            ScriptEditor->setObjectName(QStringLiteral("ScriptEditor"));
        ScriptEditor->resize(520, 400);
        actionSearch = new QAction(ScriptEditor);
        actionSearch->setObjectName(QStringLiteral("actionSearch"));
        actionReplace = new QAction(ScriptEditor);
        actionReplace->setObjectName(QStringLiteral("actionReplace"));
        actionGo_To = new QAction(ScriptEditor);
        actionGo_To->setObjectName(QStringLiteral("actionGo_To"));
        gridLayout = new QGridLayout(ScriptEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        namedScopeList = new QComboBox(ScriptEditor);
        namedScopeList->setObjectName(QStringLiteral("namedScopeList"));

        horizontalLayout->addWidget(namedScopeList);

        functionList = new QComboBox(ScriptEditor);
        functionList->setObjectName(QStringLiteral("functionList"));

        horizontalLayout->addWidget(functionList);

        searchButton = new QToolButton(ScriptEditor);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout->addWidget(searchButton);

        replaceButton = new QToolButton(ScriptEditor);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));

        horizontalLayout->addWidget(replaceButton);

        gotoButton = new QToolButton(ScriptEditor);
        gotoButton->setObjectName(QStringLiteral("gotoButton"));

        horizontalLayout->addWidget(gotoButton);

        positionLabel = new QLabel(ScriptEditor);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(positionLabel);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ScriptEditor);

        QMetaObject::connectSlotsByName(ScriptEditor);
    } // setupUi

    void retranslateUi(QWidget *ScriptEditor)
    {
        ScriptEditor->setWindowTitle(QApplication::translate("ScriptEditor", "Form", 0));
        actionSearch->setText(QApplication::translate("ScriptEditor", "Search", 0));
        actionSearch->setShortcut(QApplication::translate("ScriptEditor", "Ctrl+F", 0));
        actionReplace->setText(QApplication::translate("ScriptEditor", "Replace", 0));
        actionReplace->setShortcut(QApplication::translate("ScriptEditor", "Ctrl+H", 0));
        actionGo_To->setText(QApplication::translate("ScriptEditor", "Go To", 0));
        actionGo_To->setShortcut(QApplication::translate("ScriptEditor", "Ctrl+G", 0));
        namedScopeList->clear();
        namedScopeList->insertItems(0, QStringList()
         << QApplication::translate("ScriptEditor", "[ Global Scope ]", 0)
        );
        functionList->clear();
        functionList->insertItems(0, QStringList()
         << QApplication::translate("ScriptEditor", "[ Function ]", 0)
        );
        searchButton->setText(QApplication::translate("ScriptEditor", "...", 0));
        searchButton->setShortcut(QApplication::translate("ScriptEditor", "Ctrl+F", 0));
        replaceButton->setText(QApplication::translate("ScriptEditor", "...", 0));
        gotoButton->setText(QApplication::translate("ScriptEditor", "...", 0));
        positionLabel->setText(QApplication::translate("ScriptEditor", "Line: Col:", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptEditor: public Ui_ScriptEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTEDITOR_H
