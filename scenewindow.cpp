#include "scenewindow.h"

SceneWindow::SceneWindow()
{
    createMenuBar();
    configureInterface();
}

SceneWindow::~SceneWindow()
{

}

void SceneWindow::configureInterface()
{
    gridLayout = new QGridLayout;
    sceneB = new Scene;
    itemBar = new View(sceneB);
    //Заполняем нашими превьюшками наш "Итем бар"
    for(int i = 0; i < 2; i++)
        sceneB->addItem(new Preview(33, 65 * i + 33, i));
    itemBar->setFixedWidth(69);
    itemBar->setAcceptDrops(false);
    workZone = new QTabWidget;
    gridLayout->addWidget(itemBar, 1,1);
    gridLayout->addWidget(workZone, 1,2);
    gridLayout->setMenuBar(menuBar);
    setLayout(gridLayout);
}

void SceneWindow::createMenuBar()
{
    menuBar = new QMenuBar();
    QMenu *fileMenu = new QMenu("File");
    fileMenu->addAction("New");
    fileMenu->addSeparator();
    fileMenu->addAction("Open");
    fileMenu->addAction("Close");
    fileMenu->addSeparator();
    fileMenu->addAction("Save");
    fileMenu->addAction("Seve as");
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(new QMenu("Help"));
    connect(fileMenu->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(newFile()));
    connect(fileMenu->actions().at(3), SIGNAL(triggered(bool)), this, SLOT(closeFile()));
}

void SceneWindow::newFile()
{
    workZone->addTab(new View(new Scene), "Новая схема");
}

void SceneWindow::closeFile()
{
    workZone->removeTab(workZone->currentIndex());
}
