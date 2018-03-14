#include "daoclient.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include "dbutil.h"

DaoClient::DaoClient()
{

}

QSqlQueryModel *DaoClient::search(QString firstname, QString lastname)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if((firstname.isNull() || firstname.trimmed().isEmpty()) && (lastname.isNull() || lastname.trimmed().isEmpty())){
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("SELECT Id, Nom, Prenom, DateRdv FROM [TClient]");
        model->setQuery(query);
    }else{
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("SELECT Id, Nom, Prenom, DateRdv FROM [TClient] WHERE [Nom]=:nom OR [Prenom]=:prenom");
        query.bindValue(":nom", lastname);
        query.bindValue(":prenom", firstname);
        query.exec();
        model->setQuery(query);
    }

    return model;

}

