#include "adder.h"
#include<QDebug>

void Adder::updateAdderXML(){

    QDomElement AdderXML = addElement(doc, doc, "Adder");
    AdderXML.setAttribute("id", id);
    addElement(doc, AdderXML, "FirstInputID", QString::number(firstInputId));
    addElement(doc, AdderXML, "SecondInputID", QString::number(secondInputId));
    addElement(doc, AdderXML, "ThirdInputID", QString::number(thirdInputId));
    addElement(doc, AdderXML, "FirstInputType", firstInputType);
    addElement(doc, AdderXML, "SecondInputType", secondInputType);
    addElement(doc, AdderXML, "ThirdInputType", thirdInputType);
    addElement(doc, AdderXML, "NextElementID", QString::number(nextElementId));
    addElement(doc, AdderXML, "NextElementType", nextElementType);
    addElement(doc, AdderXML, "FirstInputMode", QString::number(firstInputMode));
    addElement(doc, AdderXML, "SecondInputMode", QString::number(secondInputMode));
    addElement(doc, AdderXML, "ThirdInputID", "NULL");
    if(adderInputNumber == NULL) addElement(doc, AdderXML, "AdderInputNumber", "NULL");
    else addElement(doc, AdderXML, "AdderInputNumber", QString::number(adderInputNumber));
    QDomElement pos = addElement(doc, AdderXML, "Position");
    addElement(doc, pos, "X", QString::number(this->pos().x()));
    addElement(doc, pos, "Y", QString::number(this->pos().y()));
    qDebug() << doc.toString();

}
