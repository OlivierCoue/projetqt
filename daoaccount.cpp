#include "daoaccount.h"

DaoAccount::DaoAccount()
{

}

int DaoAccount::search(QString login, QString password)
{
    QSqlQuery query(DbUtil::getInstance()->getConnection());
    query.prepare("SELECT Id FROM [TCompte] WHERE [Login]=:login OR [MdP]=:password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
    query.next();
    return query.value(0).toInt();
}
