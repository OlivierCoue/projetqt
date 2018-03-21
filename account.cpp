#include "staff.h"
#include "account.h"

Account::Account()
{

}

Account::Account(int id, Staff* staff, QString login, QString password)
{
    this->id = id;
    setStaff(staff);
    setLogin(login);
    setPassword(password);
}

int Account::getId() const
{
    return id;
}

QString Account::getPassword() const
{
    return password;
}

void Account::setPassword(const QString &value)
{
    password = value;
}

bool Account::validate()
{
    if(staff == nullptr || login == nullptr || password == nullptr)
        return false;
    return true;
}

QString Account::getLogin() const
{
    return login;
}

void Account::setLogin(const QString &value)
{
    login = value;
}

Staff* Account::getStaff()
{
    return staff;
}

void Account::setStaff(Staff* value)
{
    staff = value;
}
