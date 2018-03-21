#ifndef TYPE_H
#define TYPE_H

#include <QtWidgets>

class StaffType
{
public:
    StaffType();
    StaffType(int id ,QString type);
    QString getString();
    QVariant getQVariantId();
    void setString(const QString &value);

    int getId() const;

    bool operator==(const StaffType &staffType) const
    {
        return type == staffType.type;
    }

private:
    void setId(int value);
    int id;
    QString type;
};

#endif // TYPE_H
