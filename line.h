#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPoint>
#include <QPainter>
#include <QPen>

class Line : public QGraphicsItem
{
public:
    Line(QPoint, QPoint);
    void setHalfX();
    void setY();
    void setPoint();
    void setQPoint(QPoint, QPoint);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPoint beginPoint;
    QPoint endPoint;
    QPoint p0;
    QPoint p1;
    QPoint p2;
    QPoint p3;
    int halfX;
    int y;
};

#endif // LINE_H
