#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(QString firstname, QString lastname, QString type)
{
    setFirstname(firstname);
    setLastname(lastname);
    setType(type);
}

Staff::Staff(QString firstname, QString lastname, QString login, QString password)
{
    setFirstname(firstname);
    setLastname(lastname);
    setType(DEVELOPER);
    setLogin(login);
    setPassword(password);
}

const QString Staff::BANKER_A = "Banquier type A";
const QString Staff::BANKER_B = "Banquier type B";
const QString Staff::INSURER_HOUSING = "Assureur maison";
const QString Staff::INSURER_CAR = "Assureur voiture";
const QString Staff::INSURER_LIFE = "Assureur vie";
const QString Staff::DEVELOPER = "Programmeur";
const QString Staff::MISCELLANEOUS = "Divers";

QString Staff::getFirstname() const
{
    return firstname;
}

void Staff::setFirstname(const QString &value)
{
    firstname = value;
}

QString Staff::getLastname() const
{
    return lastname;
}

void Staff::setLastname(const QString &value)
{
    lastname = value;
}

QString Staff::getLogin() const
{
    if(type == DEVELOPER)
        return login;
    else
        throw QException();
}

void Staff::setLogin(const QString &value)
{
    if(type == DEVELOPER)
        login = value;
    else
        throw QException();
}

QString Staff::getPassword() const
{
    if(type == DEVELOPER)
        return password;
    else
        throw QException();
}

void Staff::setPassword(const QString &value)
{
    if(type == DEVELOPER)
        password = value;
    else
        throw QException();
}

QString Staff::getType() const
{
    return type;
}

void Staff::setType(const QString &value)
{
    type = value;
    if(value == DEVELOPER) {
        login = "";
        password = "";
    }
}

bool Staff::validate()
{
    if(firstname.isEmpty())
        return false;
    firstname = firstname.toLower();
    firstname[0] = firstname[0].toUpper();

    if(lastname.isEmpty())
        return false;
    lastname = lastname.toLower();
    lastname[0] = lastname[0].toUpper();

    if(!getAllTypes().contains(type))
        return false;

    if(type == DEVELOPER)
        if(login.isEmpty() || password.isEmpty())
            return false;
    return true;
}

int Staff::getIndexOfType()
{
    int i;
    QVector<QString> typeList = getAllTypes();
    for(i = 0; i < typeList.length(); i++) {
        if(type == typeList[i])
            return i;
    }
    return -1;
}

QVector<QString> Staff::getAllTypes()
{
    QVector<QString> typeList(0);
    typeList.append(BANKER_A);
    typeList.append(BANKER_B);
    typeList.append(INSURER_HOUSING);
    typeList.append(INSURER_CAR);
    typeList.append(INSURER_LIFE);
    typeList.append(DEVELOPER);
    typeList.append(MISCELLANEOUS);
    return typeList;
}
