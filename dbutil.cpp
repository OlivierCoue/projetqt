#include "dbutil.h"
#include <QDebug>

DbUtil* DbUtil::instance = 0;

DbUtil::DbUtil()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");
    db.setDatabaseName("base_tmp.sqli");
    db.open();
    if(db.isOpen())
        qDebug() << "ca marche";
}

DbUtil *DbUtil::getInstance()
{
   if (instance == 0){
       instance = new DbUtil();
   }
   return instance;
}

void DbUtil::openConnection()
{

}

QSqlDatabase DbUtil::getConnection()
{
    return db;
}

void DbUtil::closeConnection()
{
    db.close();
}
