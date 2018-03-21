#ifndef DAOACCOUNT_H
#define DAOACCOUNT_H

#include <QtWidgets>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "account.h"

class DaoAccount
{
public:
    DaoAccount();
    static int save(Account account);
    static void update(Account account);
};

#endif // DAOACCOUNT_H
