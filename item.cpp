#include "item.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsScene>

Item::Item(int x, int y, int p){
    setPos(x, y);
    currentPainter = p;
//    this->setFlag(GraphicsItemFlag::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    painterList = getPainterList();
    paramNameVector = getParamNameVector(currentPainter);
    paramVector = new QVector<QString>;
    name = new QString("Object");
}

QRectF Item::boundingRect() const
{
    return QRectF (-40,-40,80,80);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painterList.at(currentPainter)(painter, -30, *name);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}


void Item::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete) this->scene()->removeItem(this);
    if(event->key() == Qt::Key_M){
        if(paramVector->size() == 0)
            for(int i = 0; i < paramNameVector.size(); i++) paramVector->push_back("");
        contextMenu = new ContextMenu(paramVector, &paramNameVector);    
        contextMenu->setName(name);
        contextMenu->create_field();
        contextMenu->show();
    }
}

void Item::mouseDoubleClickEvent(QMouseEvent *event)
{
}
