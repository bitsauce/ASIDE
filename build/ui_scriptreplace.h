/********************************************************************************
** Form generated from reading UI file 'scriptreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTREPLACE_H
#define UI_SCRIPTREPLACE_H

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

class Ui_ScriptReplace
{
public:
    QGridLayout *gridLayout;
    QCheckBox *matchCaseCheck;
    QFormLayout *formLayout;
    QLineEdit *searchPhraseEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *replacePhraseEdit;
    QCheckBox *wholeWordsCheck;
    QHBoxLayout *horizontalLayout;
    QPushButton *replaceAllButton;
    QPushButton *replaceButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QCheckBox *tempBox;

    void setupUi(QDialog *ScriptReplace)
    {
        if (ScriptReplace->objectName().isEmpty())
            ScriptReplace->setObjectName(QStringLiteral("ScriptReplace"));
        ScriptReplace->resize(379, 184);
        gridLayout = new QGridLayout(ScriptReplace);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        matchCaseCheck = new QCheckBox(ScriptReplace);
        matchCaseCheck->setObjectName(QStringLiteral("matchCaseCheck"));
        matchCaseCheck->setEnabled(false);

        gridLayout->addWidget(matchCaseCheck, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        searchPhraseEdit = new QLineEdit(ScriptReplace);
        searchPhraseEdit->setObjectName(QStringLiteral("searchPhraseEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, searchPhraseEdit);

        label = new QLabel(ScriptReplace);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(ScriptReplace);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        replacePhraseEdit = new QLineEdit(ScriptReplace);
        replacePhraseEdit->setObjectName(QStringLiteral("replacePhraseEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, replacePhraseEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        wholeWordsCheck = new QCheckBox(ScriptReplace);
        wholeWordsCheck->setObjectName(QStringLiteral("wholeWordsCheck"));
        wholeWordsCheck->setEnabled(false);

        gridLayout->addWidget(wholeWordsCheck, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        replaceAllButton = new QPushButton(ScriptReplace);
        replaceAllButton->setObjectName(QStringLiteral("replaceAllButton"));
        replaceAllButton->setEnabled(true);

        horizontalLayout->addWidget(replaceAllButton);

        replaceButton = new QPushButton(ScriptReplace);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));

        horizontalLayout->addWidget(replaceButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        prevButton = new QPushButton(ScriptReplace);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        nextButton = new QPushButton(ScriptReplace);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        tempBox = new QCheckBox(ScriptReplace);
        tempBox->setObjectName(QStringLiteral("tempBox"));

        gridLayout->addWidget(tempBox, 4, 0, 1, 1);


        retranslateUi(ScriptReplace);

        QMetaObject::connectSlotsByName(ScriptReplace);
    } // setupUi

    void retranslateUi(QDialog *ScriptReplace)
    {
        ScriptReplace->setWindowTitle(QApplication::translate("ScriptReplace", "Replace", 0));
        matchCaseCheck->setText(QApplication::translate("ScriptReplace", "Match case", 0));
        label->setText(QApplication::translate("ScriptReplace", "Find:", 0));
        label_2->setText(QApplication::translate("ScriptReplace", "Replace:", 0));
        wholeWordsCheck->setText(QApplication::translate("ScriptReplace", "Whole words only", 0));
        replaceAllButton->setText(QApplication::translate("ScriptReplace", "Replace All", 0));
        replaceButton->setText(QApplication::translate("ScriptReplace", "Replace", 0));
        prevButton->setText(QApplication::translate("ScriptReplace", "Previous", 0));
        nextButton->setText(QApplication::translate("ScriptReplace", "Next", 0));
        tempBox->setText(QApplication::translate("ScriptReplace", "Replace in all files", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptReplace: public Ui_ScriptReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTREPLACE_H
