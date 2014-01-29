/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Project
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *recentGroup;
    QGridLayout *gridLayout;
    QListWidget *recentList;
    QPushButton *clearButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *openButton;

    void setupUi(QWidget *Project)
    {
        if (Project->objectName().isEmpty())
            Project->setObjectName(QString::fromUtf8("Project"));
        Project->resize(400, 300);
        gridLayout_2 = new QGridLayout(Project);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        recentGroup = new QGroupBox(Project);
        recentGroup->setObjectName(QString::fromUtf8("recentGroup"));
        gridLayout = new QGridLayout(recentGroup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        recentList = new QListWidget(recentGroup);
        recentList->setObjectName(QString::fromUtf8("recentList"));

        gridLayout->addWidget(recentList, 0, 0, 1, 1);

        clearButton = new QPushButton(recentGroup);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 1, 0, 1, 1);


        gridLayout_2->addWidget(recentGroup, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newButton = new QPushButton(Project);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        horizontalLayout->addWidget(newButton);

        openButton = new QPushButton(Project);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout->addWidget(openButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 2, 1, 1);

        QWidget::setTabOrder(newButton, openButton);

        retranslateUi(Project);
        QObject::connect(newButton, SIGNAL(clicked()), Project, SLOT(newProject()));
        QObject::connect(openButton, SIGNAL(clicked()), Project, SLOT(openProject()));
        QObject::connect(recentList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), Project, SLOT(recentOpen(QListWidgetItem*)));
        QObject::connect(clearButton, SIGNAL(clicked()), Project, SLOT(clearRecent()));

        QMetaObject::connectSlotsByName(Project);
    } // setupUi

    void retranslateUi(QWidget *Project)
    {
        Project->setWindowTitle(QApplication::translate("Project", "Form", 0, QApplication::UnicodeUTF8));
        recentGroup->setTitle(QApplication::translate("Project", "Recent Projects", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("Project", "Clear List", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("Project", "New Project...", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("Project", "Open Project...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Project: public Ui_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H
