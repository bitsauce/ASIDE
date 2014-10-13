/********************************************************************************
** Form generated from reading UI file 'profiler.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILER_H
#define UI_PROFILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profiler
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Profiler)
    {
        if (Profiler->objectName().isEmpty())
            Profiler->setObjectName(QStringLiteral("Profiler"));
        Profiler->resize(1081, 300);
        gridLayout = new QGridLayout(Profiler);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Profiler);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        treeWidget = new QTreeWidget(Profiler);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(Profiler);

        QMetaObject::connectSlotsByName(Profiler);
    } // setupUi

    void retranslateUi(QWidget *Profiler)
    {
        Profiler->setWindowTitle(QApplication::translate("Profiler", "Form", 0));
        pushButton->setText(QApplication::translate("Profiler", "Close", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("Profiler", "Average", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("Profiler", "Min", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("Profiler", "Max", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Profiler", "Funciton", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(3, QApplication::translate("Profiler", "10 ms", 0));
        ___qtreewidgetitem1->setText(2, QApplication::translate("Profiler", "90 ms", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Profiler", "150 ms", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Profiler", "void test()", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QApplication::translate("Profiler", "19999 ms", 0));
        ___qtreewidgetitem2->setText(0, QApplication::translate("Profiler", "void foo()", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Profiler: public Ui_Profiler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILER_H
