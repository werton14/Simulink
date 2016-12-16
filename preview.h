#ifndef PREVIEW_H
#define PREVIEW_H
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <painters.h>
#include <QList>

class Preview : public QGraphicsItem
{
public:
    Preview(int x, int y, int p);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setCurentPainter(int p){currentPainter = p;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    int currentPainter = 0;
    QPainter *p1;
    QList<void(*)(QPainter*, int, QString)> painterList;
};

#endif // PREVIEW_H
