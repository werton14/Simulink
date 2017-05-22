#include "painters.h"


// Функции для отрисовки объектов

void ramp(QPainter *painter, int p, QString s)
{
    QPen pen_1;
    pen_1.setWidth(2);
    QPen pen_2;
    pen_2.setWidth(1);
    QPen pen_3;
    pen_3.setWidth(1);
    QRect rect (p,p,50,60);
    painter->setPen(pen_3);
    painter->setBrush(Qt::white);
    painter->drawRect(rect);  
    painter->setPen(pen_2);
    painter->drawLine(p + rect.width()/7,p + (rect.height()/4) * 3.5,p + rect.width()/2.5,p + (rect.height()/4) * 3.5);
    painter->drawLine(p + rect.width()/2.5,p + (rect.height()/4) * 3.5,p + (rect.width()/4) * 3.5, p + rect.height()/6);
    painter->setPen(pen_1);
    painter->drawLine(p + rect.width() + 1,p + (rect.height()/5) * 2,p + rect.width() + rect.width()/5,p + rect.height()/2);
    painter->drawLine(p + rect.width() + 1,p + (rect.height()/5) * 3,p + rect.width() + rect.width()/5,p + rect.height()/2);
    painter->drawText(-5 - ((s.size())*5)/2, p-2,s);
}

void scape(QPainter *painter, int p, QString s){
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
    painter->drawText(3 - ((s.size())*5)/2  , p-2,s);
}

void adder(QPainter *painter, int p, QString s){
    QPen pen_1;
    pen_1.setWidth(2);
    QPen pen_2;
    pen_2.setWidth(1);
    QPen pen_3;
    pen_3.setWidth(1);
    QRect rect(p,p,50,50);
    painter->setPen(pen_3);
    painter->drawEllipse(rect);
    painter->drawLine(p+11,p + (rect.height()/3)*2,p+15,p + (rect.height()/3)*2);
    painter->drawLine(p+13,p + (rect.height()/3)*1.9,p+13,p + (rect.height()/3)*2.15);
    painter->drawLine(p+20,p+7 + (rect.height()/3)*2,p+24,p+7 + (rect.height()/3)*2);
    painter->drawLine(p+22,p+7 + (rect.height()/3)*1.9,p+22,p+7 + (rect.height()/3)*2.15);
    painter->setPen(pen_1);
    painter->drawLine(p-1,p + rect.height()/2,p-7,p + rect.height()/4);
    painter->drawLine(p-1,p + rect.height()/2,p-7,p + (rect.height()/4)*3);
    painter->drawLine(p + rect.width()/2,p+51,p + (rect.width()/3)*0.8,p+57);
    painter->drawLine(p + rect.width()/2,p+51,p + (rect.width()/3)*2.4,p+57);
    painter->drawLine(p+57,p + rect.height()/2,p+49.5,p + (rect.height()/3));
    painter->drawLine(p+57,p + rect.height()/2,p+49.5,p + (rect.height()/3)*2.1);
}

void transferFunction(QPainter *painter, int p, QString s){
    QPen pen_1;
    pen_1.setWidth(2);
    QPen pen_2;
    pen_2.setWidth(1);
    QPen pen_3;
    pen_3.setWidth(1);
    QRect rect(p,p,50,40);
    painter->setPen(pen_3);
    painter->drawRect(rect);
    painter->setPen(pen_1);
    painter->drawLine(p-1,p + rect.height()/2,p-6,p + (rect.height()/3 )* 0.7);
    painter->drawLine(p-1,p + rect.height()/2,p-6,p + (rect.height()/3) * 2.6);
    painter->drawLine(p+58,p + rect.height()/2,p+51,p + rect.height()/3);
    painter->drawLine(p+58,p + rect.height()/2,p+51,p + (rect.height()/3) * 2.2);
}

// Эта функция возращает список указателей на функции выше

QList<void(*)(QPainter*, int, QString)> getPainterList(){
    QList<void(*)(QPainter*, int, QString)> a;
    a.push_back(ramp);
    a.push_back(scape);
    a.push_back(adder);
    a.push_back(transferFunction);
    return a;
}
