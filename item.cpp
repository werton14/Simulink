#include "item.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsScene>
#include "line.h"

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

void Item::repaintLines()
{
    for(int i = 0; i < line.count(); i++){
        Line *l = dynamic_cast<Line*> (line.at(i));
        l->setQPoint();
        this->scene()->removeItem(l);
        this->scene()->addItem(l);
    }
}

QList<QGraphicsItem *> Item::getLines() const
{
    return line;
}

void Item::addLine(QGraphicsItem *value)
{
    line.push_back(value);
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

QDomElement addElement( QDomDocument &doc, QDomNode &node,
                         const QString &tag,
                          const QString &value )
{
    QDomElement el = doc.createElement( tag );
    node.appendChild( el );
    if ( !value.isNull() ) {
       QDomText txt = doc.createTextNode( value );
       el.appendChild( txt );
    }
    return el;
}
