/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLineEdit *lineEdit_2;
    QToolButton *browseDefaultApplication;
    QLineEdit *applicationLineEdit;
    QLabel *defaultApplicationLabel;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFileTypeButton;
    QPushButton *removeFileTypeButton;
    QTreeWidget *fileTypeTree;
    QDialogButtonBox *buttonBox;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(800, 600);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_3->addWidget(checkBox, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_3->addWidget(lineEdit_3, 2, 2, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 2, 1, 1);

        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 3, 1, 1, 1);

        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_3->addWidget(checkBox_3, 3, 2, 1, 1);

        checkBox_4 = new QCheckBox(frame);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 2, 1, 1, 1);

        browseDefaultApplication = new QToolButton(frame);
        browseDefaultApplication->setObjectName(QStringLiteral("browseDefaultApplication"));

        gridLayout_3->addWidget(browseDefaultApplication, 4, 2, 1, 1);

        applicationLineEdit = new QLineEdit(frame);
        applicationLineEdit->setObjectName(QStringLiteral("applicationLineEdit"));

        gridLayout_3->addWidget(applicationLineEdit, 4, 1, 1, 1);

        defaultApplicationLabel = new QLabel(frame);
        defaultApplicationLabel->setObjectName(QStringLiteral("defaultApplicationLabel"));

        gridLayout_3->addWidget(defaultApplicationLabel, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addFileTypeButton = new QPushButton(frame);
        addFileTypeButton->setObjectName(QStringLiteral("addFileTypeButton"));

        horizontalLayout->addWidget(addFileTypeButton);

        removeFileTypeButton = new QPushButton(frame);
        removeFileTypeButton->setObjectName(QStringLiteral("removeFileTypeButton"));

        horizontalLayout->addWidget(removeFileTypeButton);


        gridLayout_2->addLayout(horizontalLayout, 8, 0, 1, 1);

        fileTypeTree = new QTreeWidget(frame);
        fileTypeTree->setObjectName(QStringLiteral("fileTypeTree"));

        gridLayout_2->addWidget(fileTypeTree, 4, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        treeWidget = new QTreeWidget(Settings);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));
        QObject::connect(addFileTypeButton, SIGNAL(clicked()), Settings, SLOT(addFileType()));
        QObject::connect(removeFileTypeButton, SIGNAL(clicked()), Settings, SLOT(removeFileType()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", 0));
        checkBox->setText(QApplication::translate("Settings", "Auto Indentation", 0));
        label_2->setText(QApplication::translate("Settings", "Editor Font:", 0));
        label_3->setText(QApplication::translate("Settings", "Restore Previous Session:", 0));
        lineEdit_3->setText(QApplication::translate("Settings", "18pt", 0));
        pushButton->setText(QApplication::translate("Settings", "Set As Default Editor", 0));
        checkBox_2->setText(QApplication::translate("Settings", "On Launch", 0));
        checkBox_3->setText(QApplication::translate("Settings", "After Project Load", 0));
        checkBox_4->setText(QApplication::translate("Settings", "Auto-complete", 0));
        lineEdit_2->setText(QApplication::translate("Settings", "Courier New", 0));
        browseDefaultApplication->setText(QApplication::translate("Settings", "...", 0));
        applicationLineEdit->setText(QString());
        defaultApplicationLabel->setText(QApplication::translate("Settings", "Default AS Application:", 0));
        label->setText(QApplication::translate("Settings", "File types:", 0));
        addFileTypeButton->setText(QApplication::translate("Settings", "Add", 0));
        removeFileTypeButton->setText(QApplication::translate("Settings", "Remove", 0));
        QTreeWidgetItem *___qtreewidgetitem = fileTypeTree->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("Settings", "Extention", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Settings", "File Type", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("Settings", "Entry", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("Settings", "Script Editor", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Settings", "Datatypes", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
