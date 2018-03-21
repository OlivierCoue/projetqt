#include "stafftype.h"

StaffType::StaffType()
{

}

StaffType::StaffType(int id, QString type)
{
    this->id = id;
    this->type = type;
}

QString StaffType::getString()
{
    return type;
}

QVariant StaffType::getQVariantId()
{
    return QVariant(id);
}

void StaffType::setString(const QString &value)
{
    type = value;
}

int StaffType::getId() const
{
    return id;
}

void StaffType::setId(int value)
{
    id = value;
}
