#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include "scene.h"
#include "view.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QAction>
#include "preview.h"
#include <QTabWidget>
#include <QTabBar>
#include "painters.h"

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
    QGraphicsView *itemBar;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QList<Preview*> previewList;
    QTabWidget *workZone;
    void configureInterface();
    void createMenuBar();
    void test();
private slots:
    void newFile();
    void closeFile();
};

#endif // SCENEWINDOW_H
