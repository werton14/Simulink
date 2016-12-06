#include "scenewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SceneWindow w;
    w.setMinimumSize(900, 500);
    w.show();

    return a.exec();
}
