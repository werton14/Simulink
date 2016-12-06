#ifndef PAINTERS_H
#define PAINTERS_H
#include <QPainter>
#include <QList>

QList<void(*)(QPainter*, int)> getPainterList();

#endif // PAINTERS_H
