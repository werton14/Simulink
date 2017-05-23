#include "globaloutput.h"
#include<QDebug>

void GlobalOutput::updateGlobalOutputXML(){

    QDomElement globalOutputXML = addElement(doc,doc,"GlobalOutput");
    globalOutputXML.setAttribute("id",id);
    addElement(doc,globalOutputXML,"PreviousElementType", previousElementType);
    addElement(doc,globalOutputXML,"PreviousElementID", QString::number(previousElementID));
    addElement(doc,globalOutputXML,"Function",function);
    QDomElement pos = addElement(doc,globalOutputXML, "Position");
    addElement(doc,pos,"X",QString::number(this->pos().x()));
    addElement(doc,pos,"Y",QString::number(this->pos().y()));
    qDebug()<<doc.toString();
}
