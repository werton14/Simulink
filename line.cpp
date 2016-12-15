#include "line.h"

Line::Line(QPoint begin, QPoint end): beginPoint(begin), endPoint(end)
{
    setHalfX();
    setY();
    setPoint();
}

void Line::setHalfX()
{
    halfX = (endPoint.x() - beginPoint.x()) / 2;
}

void Line::setPoint()
{
    p0.setX(0);
    p0.setY(0);
    p1.setX(halfX);
    p1.setY(0);
    p2.setX(halfX);
    p2.setY(y);
    p3.setX(2 * halfX);
    p3.setY(y);
}

QRectF Line::boundingRect() const
{
    return QRectF(0, 0, 2 * halfX, y);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(2);
    painter->drawLine(p0, p1);
    painter->drawLine(p1, p2);
    painter->drawLine(p2, p3);
}

void Line::setY()
{
    y = -1 * (beginPoint.y() - endPoint.y());
}