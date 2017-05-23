#ifndef GLOBALOUTPUT_H
#define GLOBALOUTPUT_H

#include "item.h"

class GlobalOutput : public Item
{
public:
    GlobalOutput(int x, int y, int p, QDomDocument d):Item(x, y, p), doc(d){}

private:
    int id = (int) this;
    int previousElementID = -1;
    QString previousElementType = "Type";
    QString function = "Function";

    void updateGlobalOutputXML();
    QDomDocument doc;
};

#endif // GLOBALOUTPUT_H
