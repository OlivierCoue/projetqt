#include "daoaccount.h"

DaoAccount::DaoAccount()
{

}

int DaoAccount::save(Account account)
{
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if(account.validate()){
        qDebug() <<  "creation du account" << account.getLogin();
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("INSERT INTO [TCompte](IdRessource, Login, MdP) VALUES  (:staff, :login, :password)");
        query.bindValue(":staff", account.getStaff().getId());
        query.bindValue(":login", account.getLogin());
        query.bindValue(":password", account.getPassword());
        query.exec();
    }
}

void DaoAccount::update(Account account)
{
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if(account.validate()){
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("UPDATE [TCompte] SET IdRessource = :staff, Login = :login, MdP = :password) WHERE Id = :id");
        query.bindValue(":id", account.getId());
        query.bindValue(":staff", account.getStaff().getId());
        query.bindValue(":login", account.getLogin());
        query.bindValue(":password", account.getPassword());
        query.exec();
    }
}
