#include "paramnamevector.h"


QVector<QString> getParamNameVector(int currentObject)
{
    QVector<QString> paramNameVector;
    paramNameVector.push_back("Type");
    paramNameVector.push_back("Value");

    QList<QVector<QString>> listParamNameVector;
    listParamNameVector.push_back(paramNameVector);
    listParamNameVector.push_back(paramNameVector);
    listParamNameVector.push_back(paramNameVector);
    paramNameVector.push_back("Device");
    listParamNameVector.push_back(paramNameVector);



    return listParamNameVector.at(currentObject);
}
