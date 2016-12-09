#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T21:27:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simulink
TEMPLATE = app


SOURCES += main.cpp\
        scenewindow.cpp \
    view.cpp \
    scene.cpp \
    item.cpp \
    preview.cpp \
    painters.cpp \
    contextmenu.cpp \
    paramnamevector.cpp \
    line.cpp

HEADERS  += scenewindow.h \
    view.h \
    scene.h \
    item.h \
    preview.h \
    painters.h \
    contextmenu.h \
    paramnamevector.h \
    line.h

RESOURCES +=
