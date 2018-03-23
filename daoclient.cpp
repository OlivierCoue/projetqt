#include "daoclient.h"

DaoClient::DaoClient()
{

}

QSqlQueryModel *DaoClient::search(QString firstname, QString lastname, int id, QDate start, QDate end)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if((firstname.isNull() || firstname.trimmed().isEmpty()) && (lastname.isNull() || lastname.trimmed().isEmpty())  && id <= 0){
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("SELECT Id, Nom, Prenom, DateRdv FROM [TClient]");
        query.exec();
        model->setQuery(query);
    }else{
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("SELECT Id, Nom, Prenom, DateRdv FROM [TClient] WHERE [Nom]=:nom OR [Prenom]=:prenom OR [Id]=:id AND [DateRdv] BETWEEN :start AND :end");
        query.bindValue(":nom", lastname);
        query.bindValue(":prenom", firstname);
        query.bindValue(":id", id);
        query.bindValue(":start", start);
        query.bindValue(":end", end);
        query.exec();
        model->setQuery(query);
    }

    return model;

}

void DaoClient::save(Client client)
{
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if(client.validate()){
        qDebug() <<  "creation du client" << client.getFirstname();
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("INSERT INTO [TClient](Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) VALUES  (:lastname, :firstname, :address, :city, :postalCode, :comment, :phoneNumber, :appointmentDate, :appointmentLength, :priority)");
        query.bindValue(":firstname", client.getFirstname());
        query.bindValue(":lastname", client.getLastname());
        query.bindValue(":address", client.getAddress());
        query.bindValue(":city", client.getCity());
        query.bindValue(":postalCode", client.getPostalCode());
        query.bindValue(":comment", client.getComment());
        query.bindValue(":phoneNumber", client.getPhoneNumber());
        query.bindValue(":appointmentDate", client.getAppointmentDate());
        query.bindValue(":appointmentLength", client.getAppointmentLength());
        query.bindValue(":priority", client.getPriority());
        query.exec();
    }

}

void DaoClient::update(Client client)
{
    if(DbUtil::getInstance()->getConnection().isOpen())
        qDebug() <<  "ca re marche";

    if(client.validate()){
        qDebug() <<  "creation du client" << client.getFirstname();
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("UPDATE [TClient]SET Nom = :lastname, Prenom = :firstname, Adresse = :address, Ville = :city, CP = :postalCode, Commentaire = :comment, Tel = :phoneNumber, DateRdv = :appointmentDate, DureeRdv = :appointmentLength, Priorite = :priority WHERE Id = :id");
        query.bindValue(":id", client.getId());
        query.bindValue(":firstname", client.getFirstname());
        query.bindValue(":lastname", client.getLastname());
        query.bindValue(":address", client.getAddress());
        query.bindValue(":city", client.getCity());
        query.bindValue(":postalCode", client.getPostalCode());
        query.bindValue(":comment", client.getComment());
        query.bindValue(":phoneNumber", client.getPhoneNumber());
        query.bindValue(":appointmentDate", client.getAppointmentDate());
        query.bindValue(":appointmentLength", client.getAppointmentLength());
        query.bindValue(":priority", client.getPriority());
        query.exec();
    }
}

Client * DaoClient::get(int index)
{
    QSqlQuery query(DbUtil::getInstance()->getConnection());
    query.prepare("SELECT * FROM [TClient] WHERE Id = :id");
    query.bindValue(":id", index);
    query.exec();
    query.next();
    Client * client = new Client(
        query.value(0).toInt(),    // id
        query.value(2).toString(), // firstname
        query.value(1).toString(), // lastname
        query.value(3).toString(), // address
        query.value(4).toString(), // city
        query.value(5).toInt(),    // postalCode
        query.value(8).toDate(),   // appointmentDate
        query.value(9).toInt(),    // appointmentLength
        query.value(10).toInt(),   // priority
        query.value(6).toString(), // comment
        query.value(7).toString()  // phoneNumber
        );
    return client;

}

