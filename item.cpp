#include "item.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsScene>

Item::Item(int x, int y, int p){
    setPos(x, y);
    currentPainter = p;
    this->setFlag(GraphicsItemFlag::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    painterList = getPainterList();
}

QRectF Item::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painterList.at(currentPainter)(painter, -30);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}


void Item::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete) this->scene()->removeItem(this);
}

