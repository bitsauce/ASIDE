/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *projectNameEdit;
    QLabel *label_3;
    QLineEdit *projectPathEdit;
    QToolButton *browseButton;
    QLabel *label_2;

    void setupUi(QWidget *NewProjectDialog)
    {
        if (NewProjectDialog->objectName().isEmpty())
            NewProjectDialog->setObjectName(QStringLiteral("NewProjectDialog"));
        NewProjectDialog->resize(378, 141);
        NewProjectDialog->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(NewProjectDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(NewProjectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(NewProjectDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        projectNameEdit = new QLineEdit(NewProjectDialog);
        projectNameEdit->setObjectName(QStringLiteral("projectNameEdit"));

        gridLayout->addWidget(projectNameEdit, 1, 1, 1, 1);

        label_3 = new QLabel(NewProjectDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        projectPathEdit = new QLineEdit(NewProjectDialog);
        projectPathEdit->setObjectName(QStringLiteral("projectPathEdit"));

        gridLayout->addWidget(projectPathEdit, 2, 1, 1, 1);

        browseButton = new QToolButton(NewProjectDialog);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        gridLayout->addWidget(browseButton, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        label_2 = new QLabel(NewProjectDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"Calibri\";"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        retranslateUi(NewProjectDialog);
        QObject::connect(browseButton, SIGNAL(clicked()), NewProjectDialog, SLOT(browseProjectPath()));
        QObject::connect(buttonBox, SIGNAL(accepted()), NewProjectDialog, SLOT(acceptDialog()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewProjectDialog, SLOT(cancelDialog()));

        QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QWidget *NewProjectDialog)
    {
        NewProjectDialog->setWindowTitle(QApplication::translate("NewProjectDialog", "Create New Project", 0));
        label->setText(QApplication::translate("NewProjectDialog", "Project Name:", 0));
        label_3->setText(QApplication::translate("NewProjectDialog", "Project Path:", 0));
        browseButton->setText(QApplication::translate("NewProjectDialog", "...", 0));
        label_2->setText(QApplication::translate("NewProjectDialog", "New Project", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
