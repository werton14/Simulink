#include "node.h"
#include<QDebug>

void Node::updateNodeXML(){

    QDomElement nodeXML = addElement(doc, doc, "Node");
    nodeXML.setAttribute("id", id);
    addElement(doc, nodeXML, "PreviousElementID", QString::number(previousElementId));
    addElement(doc, nodeXML, "PreviousElementType", previousElementType);
    addElement(doc, nodeXML, "FirstOutputID", QString::number(firstOutputId));
    addElement(doc, nodeXML, "SecondOutputID", QString::number(secondOutputId));
    addElement(doc, nodeXML, "FirstOutputType", firstOutputType);
    addElement(doc, nodeXML, "SecondOutputType", secondOutputType);
    if(adderInputNumber == NULL) addElement(doc, nodeXML, "AdderInputNumber", "NULL");
    else addElement(doc, nodeXML, "AdderInputNumber", QString::number(adderInputNumber));
    QDomElement pos = addElement(doc, nodeXML, "Position");
    addElement(doc, pos, "X", QString::number(this->pos().x()));
    addElement(doc, pos, "Y", QString::number(this->pos().y()));
    qDebug() << doc.toString();
}
