#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H

#include <QString>
#include <QDomElement>
#include <QDomDocument>

#include "position.h"
#include "item.h"

class TransferFunction : public Item
{
public:
    TransferFunction(int x, int y, int p, QDomDocument d):Item(x, y, p), doc(d){ position.setX(x), position.setY(y);}

    QDomElement getTransferFunctionXML();
    void setTransferFunctionXML(QDomElement &value);

private:
    int id = (int) this;
    int previousElementId = -1;
    int nextElementId = -1;
    QString previousElementType = "Type";
    QString nextElementType = "Type";
    int adderInputNumber = NULL;
    QString function = "Function";
    Position position;

    QDomElement transferFunctionXML;
    void updateTransferFunctionXML();
    QDomDocument doc;

};

#endif // TRANSFERFUNCTION_H
