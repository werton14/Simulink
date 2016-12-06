#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include <scene.h>
#include <view.h>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QAction>
#include "preview.h"
#include <QTabWidget>
#include <QTabBar>


class SceneWindow : public QWidget
{
    Q_OBJECT

public:
    SceneWindow();
    ~SceneWindow();
private:
    QGridLayout *gridLayout;
    Scene * sceneB;
    Scene * sceneZ;
    View *constructZone;
    View *itemBar;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QList<Preview*> previewList;
    QTabWidget *workZone;
    void configureInterface();
    void createMenuBar();
private slots:
    void newFile();
    void closeFile();
};

#endif // SCENEWINDOW_H
