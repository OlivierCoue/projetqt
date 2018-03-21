#ifndef ADDSTAFFDIALOG_H
#define ADDSTAFFDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QDebug>

#include "daotype.h"
#include "daostaff.h"
#include "staff.h"

namespace Ui {
class AddStaffDialog;
}

class AddStaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStaffDialog(QWidget *parent = 0);
    explicit AddStaffDialog(Staff *staff, QWidget *parent = 0);
    ~AddStaffDialog();

private slots:

    void on_createStaffButton_clicked();

    void on_typeBox_currentTextChanged(const QString &arg1);

    void on_cancelButton_clicked();

    void showEvent( QShowEvent* event );

private:
    void setForm(Staff staff);
    Staff * currentStaff;
    Ui::AddStaffDialog *ui;
};

#endif // ADDSTAFFDIALOG_H
