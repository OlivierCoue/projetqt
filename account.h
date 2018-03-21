#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QWidget>

class Staff;

class Account
{
public:
    Account();
    Account(int, Staff*, QString, QString);
    int getId() const;

    Staff* getStaff();
    void setStaff(Staff* value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    bool validate();
private:
    int id = -1;
    Staff * staff = NULL;
    QString login, password;
};

#endif // ACCOUNT_H
