/********************************************************************************
** Form generated from reading UI file 'scriptsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTSEARCH_H
#define UI_SCRIPTSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ScriptSearch
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *findAllButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QFormLayout *formLayout;
    QLineEdit *searchPhraseEdit;
    QLabel *label;
    QCheckBox *matchCaseCheck;
    QCheckBox *wholeWordsCheck;
    QCheckBox *regexpCheck;

    void setupUi(QDialog *ScriptSearch)
    {
        if (ScriptSearch->objectName().isEmpty())
            ScriptSearch->setObjectName(QStringLiteral("ScriptSearch"));
        ScriptSearch->resize(379, 184);
        gridLayout = new QGridLayout(ScriptSearch);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findAllButton = new QPushButton(ScriptSearch);
        findAllButton->setObjectName(QStringLiteral("findAllButton"));
        findAllButton->setEnabled(false);

        horizontalLayout->addWidget(findAllButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        prevButton = new QPushButton(ScriptSearch);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        nextButton = new QPushButton(ScriptSearch);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        searchPhraseEdit = new QLineEdit(ScriptSearch);
        searchPhraseEdit->setObjectName(QStringLiteral("searchPhraseEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, searchPhraseEdit);

        label = new QLabel(ScriptSearch);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        matchCaseCheck = new QCheckBox(ScriptSearch);
        matchCaseCheck->setObjectName(QStringLiteral("matchCaseCheck"));
        matchCaseCheck->setEnabled(true);

        gridLayout->addWidget(matchCaseCheck, 2, 0, 1, 1);

        wholeWordsCheck = new QCheckBox(ScriptSearch);
        wholeWordsCheck->setObjectName(QStringLiteral("wholeWordsCheck"));
        wholeWordsCheck->setEnabled(true);

        gridLayout->addWidget(wholeWordsCheck, 3, 0, 1, 1);

        regexpCheck = new QCheckBox(ScriptSearch);
        regexpCheck->setObjectName(QStringLiteral("regexpCheck"));

        gridLayout->addWidget(regexpCheck, 1, 0, 1, 1);


        retranslateUi(ScriptSearch);

        QMetaObject::connectSlotsByName(ScriptSearch);
    } // setupUi

    void retranslateUi(QDialog *ScriptSearch)
    {
        ScriptSearch->setWindowTitle(QApplication::translate("ScriptSearch", "Search", 0));
        findAllButton->setText(QApplication::translate("ScriptSearch", "Find All", 0));
        prevButton->setText(QApplication::translate("ScriptSearch", "Previous", 0));
        nextButton->setText(QApplication::translate("ScriptSearch", "Next", 0));
        label->setText(QApplication::translate("ScriptSearch", "Search:", 0));
        matchCaseCheck->setText(QApplication::translate("ScriptSearch", "Match case", 0));
        wholeWordsCheck->setText(QApplication::translate("ScriptSearch", "Whole words only", 0));
        regexpCheck->setText(QApplication::translate("ScriptSearch", "Use Regular Expression", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptSearch: public Ui_ScriptSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTSEARCH_H
