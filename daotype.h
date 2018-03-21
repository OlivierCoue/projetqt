#ifndef DAOTYPE_H
#define DAOTYPE_H

#include <QVector>
#include <QtWidgets>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "dbutil.h"
#include "stafftype.h"

using namespace std;

class DaoType
{
public:
    DaoType();
    static QVector<StaffType> getAll();
};

#endif // DAOTYPE_H
