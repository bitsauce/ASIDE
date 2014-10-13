#-------------------------------------------------
#
# Project created by QtCreator 2011-12-23T19:11:37
#
#-------------------------------------------------

QT += core gui network opengl xml widgets
CONFIG += qscintilla2

RC_FILE = win32.rc
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    project.cpp \
    projecttree.cpp \
    scripteditor.cpp \
    debugger.cpp \
    settings.cpp \
    workspace.cpp \
    configeditor.cpp \
    editorbase.cpp \
    profiler.cpp

HEADERS += mainwindow.h \
    project.h \
    projecttree.h \
    scripteditor.h \
    infowidget.h \
    debugger.h \
    settings.h \
    workspace.h \
    aside.h \
    configeditor.h \
    editorbase.h \
    profiler.h

FORMS += mainwindow.ui \
    projectdialog.ui \
    newprojectdialog.ui \
    scripteditor.ui \
    scriptsearch.ui \
    scriptreplace.ui \
    scriptgoto.ui \
    settings.ui \
    configeditor.ui \
    profiler.ui

include(../qtsingleapplication/src/qtsingleapplication.pri)

RESOURCES += resources.qrc

OTHER_FILES += win32.rc

SUBDIRS += \
    ../QScintilla/Qt4Qt5/qscintilla.pro
