#include "daostaff.h"

DaoStaff::DaoStaff()
{

}

void DaoStaff::save(Staff staff)
{
    int staffId;
    if(staff.validate()){
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("INSERT INTO [TRessource](Nom, Prenom, IdType) VALUES  (:lastname, :firstname, :type)");
        query.bindValue(":firstname", staff.getFirstname());
        query.bindValue(":lastname", staff.getLastname());
        query.bindValue(":type", staff.getType().getId());
        query.exec();
        staffId = query.lastInsertId().toInt();
        if(staff.isDeveloper()) {
            query.prepare("INSERT INTO [TCompte](IdRessource, Login, MdP) VALUES  (:staff, :login, :password)");
            query.bindValue(":staff", staffId);
            query.bindValue(":login", staff.getLogin());
            query.bindValue(":password", staff.getPassword());
            query.exec();
        }
    }
}

void DaoStaff::update(Staff staff)
{
    if(staff.validate()){
        QSqlQuery query(DbUtil::getInstance()->getConnection());
        query.prepare("UPDATE [TRessource] SET Nom = :lastname, Prenom = :firstname, IdType = :type WHERE Id = :id");
        query.bindValue(":id", staff.getId());
        query.bindValue(":firstname", staff.getFirstname());
        query.bindValue(":lastname", staff.getLastname());
        query.bindValue(":type", staff.getType().getId());
        query.exec();
        if(staff.isDeveloper()) {
            query.prepare("UPDATE [TCompte] SET Login = :login, MdP = :password WHERE IdRessource = :staff");
            query.bindValue(":staff", staff.getId());
            query.bindValue(":login", staff.getLogin());
            query.bindValue(":password", staff.getPassword());
            query.exec();
        }
    }
}

QSqlQueryModel * DaoStaff::getAll()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DbUtil::getInstance()->getConnection());
    query.prepare("SELECT Id, Nom, Prenom, IdType FROM [TRessource]");
    query.exec();
    model->setQuery(query);
    return model;
}
