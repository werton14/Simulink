#include "View.h"
#include <QDebug>
#include <QDropEvent>

#include "SceneItem/transferfunction.h"
View::View(Scene * scene) :
    QGraphicsView(scene)
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void View::dragEnterEvent ( QDragEnterEvent * event )
{
    QGraphicsView::dragEnterEvent(event);
}

void View::dragLeaveEvent ( QDragLeaveEvent * event )
{
    QGraphicsView::dragLeaveEvent(event);
}

void View::dragMoveEvent ( QDragMoveEvent * event )
{
    QGraphicsView::dragMoveEvent(event);
}

void View::dropEvent ( QDropEvent * event )
{
    QDomDocument doc;
        TransferFunction *item = new TransferFunction(0, 0, event->mimeData()->text().toInt(), doc);
        item->setPos(mapToScene(event->pos()));
        this->scene()->addItem(item);
        QGraphicsView::dropEvent(event);

}

void View::resizeEvent(QResizeEvent *event)
{
    setSceneRect(0, 0, viewport()->rect().width(), viewport()->rect().height());
}
