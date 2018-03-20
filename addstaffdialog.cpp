#include "addstaffdialog.h"
#include "ui_addstaffdialog.h"

AddStaffDialog::AddStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    // for all types
    //ui->typeBox->addItem(type.getString(), type.getQVariantId());
    currentStaff = new Staff();
}

AddStaffDialog::AddStaffDialog(Staff *staff, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    // for all types
    //ui->typeBox->addItem(type.getString(), type.getQVariantId());
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
    //create new type from ui->typeBox->currentText + id
    //currentStaff->setType(ui->typeBox->currentText());
    if(currentStaff->isDeveloper()) {
        currentStaff->setLogin(ui->login->text());
        currentStaff->setPassword(ui->password->text());
    }
    if(currentStaff->validate())
        accept();
}

void AddStaffDialog::on_typeBox_currentTextChanged(const QString &type)
{
    //currentStaff->setType(ui->typeBox->currentText());
    bool isDev = currentStaff->isDeveloper();
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
   // ui->typeBox->setCurrentIndex(staff.getIndexOfType());
    if(staff.isDeveloper()) {
        ui->login->setText(staff.getLogin());
        ui->login->setText(staff.getPassword());
    }
}
