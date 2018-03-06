#include "staff.h"

staff::staff()
{

}

QString staff::getFirstname() const
{
    return firstname;
}

void staff::setFirstname(const QString &value)
{
    firstname = value;
}

QString staff::getLastname() const
{
    return lastname;
}

void staff::setLastname(const QString &value)
{
    lastname = value;
}

staff::Type staff::getType() const
{
    return type;
}

void staff::setType(const staff::Type &value)
{
    type = value;
}

QString staff::getLogin() const
{
    if(type == DEVELOPER)
        return login;
}

void staff::setLogin(const QString &value)
{
    if(type == DEVELOPER)
        login = value;
}

QString staff::getPassword() const
{
    if(type == DEVELOPER)
        return password;
}

void staff::setPassword(const QString &value)
{
    if(type == DEVELOPER)
        password = value;
}
