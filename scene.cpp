#include "scene.h"
#include "SceneItem/transferfunction.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>


// Просто нужно переопределить методы что бы работал dropEvent()
Scene::Scene()
{
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
//    TransferFunction *f = dynamic_cast<TransferFunction*> (this->focusItem());
//    QDomElement e = f->getTransferFunctionXML();
    secondItem = firstItem;
    firstItem = this->focusItem();
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    Item *item = dynamic_cast<Item*> (this->focusItem());

    if(event->key() == Qt::Key_L){

        Line *l = new Line();

        Item *fI = dynamic_cast<Item*> (firstItem);
        Item *sI = dynamic_cast<Item*> (secondItem);
        fI->addLine(l);
        sI->addLine(l);
        l->setFirstItem(fI);
        l->setSecondItem(sI);

        l->setQPoint();
        l->setPos(firstItem->pos().x() , firstItem->pos().y());
        this->addItem(l);
    }
    if(focusItem()){
        item->keyPressEvent(event);
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(focusItem()){
        focusItem()->setPos(event->scenePos());
        Item *item = dynamic_cast<Item*> (focusItem());
        item->repaintLines();
    }
}
