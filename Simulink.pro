#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T21:27:34
#
#-------------------------------------------------

QT       += core gui
QT       += xml

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
    line.cpp \
    iteminfo.cpp \
    SceneItem/transferfunction.cpp \
    SceneItem/position.cpp

HEADERS  += scenewindow.h \
    view.h \
    scene.h \
    item.h \
    preview.h \
    painters.h \
    contextmenu.h \
    paramnamevector.h \
    line.h \
    iteminfo.h \
    SceneItem/transferfunction.h \
    SceneItem/position.h

RESOURCES +=
