#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include "item.h"

class Line : public QGraphicsItem
{
public:
    Line();
    void setHalfX();
    void setY();
    void setPoint();
    void setQPoint();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Item *getFirstItem() const;
    void setFirstItem(Item *value);

    Item *getSecondItem() const;
    void setSecondItem(Item *value);

private:
    QPoint beginPoint;
    QPoint endPoint;
    QPoint p0;
    QPoint p1;
    QPoint p2;
    QPoint p3;
    int halfX;
    int y;
    Item *firstItem;
    Item *secondItem;
};

#endif // LINE_H
