#include "globalinput.h"

#include <QDebug>



void GlobalInput::updateGlobalInputXML(){

    QDomElement globalInputXML = addElement(doc,doc,"GlobalInput");
    globalInputXML.setAttribute("id",id);
    addElement(doc,globalInputXML,"NextElementType", nextElementType);
    addElement(doc,globalInputXML,"NextElementID", QString::number(nextElementID));
    if(adderInputNumber == NULL) addElement(doc,globalInputXML,"AdderInputNumber","NULL");
    else addElement(doc,globalInputXML,"AdderInputNumber",QString::number(adderInputNumber));
    addElement(doc,doc,"Function",function);
    QDomElement pos = addElement(doc,globalInputXML, "Position");
    addElement(doc,pos,"X",QString::number(this->pos().x()));
    addElement(doc,pos,"Y",QString::number(this->pos().y()));
    qDebug()<<doc.toString();

}
