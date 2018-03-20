#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QWidget>

#include "staff.h"

class Account
{
public:
    Account();
    Account(Staff staff, QString login, QString password);
    int getId() const;

    Staff getStaff() const;
    void setStaff(const Staff &value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private:
    void setId(int value);
    int id;
    Staff staff;
    QString login, password;
};

#endif // ACCOUNT_H
