/********************************************************************************
** Form generated from reading UI file 'profiler.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILER_H
#define UI_PROFILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profiler
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *profilerTree;
    QHBoxLayout *horizontalLayout;
    QToolButton *startProfilerButton;
    QSpacerItem *horizontalSpacer;
    QCheckBox *bottomUpToggle;
    QRadioButton *totalRadioButton;
    QRadioButton *stepRadioButton;

    void setupUi(QWidget *Profiler)
    {
        if (Profiler->objectName().isEmpty())
            Profiler->setObjectName(QStringLiteral("Profiler"));
        Profiler->resize(1080, 300);
        gridLayout = new QGridLayout(Profiler);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        profilerTree = new QTreeWidget(Profiler);
        profilerTree->setObjectName(QStringLiteral("profilerTree"));

        gridLayout->addWidget(profilerTree, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startProfilerButton = new QToolButton(Profiler);
        startProfilerButton->setObjectName(QStringLiteral("startProfilerButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/toolbar/icons/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        startProfilerButton->setIcon(icon);

        horizontalLayout->addWidget(startProfilerButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bottomUpToggle = new QCheckBox(Profiler);
        bottomUpToggle->setObjectName(QStringLiteral("bottomUpToggle"));

        horizontalLayout->addWidget(bottomUpToggle);

        totalRadioButton = new QRadioButton(Profiler);
        totalRadioButton->setObjectName(QStringLiteral("totalRadioButton"));

        horizontalLayout->addWidget(totalRadioButton);

        stepRadioButton = new QRadioButton(Profiler);
        stepRadioButton->setObjectName(QStringLiteral("stepRadioButton"));
        stepRadioButton->setChecked(true);

        horizontalLayout->addWidget(stepRadioButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Profiler);

        QMetaObject::connectSlotsByName(Profiler);
    } // setupUi

    void retranslateUi(QWidget *Profiler)
    {
        Profiler->setWindowTitle(QApplication::translate("Profiler", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = profilerTree->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("Profiler", "Calls", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("Profiler", "Time", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("Profiler", "Average", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("Profiler", "Min", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("Profiler", "Max", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Profiler", "Funciton", 0));
        startProfilerButton->setText(QApplication::translate("Profiler", "...", 0));
        bottomUpToggle->setText(QApplication::translate("Profiler", "Bottom Up", 0));
        totalRadioButton->setText(QApplication::translate("Profiler", "Total", 0));
        stepRadioButton->setText(QApplication::translate("Profiler", "Step", 0));
    } // retranslateUi

};

namespace Ui {
    class Profiler: public Ui_Profiler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILER_H
