#ifndef GLOBALINPUT_H
#define GLOBALINPUT_H

#include <QString>
#include <QDomElement>
#include <QDomDocument>

#include "item.h"

class GlobalInput: public Item
{

public:
    GlobalInput(int x, int y, int p, QDomDocument d):Item(x, y, p), doc(d){}

private:
    int id = (int) this;
    int nextElementID = -1;
    QString nextElementType = "Type";
    int adderInputNumber = NULL;
    QString function = "Function";

    void updateGlobalInputXML();
    QDomDocument doc;
};

#endif // GLOBALINPUT_H
