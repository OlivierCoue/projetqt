#ifndef DAOSTAFF_H
#define DAOSTAFF_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>

#include "dbutil.h"

#include "staff.h"

class DaoStaff
{
public:
    DaoStaff();
    static void save(Staff staff);
    static void update(Staff staff);
    static QSqlQueryModel * getAll();
};

#endif // DAOSTAFF_H
