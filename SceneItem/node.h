#ifndef NODE_H
#define NODE_H

#include "item.h"

class Node: public Item
{
public:
    Node(int x, int y, int p, QDomDocument d):Item(x, y, p), doc(d){}

private:
    int id = (int) this;
    QString previousElementType = "Type";
    int previousElementId = -1;
    int firstOutputId = -1;
    int secondOutputId = -1;
    QString firstOutputType = "Type";
    QString secondOutputType = "Type";
    int adderInputNumber = NULL;

    void updateNodeXML();
    QDomDocument doc;
};

#endif // NODE_H
