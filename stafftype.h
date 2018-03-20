#ifndef TYPE_H
#define TYPE_H

#include <QtWidgets>

class StaffType
{
public:
    StaffType();
    StaffType(int id ,QString type);
    QString getString() const;
    QVariant getQVariantId();
    void setString(const QString &value);

    int getId() const;

private:
    void setId(int value);
    int id;
    QString type;
};

#endif // TYPE_H
