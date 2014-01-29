/********************************************************************************
** Form generated from reading UI file 'updater.ui'
**
** Created: Fri 24. Aug 01:44:24 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATER_H
#define UI_UPDATER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Updater
{
public:
    QGridLayout *gridLayout;
    QLabel *progressLabel;
    QProgressBar *progressBar;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Updater)
    {
        if (Updater->objectName().isEmpty())
            Updater->setObjectName(QString::fromUtf8("Updater"));
        Updater->resize(400, 300);
        gridLayout = new QGridLayout(Updater);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressLabel = new QLabel(Updater);
        progressLabel->setObjectName(QString::fromUtf8("progressLabel"));

        gridLayout->addWidget(progressLabel, 0, 0, 1, 1);

        progressBar = new QProgressBar(Updater);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 1);

        cancelButton = new QPushButton(Updater);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(Updater);
        QObject::connect(cancelButton, SIGNAL(clicked()), Updater, SLOT(close()));

        QMetaObject::connectSlotsByName(Updater);
    } // setupUi

    void retranslateUi(QDialog *Updater)
    {
        Updater->setWindowTitle(QApplication::translate("Updater", "Updater", 0, QApplication::UnicodeUTF8));
        progressLabel->setText(QApplication::translate("Updater", "Downloading Update", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Updater", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Updater: public Ui_Updater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATER_H
