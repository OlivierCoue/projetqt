#ifndef DBUTIL_H
#define DBUTIL_H

#include <QSqlDatabase>

class DbUtil
{
private:
    static DbUtil * instance;
    DbUtil();
    QSqlDatabase db;
public:
    static DbUtil * getInstance();
    void openConnection();
    QSqlDatabase getConnection();
    void closeConnection();
};

#endif // DBUTIL_H
