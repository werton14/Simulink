#include "line.h"
#include <cmath>
#include <QDebug>
Line::Line()
{

}

void Line::setHalfX()
{
    halfX = (endPoint.x() - beginPoint.x()) / 2;
}

void Line::setPoint()
{
    p0.setX(0+30);
    p0.setY(0);
    p1.setX(halfX);
    p1.setY(0);
    p2.setX(halfX);
    p2.setY(y);
    p3.setX(2 * halfX-20);
    p3.setY(y);

}

void Line::setQPoint()
{
    beginPoint.setX(firstItem->pos().x());
    endPoint.setX(secondItem->pos().x());
    beginPoint.setY(firstItem->pos().y());
    endPoint.setY(secondItem->pos().y());
    setHalfX();
    setY();
    setPoint();
    this->setPos(firstItem->x(), firstItem->y());
}

QRectF Line::boundingRect() const
{
    return QRectF(0,-1*abs(y), 2 * halfX,2*abs(y));
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(2);
    painter->drawLine(p0, p1);
    painter->drawLine(p1, p2);
    painter->drawLine(p2, p3);
}

Item *Line::getFirstItem() const
{
    return firstItem;
}

void Line::setFirstItem(Item *value)
{
    firstItem = value;
}

Item *Line::getSecondItem() const
{
    return secondItem;
}

void Line::setSecondItem(Item *value)
{
    secondItem = value;
}

void Line::setY()
{
    y = -1*((beginPoint.y() - endPoint.y()));
}
