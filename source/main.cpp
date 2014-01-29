#if defined(QT_OS_WINDOWS) && !defined(QT_NO_DEBUG)
#define NOMINMAX
#include <windows.h>
#include <vld.h>
#endif

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
