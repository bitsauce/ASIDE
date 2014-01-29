/********************************************************************************
** Form generated from reading UI file 'leveleditor.ui'
**
** Created: Tue 10. Jul 17:37:58 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELEDITOR_H
#define UI_LEVELEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelEditor
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *LevelEditor)
    {
        if (LevelEditor->objectName().isEmpty())
            LevelEditor->setObjectName(QString::fromUtf8("LevelEditor"));
        LevelEditor->resize(320, 241);
        graphicsView = new QGraphicsView(LevelEditor);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 301, 221));

        retranslateUi(LevelEditor);

        QMetaObject::connectSlotsByName(LevelEditor);
    } // setupUi

    void retranslateUi(QWidget *LevelEditor)
    {
        LevelEditor->setWindowTitle(QApplication::translate("LevelEditor", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LevelEditor: public Ui_LevelEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELEDITOR_H
