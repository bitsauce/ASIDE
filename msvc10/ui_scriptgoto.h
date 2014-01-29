/********************************************************************************
** Form generated from reading UI file 'scriptgoto.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTGOTO_H
#define UI_SCRIPTGOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ScriptGoTo
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *gotoLineEdit;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *gotoButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ScriptGoTo)
    {
        if (ScriptGoTo->objectName().isEmpty())
            ScriptGoTo->setObjectName(QStringLiteral("ScriptGoTo"));
        ScriptGoTo->resize(243, 101);
        gridLayout = new QGridLayout(ScriptGoTo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(ScriptGoTo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        gotoLineEdit = new QLineEdit(ScriptGoTo);
        gotoLineEdit->setObjectName(QStringLiteral("gotoLineEdit"));

        gridLayout_2->addWidget(gotoLineEdit, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        gotoButton = new QPushButton(ScriptGoTo);
        gotoButton->setObjectName(QStringLiteral("gotoButton"));

        gridLayout_3->addWidget(gotoButton, 0, 2, 1, 1);

        closeButton = new QPushButton(ScriptGoTo);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout_3->addWidget(closeButton, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 1, 0, 1, 1);


        retranslateUi(ScriptGoTo);

        QMetaObject::connectSlotsByName(ScriptGoTo);
    } // setupUi

    void retranslateUi(QDialog *ScriptGoTo)
    {
        ScriptGoTo->setWindowTitle(QApplication::translate("ScriptGoTo", "Go to line...", 0));
        label->setText(QApplication::translate("ScriptGoTo", "Line Number:", 0));
        gotoButton->setText(QApplication::translate("ScriptGoTo", "Go To Line", 0));
        closeButton->setText(QApplication::translate("ScriptGoTo", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ScriptGoTo: public Ui_ScriptGoTo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTGOTO_H
