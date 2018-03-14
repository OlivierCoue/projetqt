#include "addstaffdialog.h"
#include "ui_addstaffdialog.h"

AddStaffDialog::AddStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    ui->typeBox->addItems(QStringList::fromVector(Staff::getAllTypes()));
    currentStaff = new Staff();
}

AddStaffDialog::AddStaffDialog(Staff *staff, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    ui->typeBox->addItems(QStringList::fromVector(Staff::getAllTypes()));
    currentStaff = staff;
    setForm(*staff);
}

AddStaffDialog::~AddStaffDialog()
{
    delete ui;
}

void AddStaffDialog::on_createStaffButton_clicked()
{
    currentStaff->setFirstname(ui->firstname->text());
    currentStaff->setLastname(ui->lastname->text());
    currentStaff->setType(ui->typeBox->currentText());
    if(ui->typeBox->currentText() == Staff::DEVELOPER) {
        currentStaff->setLogin(ui->login->text());
        currentStaff->setPassword(ui->password->text());
    }
    if(currentStaff->validate())
        accept();
}

void AddStaffDialog::on_typeBox_currentTextChanged(const QString &type)
{
    bool isDev = type == Staff::DEVELOPER;
    ui->login->setEnabled(isDev);
    ui->password->setEnabled(isDev);
}

void AddStaffDialog::on_cancelButton_clicked()
{
    reject();
}

void AddStaffDialog::setForm(Staff staff)
{
    ui->firstname->setText(staff.getFirstname());
    ui->lastname->setText(staff.getLastname());
    ui->typeBox->setCurrentIndex(staff.getIndexOfType());
    if(staff.getType() == Staff::DEVELOPER) {
        ui->login->setText(staff.getLogin());
        ui->login->setText(staff.getPassword());
    }
}
