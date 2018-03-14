#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QtWidgets>

class ressource
{
public:
    ressource();

    QString getFirstname() const;
    void setFirstname(const QString &value);

    QString getLastname() const;
    void setLastname(const QString &value);

private:
    QString firstname, lastname;
};

#endif // RESSOURCE_H
