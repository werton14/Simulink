#ifndef ADDER_H
#define ADDER_H

#include "item.h"

class Adder: public Item
{
public:
    Adder(int x, int y, int p, QDomDocument d):Item(x, y, p), doc(d){}

private:
    int id = (int) this;
    int firstInputId = -1;
    int secondInputId = -1;
    int thirdInputId = -1;
    int nextElementId = -1;
    int firstInputMode = -1;
    int secondInputMode = -1;
    QString firstInputType = "Type";
    QString secondInputType = "Type";
    QString thirdInputType = "Type";
    QString nextElementType = "Type";
    int adderInputNumber = NULL;

    void updateAdderXML();
    QDomDocument doc;
};

#endif // ADDER_H
