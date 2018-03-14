#ifndef DAOCLIENT_H
#define DAOCLIENT_H

#include <QVector>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include "client.h"

class DaoClient
{
public:
    DaoClient();
    static QSqlQueryModel * search(QString firstname, QString lastname);
};

#endif // DAOCLIENT_H
