#ifndef DAOACCOUNT_H
#define DAOACCOUNT_H

#include <QtWidgets>
#include <QSqlQuery>

class DaoAccount
{
public:
    DaoAccount();
    int search(QString login, QString password);
};

#endif // DAOACCOUNT_H
