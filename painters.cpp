#include "painters.h"

// Функции для отрисовки объектов

void ramp(QPainter *painter, int p)
{
    QPen pen_1;
    pen_1.setWidth(2);
    QPen pen_2;
    pen_2.setWidth(1);
    QPen pen_3;
    pen_3.setWidth(1);
    QRect rect (p,p,50,60);
    painter->setPen(pen_3);
    painter->drawRect(rect);
    painter->setBrush(Qt::white);
    painter->setPen(pen_2);
    painter->drawLine(p + rect.width()/7,p + (rect.height()/4) * 3.5,p + rect.width()/2.5,p + (rect.height()/4) * 3.5);
    painter->drawLine(p + rect.width()/2.5,p + (rect.height()/4) * 3.5,p + (rect.width()/4) * 3.5, p + rect.height()/6);
    painter->setPen(pen_1);
    painter->drawLine(p + rect.width() + 1,p + (rect.height()/5) * 2,p + rect.width() + rect.width()/5,p + rect.height()/2);
    painter->drawLine(p + rect.width() + 1,p + (rect.height()/5) * 3,p + rect.width() + rect.width()/5,p + rect.height()/2);
}

void scape(QPainter *painter, int p){
    QPen pen_1;
    pen_1.setWidth(2);
    QPen pen_2;
    pen_2.setWidth(1);
    QPen pen_3;
    pen_3.setWidth(1);
    QRect rect(p + 10,p,50,60);
    QRect rect1(p+16,p+6,37,20);
    painter->setPen(pen_2);
    painter->drawRect(rect1);
    painter->setPen(pen_3);
    painter->drawRect(rect);
    painter->setPen(pen_1);
    painter->drawLine(p+10,p + rect.height()/2,p,p + rect.height()/4);
    painter->drawLine(p+10,p + rect.height()/2,p,p + (rect.height()/4)*3);
}

// Эта функция возращает список указателей на функции выше

QList<void(*)(QPainter*, int)> getPainterList(){
    QList<void(*)(QPainter*, int)> a;
    a.push_back(ramp);
    a.push_back(scape);
    return a;
}
