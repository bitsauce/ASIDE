/********************************************************************************
** Form generated from reading UI file 'configeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGEDITOR_H
#define UI_CONFIGEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigEditor
{
public:
    QGridLayout *gridLayout;
    QLineEdit *programLineEdit;
    QToolButton *browseProgramButton;
    QLabel *programLabel;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *ConfigEditor)
    {
        if (ConfigEditor->objectName().isEmpty())
            ConfigEditor->setObjectName(QStringLiteral("ConfigEditor"));
        ConfigEditor->resize(255, 99);
        gridLayout = new QGridLayout(ConfigEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        programLineEdit = new QLineEdit(ConfigEditor);
        programLineEdit->setObjectName(QStringLiteral("programLineEdit"));

        gridLayout->addWidget(programLineEdit, 1, 1, 1, 1);

        browseProgramButton = new QToolButton(ConfigEditor);
        browseProgramButton->setObjectName(QStringLiteral("browseProgramButton"));

        gridLayout->addWidget(browseProgramButton, 1, 2, 1, 1);

        programLabel = new QLabel(ConfigEditor);
        programLabel->setObjectName(QStringLiteral("programLabel"));

        gridLayout->addWidget(programLabel, 1, 0, 1, 1);

        nameLabel = new QLabel(ConfigEditor);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(ConfigEditor);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);


        retranslateUi(ConfigEditor);

        QMetaObject::connectSlotsByName(ConfigEditor);
    } // setupUi

    void retranslateUi(QWidget *ConfigEditor)
    {
        ConfigEditor->setWindowTitle(QApplication::translate("ConfigEditor", "Form", 0));
        browseProgramButton->setText(QApplication::translate("ConfigEditor", "...", 0));
        programLabel->setText(QApplication::translate("ConfigEditor", "Program:", 0));
        nameLabel->setText(QApplication::translate("ConfigEditor", "Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigEditor: public Ui_ConfigEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGEDITOR_H
