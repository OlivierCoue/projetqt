#ifndef STAFF_H
#define STAFF_H

class staff
{

public:
    staff();
    QString getFirstname() const;
    void setFirstname(const QString &value);

    QString getLastname() const;
    void setLastname(const QString &value);

    Type getType() const;
    void setType(const Type &value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private:
    enum Type {
        BANKER_A,
        BANKER_B,
        INSURER_HOUSING,
        INSURER_CAR,
        INSURER_LIFE,
        DEVELOPER,
        MISCELLANEOUS
    } type;
    QString firstname, lastname;
    QString login, password;
};

#endif // STAFF_H
