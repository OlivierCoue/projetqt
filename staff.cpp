#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(int id, QString firstname, QString lastname, StaffType type, QString login = nullptr, QString password = nullptr)
{
    setId(id);
    setFirstname(firstname);
    setLastname(lastname);
    setType(type);
    setLogin(login);
    setPassword(password);
}

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
    return login;
}

void Staff::setLogin(const QString &value)
{
    login = value;
}

QString Staff::getPassword() const
{
    return password;
}

void Staff::setPassword(const QString &value)
{
    password = value;
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

    /*if(!getAllTypes().contains(type))
        return false;*/

    if(isDeveloper())
        if(login.isEmpty() || password.isEmpty())
            return false;
    return true;
}

void Staff::setId(int value)
{
    id = value;
}

StaffType Staff::getType() const
{
    return type;
}

void Staff::setType(const StaffType &value)
{
    type = value;
}

int Staff::getId() const
{
    return id;
}


bool Staff::isDeveloper()
{
    bool isDeveloper;
    if(type.getString() == "Informaticien")
        isDeveloper = true;
    else
        isDeveloper = false;
    return isDeveloper;
}
