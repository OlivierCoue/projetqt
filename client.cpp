#include "client.h"
#include <QException>

Client::Client()
{
}

Client::Client(QString firstname,
               QString lastname,
               QString address,
               QString city,
               int postalCode,
               QDate appointmentDate,
               int appointmentLength,
               int priority,
               QString comment = nullptr,
               QString phoneNumber = nullptr)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->address = address;
    this->city = city;
    this->postalCode = postalCode;
    this->appointmentDate = appointmentDate;
    this->appointmentLength = appointmentLength;
    this->priority = priority;
    this->comment = comment;
    this->phoneNumber = phoneNumber;
}

bool Client::validate()
{
    if(firstname == nullptr)
        return false;
    firstname = firstname.toLower();
    firstname[0] = firstname[0].toUpper();

    if(lastname == nullptr)
        return false;
    lastname = lastname.toLower();
    lastname[0] = lastname[0].toUpper();

    if(address == nullptr)
        return false;

    if(city == nullptr)
        return false;
    city = city.toLower();
    city[0] = city[0].toUpper();

    QDate now = QDate::currentDate();
    if(appointmentDate < now)
        return false;

    if(priority < 1 || priority > 5)
        return false;

    return true;
}

QString Client::getFirstname() const
{
    return firstname;
}

void Client::setFirstname(const QString &value)
{
    firstname = value;
}

QString Client::getAddress() const
{
    return address;
}

void Client::setAddress(const QString &value)
{
    address = value;
}

QString Client::getCity() const
{
    return city;
}

void Client::setCity(const QString &value)
{
    city = value;
}

int Client::getPostalCode() const
{
    return postalCode;
}

void Client::setPostalCode(int value)
{
    postalCode = value;
}

QDate Client::getAppointmentDate() const
{
    return appointmentDate;
}

void Client::setAppointmentDate(const QDate &value)
{
    appointmentDate = value;
}

int Client::getAppointmentLength() const
{
    return appointmentLength;
}

void Client::setAppointmentLength(int value)
{
    appointmentLength = value;
}

int Client::getPriority() const
{
    return priority;
}

void Client::setPriority(int value)
{
    priority = value;
}

QString Client::getComment() const
{
    return comment;
}

void Client::setComment(const QString &value)
{
    comment = value;
}

QString Client::getPhoneNumber() const
{
    return phoneNumber;
}

void Client::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
}

QString Client::getLastname() const
{
    return lastname;
}

void Client::setLastname(const QString &value)
{
    lastname = value;
}
