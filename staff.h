#ifndef STAFF_H
#define STAFF_H

#include <QtWidgets>
#include <QVector>

class Staff
{

public:
    Staff();
    Staff(QString firstname, QString lastname, QString type);
    Staff(QString firstname, QString lastname, QString login, QString password);

    QString getFirstname() const;
    void setFirstname(const QString &value);

    QString getLastname() const;
    void setLastname(const QString &value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    bool validate();

    int getIndexOfType();
    static QVector<QString> getAllTypes();

    static const QString BANKER_A;
    static const QString BANKER_B;
    static const QString INSURER_HOUSING;
    static const QString INSURER_CAR;
    static const QString INSURER_LIFE;
    static const QString DEVELOPER;
    static const QString MISCELLANEOUS;
private:
    QString firstname, lastname;
    QString type;
    QString login, password;
};

#endif // STAFF_H
