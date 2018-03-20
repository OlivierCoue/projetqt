#include "account.h"

Account::Account()
{

}

Account::Account(Staff staff, QString login, QString password)
{
    setStaff(staff);
    setLogin(login);
    setPassword(password);
}

int Account::getId() const
{
    return id;
}

void Account::setId(int value)
{
    id = value;
}

QString Account::getPassword() const
{
    return password;
}

void Account::setPassword(const QString &value)
{
    password = value;
}

QString Account::getLogin() const
{
    return login;
}

void Account::setLogin(const QString &value)
{
    login = value;
}

Staff Account::getStaff() const
{
    return staff;
}

void Account::setStaff(const Staff &value)
{
    staff = value;
}
