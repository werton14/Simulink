#include "scene.h"
#include "SceneItem/transferfunction.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>


// Просто нужно переопределить методы что бы работал dropEvent()
Scene::Scene()
{
    line = NULL;
}

void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
{
}

void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
{
}

void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
{
}

void Scene::dropEvent ( QGraphicsSceneDragDropEvent * event )
{
}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    TransferFunction *f = dynamic_cast<TransferFunction*> (this->focusItem());
    QDomElement e = f->getTransferFunctionXML();
    firstItem = this->focusItem();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    Item *item = dynamic_cast<Item*> (this->focusItem());

    if(event->key() == Qt::Key_L){
        QPoint p1, p2;
        p1.setX(firstItem->pos().x());
        p2.setX(secondItem->pos().x());
        p1.setY(firstItem->pos().y());
        p2.setY(secondItem->pos().y());
        if(line == NULL) line = new Line(p1, p2);
        line->setQPoint(p1, p2);
        line->setPos(firstItem->pos().x() , firstItem->pos().y());
        this->addItem(line);
    }
    if(focusItem()){
        item->keyPressEvent(event);
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(focusItem()){
        focusItem()->setPos(event->scenePos());
    }
    if(line != NULL){
        QPoint p1, p2;
        p1.setX(firstItem->pos().x());
        p2.setX(secondItem->pos().x());
        p1.setY(firstItem->pos().y());
        p2.setY(secondItem->pos().y());
        line->setQPoint(p1, p2);
        line->setPos(firstItem->pos().x() , firstItem->pos().y());
        this->removeItem(line);
        this->addItem(line);
    }
}
