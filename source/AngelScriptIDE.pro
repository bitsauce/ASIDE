#-------------------------------------------------
#
# Project created by QtCreator 2011-12-23T19:11:37
#
#-------------------------------------------------

QT += core gui network opengl xml widgets

RC_FILE = win32.rc
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    project.cpp \
    projecttree.cpp \
    scripteditor.cpp \
    debugger.cpp \
    scriptintel.cpp \
    settings.cpp \
    workspace.cpp

HEADERS  += mainwindow.h \
    project.h \
    projecttree.h \
    scripteditor.h \
    infowidget.h \
    debugger.h \
    scriptintel.h \
    settings.h \
    workspace.h \
    aside.h

FORMS    += mainwindow.ui \
    projectdialog.ui \
    newprojectdialog.ui \
    scripteditor.ui \
    scriptsearch.ui \
    scriptreplace.ui \
    scriptgoto.ui \
    settings.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += win32.rc
