#include "transferfunction.h"
#include <QDebug>

QDomElement addElement( QDomDocument &doc, QDomNode &node,
                         const QString &tag,
                          const QString &value = QString::null )
{
    QDomElement el = doc.createElement( tag );
    node.appendChild( el );
    if ( !value.isNull() ) {
       QDomText txt = doc.createTextNode( value );
       el.appendChild( txt );
    }
    return el;
}



QDomElement TransferFunction::getTransferFunctionXML()
{
    updateTransferFunctionXML();
    return doc.toElement();
}

void TransferFunction::setTransferFunctionXML(QDomElement &value)
{
    transferFunctionXML = value;
}

void TransferFunction::updateTransferFunctionXML()
{
    transferFunctionXML = addElement(doc, doc, "TransferFuction");
    transferFunctionXML.setAttribute("id", id);
    addElement(doc, transferFunctionXML, "PreviousElementID", QString::number(previousElementId));
    addElement(doc, transferFunctionXML, "PreviousElementType", previousElementType);
    addElement(doc, transferFunctionXML, "NextElementID", QString::number(nextElementId));
    addElement(doc, transferFunctionXML, "NextElementType", nextElementType);
    if(adderInputNumber == NULL) addElement(doc, transferFunctionXML, "AdderInputNumber", "NULL");
    else addElement(doc, transferFunctionXML, "AdderInputNumber", QString::number(adderInputNumber));
    addElement(doc, transferFunctionXML, "Function", function);
    QDomElement pos = addElement(doc, transferFunctionXML, "Position");
    addElement(doc, pos, "X", QString::number(this->pos().x()));
    addElement(doc, pos, "Y", QString::number(this->pos().y()));
    qDebug() << doc.toString();
}
