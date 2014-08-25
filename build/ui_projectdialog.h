/********************************************************************************
** Form generated from reading UI file 'projectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTDIALOG_H
#define UI_PROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *newProjectButton;
    QListView *recentList;
    QPushButton *clearButton;
    QPushButton *openProjectButton;
    QLabel *label;
    QWidget *widget;

    void setupUi(QWidget *ProjectDialog)
    {
        if (ProjectDialog->objectName().isEmpty())
            ProjectDialog->setObjectName(QStringLiteral("ProjectDialog"));
        ProjectDialog->resize(400, 326);
        ProjectDialog->setStyleSheet(QLatin1String("ProjectDialog {\n"
"background-image: url(:/projectdialog/images/projectdialog_bg.png);\n"
"}\n"
"\n"
"/* Push Button */\n"
"QPushButton {\n"
"font: 10pt \"Calibri\";\n"
"padding: 4px;\n"
"border-radius: 3px;\n"
"background-color: transparent;\n"
"background-image: url();\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: rgba(125, 175, 255, 127);\n"
"background-image: url();\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"background-color: rgba(224, 255, 255, 255);\n"
"background-image: url();\n"
"}\n"
"\n"
"/* List View */\n"
"QListView {\n"
"show-decoration-selected: 1;\n"
"background-color: transparent;\n"
"background-image: url();\n"
"}\n"
"\n"
"QListView::item {\n"
"font: 10pt \"Calibri\";\n"
"padding: 4px;\n"
"border-radius: 3px;\n"
"background-color: transparent;\n"
"background-image: url();\n"
"}\n"
"\n"
"/* Label */\n"
"QLabel {\n"
"font: 12pt \"Calibri\";\n"
"background-color: transparent;\n"
"background-image: url();\n"
"}"));
        gridLayout_2 = new QGridLayout(ProjectDialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(11, 11, 11, 11);
        newProjectButton = new QPushButton(ProjectDialog);
        newProjectButton->setObjectName(QStringLiteral("newProjectButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/projectdialog/icons/x2D_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        newProjectButton->setIcon(icon);

        gridLayout->addWidget(newProjectButton, 0, 0, 1, 1);

        recentList = new QListView(ProjectDialog);
        recentList->setObjectName(QStringLiteral("recentList"));
        recentList->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(recentList, 3, 0, 1, 1);

        clearButton = new QPushButton(ProjectDialog);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 4, 0, 1, 1);

        openProjectButton = new QPushButton(ProjectDialog);
        openProjectButton->setObjectName(QStringLiteral("openProjectButton"));
        openProjectButton->setIcon(icon);

        gridLayout->addWidget(openProjectButton, 1, 0, 1, 1);

        label = new QLabel(ProjectDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 2, 1, 1);

        widget = new QWidget(ProjectDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(400, 64));
        widget->setMaximumSize(QSize(400, 64));

        gridLayout_2->addWidget(widget, 1, 2, 1, 1);


        retranslateUi(ProjectDialog);
        QObject::connect(clearButton, SIGNAL(clicked()), ProjectDialog, SLOT(clearList()));
        QObject::connect(recentList, SIGNAL(clicked(QModelIndex)), ProjectDialog, SLOT(clickList(QModelIndex)));

        QMetaObject::connectSlotsByName(ProjectDialog);
    } // setupUi

    void retranslateUi(QWidget *ProjectDialog)
    {
        ProjectDialog->setWindowTitle(QApplication::translate("ProjectDialog", "Project Dialog", 0));
        newProjectButton->setText(QApplication::translate("ProjectDialog", "New Project...", 0));
        clearButton->setText(QApplication::translate("ProjectDialog", "Clear List", 0));
        openProjectButton->setText(QApplication::translate("ProjectDialog", "Open Project...", 0));
        label->setText(QApplication::translate("ProjectDialog", "Recent Projects", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectDialog: public Ui_ProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTDIALOG_H
