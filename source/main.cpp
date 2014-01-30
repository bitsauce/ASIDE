#include <QtSingleApplication>
#include <QObject>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Launch a single instance application
    QtSingleApplication app("aside", argc, argv);

    // If a instance is already running, tell it to open the
    // file specified by the command line
    if(app.isRunning())
    {
        if(QCoreApplication::arguments().size() > 1)
        {
            QString filePath = QCoreApplication::arguments().at(1);
            if(!filePath.isEmpty()) {
                app.sendMessage(filePath);
            }
        }
        return 0;
    }

    // Show main window
    MainWindow window;
    window.show();
    QObject::connect(&app, SIGNAL(messageReceived(const QString&)), &window, SLOT(applicationMessage(const QString&)));
    
    return app.exec();
}
