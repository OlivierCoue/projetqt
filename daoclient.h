#ifndef DAOCLIENT_H
#define DAOCLIENT_H

#include <QVector>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>

#include "dbutil.h"

#include "client.h"

class DaoClient
{
public:
    DaoClient();
    static QSqlQueryModel * search(QString firstname, QString lastname, int id, QDate start, QDate end);
    static void save(Client client);
    static void update(Client client);
    static Client * get(int index);
};

#endif // DAOCLIENT_H
