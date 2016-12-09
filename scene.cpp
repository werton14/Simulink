#include "scene.h"

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
    secondItem = firstItem;
    firstItem = this->focusItem();
    qDebug() << "Work";
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
        Line *line = new Line(p1, p2);
        line->setPos(firstItem->pos().x() , firstItem->pos().y());
        this->addItem(line);
    }
    emit item->keyPressEvent(event);
}
