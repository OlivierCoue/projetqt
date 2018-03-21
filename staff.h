#ifndef STAFF_H
#define STAFF_H

#include <QtWidgets>

#include "stafftype.h"

#include "daotype.h"

class Staff
{

public:
    Staff();
    Staff(int id,QString firstname, QString lastname,StaffType type, QString login, QString password);

    int getId() const;

    QString getFirstname() const;
    void setFirstname(const QString &value);

    QString getLastname() const;
    void setLastname(const QString &value);

    StaffType getType();
    void setType(StaffType &value);

    bool isDeveloper();

    bool validate();

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private:
    void setId(int value);
    int id = -1;
    QString firstname, lastname;
    StaffType type;
    QString login, password;
};

#endif // STAFF_H
