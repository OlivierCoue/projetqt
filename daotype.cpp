#include "daotype.h"

DaoType::DaoType()
{
}

QVector<StaffType> DaoType::getAll()
{
    QVector<StaffType> typeVector;

    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    QSqlQuery query(DbUtil::getInstance()->getConnection());
    query.prepare("SELECT * FROM [TType]");
    query.exec();
    while(query.next()) {
        typeVector.append(StaffType(query.value(0).toInt(), query.value(1).toString()));
    }
    return typeVector;
}
