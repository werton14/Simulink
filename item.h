#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "painters.h"
#include "paramnamevector.h"
#include "contextmenu.h"
#include <QPainter>
#include <QVector>
#include <QMouseEvent>


class Item;

class Item: public QGraphicsItem
{
public:
    Item(int x,int y, int p);
    QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent*);
    virtual void mouseDoubleClickEvent(QMouseEvent*);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setCurrentPainter(int p){currentPainter = p;}

private:
    QList<void(*)(QPainter*, int, QString)> painterList;
    int currentPainter = 0;
    QVector<QString> *paramVector;
    QVector<QString> paramNameVector;
    ContextMenu *contextMenu;
    QString *name;

};


#endif // ITEM_H
