#ifndef ADDSTAFFDIALOG_H
#define ADDSTAFFDIALOG_H

#include <QDialog>

namespace Ui {
class AddStaffDialog;
}

class AddStaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStaffDialog(QWidget *parent = 0);
    ~AddStaffDialog();

private:
    Ui::AddStaffDialog *ui;
};

#endif // ADDSTAFFDIALOG_H
