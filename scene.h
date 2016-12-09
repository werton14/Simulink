#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include "line.h"
#include "item.h"



class Scene: public QGraphicsScene
{
public:
    Scene();

protected:
    virtual void dragEnterEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dragLeaveEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dragMoveEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void dropEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
private:
    QGraphicsItem *firstItem;
    QGraphicsItem *secondItem;
};

#endif
