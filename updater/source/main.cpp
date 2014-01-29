#include <QtGui/QApplication>
#include "updater.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList args = QCoreApplication::arguments();
    int version = -1;
    for(int i = 0; i < args.size(); i++)
    {
        if(args[i].contains("-version"))
            version = args[i].split('=')[1].toInt();
    }

    Updater w;
    if(w.hasUpdate(version))
    {
        w.show();
        if(w.fetchUpdate())
            w.installUpdate();
        else
            return -1;
    }else
        return -1;
    
    return 0;
}
