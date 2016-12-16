#ifndef PAINTERS_H
#define PAINTERS_H
#include <QPainter>
#include <QList>
#include <QString>

QList<void(*)(QPainter*, int, QString)> getPainterList();

#endif // PAINTERS_H
