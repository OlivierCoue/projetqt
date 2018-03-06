#ifndef CLIENT_H
#define CLIENT_H

#include <QDate>


using namespace std;

class Client
{
private:
    QString lastname;
    QString firstname;
    QString address;
    QString city;
    int postalCode;
    QDate appointmentDate;
    int appointmentLength;
    int priority;
    vector<QString> resourcesIdList;
    QString comment;
    QString phoneNumber;
public:
    Client(QString, QString, QString, QString, int, QDate, int, int, QString, QString);

    bool validate();

    QString getLastname() const;
    void setLastname(const QString &value);
    QString getFirstname() const;
    void setFirstname(const QString &value);
    QString getAddress() const;
    void setAddress(const QString &value);
    QString getCity() const;
    void setCity(const QString &value);
    int getPostalCode() const;
    void setPostalCode(int value);
    QDate getAppointmentDate() const;
    void setAppointmentDate(const QDate &value);
    int getAppointmentLength() const;
    void setAppointmentLength(int value);
    int getPriority() const;
    void setPriority(int value);
    QString getComment() const;
    void setComment(const QString &value);
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
};

#endif // CLIENT_H
