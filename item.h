#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <painters.h>
#include <QPainter>


class Item;

class Item: public QGraphicsItem, QObject
{
public:
    Item(int x,int y, int p);
    virtual void keyPressEvent(QKeyEvent*);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setCurrentPainter(int p){currentPainter = p;}

private:
    QList<void(*)(QPainter*, int)> painterList;
    int currentPainter = 0;

};


#endif // ITEM_H
