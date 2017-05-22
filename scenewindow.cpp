#include "scenewindow.h"

SceneWindow::SceneWindow()
{
    createMenuBar();
    configureInterface();
    test();
}

SceneWindow::~SceneWindow()
{

}

void SceneWindow::configureInterface()
{
    gridLayout = new QGridLayout;
    itemBar = new QGraphicsView(new QGraphicsScene);
    //Заполняем нашими превьюшками наш "Итем бар"
    for(int i = 0; i < getPainterList().size(); i++)
        itemBar->scene()->addItem(new Preview(33, 65 * i + 33, i));
    itemBar->setAlignment(Qt::AlignTop);
    itemBar->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
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
    fileMenu->addAction("New", this, SLOT(newFile()), Qt::CTRL + Qt::Key_N);
    fileMenu->addSeparator();
    fileMenu->addAction("Open");
    fileMenu->addAction("Close", this, SLOT(closeFile()), Qt::CTRL + Qt::Key_F4);
    fileMenu->addSeparator();
    fileMenu->addAction("Save");
    fileMenu->addAction("Seve as");
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(new QMenu("Help"));
}

void SceneWindow::test()
{

}

void SceneWindow::newFile()
{
    workZone->addTab(new View(new Scene), "Новая схема");
}
void SceneWindow::closeFile()
{
    workZone->removeTab(workZone->currentIndex());
}
