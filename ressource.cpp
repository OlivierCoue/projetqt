#include "ressource.h"

ressource::ressource()
{

}

QString ressource::getFirstname() const
{
    return firstname;
}

void ressource::setFirstname(const QString &value)
{
    firstname = value;
}

QString ressource::getLastname() const
{
    return lastname;
}

void ressource::setLastname(const QString &value)
{
    lastname = value;
}
