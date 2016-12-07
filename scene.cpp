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
