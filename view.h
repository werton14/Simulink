#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QMimeData>
#include "Scene.h"
#include <item.h>

class View: public QGraphicsView
{
public:
    View(Scene * scene);

protected:
    virtual void dragEnterEvent ( QDragEnterEvent * event );
    virtual void dragLeaveEvent ( QDragLeaveEvent * event );
    virtual void dragMoveEvent ( QDragMoveEvent * event );
    virtual void dropEvent ( QDropEvent * event );
    virtual void resizeEvent(QResizeEvent * event);

};

#endif
