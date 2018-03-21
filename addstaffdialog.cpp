#include "addstaffdialog.h"
#include "ui_addstaffdialog.h"

AddStaffDialog::AddStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    currentStaff = new Staff();
}

AddStaffDialog::AddStaffDialog(Staff *staff, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);
    currentStaff = staff;
    setForm(*staff);
}

AddStaffDialog::~AddStaffDialog()
{
    delete ui;
}

void AddStaffDialog::on_createStaffButton_clicked()
{
    StaffType staffType(ui->typeBox->currentData().toInt(), ui->typeBox->currentText());
    currentStaff->setFirstname(ui->firstname->text());
    currentStaff->setLastname(ui->lastname->text());
    currentStaff->setType(staffType);
    if(currentStaff->isDeveloper()) {
        currentStaff->setLogin(ui->login->text());
        currentStaff->setPassword(ui->password->text());
    }
    if(currentStaff->validate()) {
        if(currentStaff->getId() == -1)
            DaoStaff::save(*currentStaff);
        else
            DaoStaff::update(*currentStaff);
        accept();
    }
}

void AddStaffDialog::on_typeBox_currentTextChanged(const QString &type)
{
    StaffType staffType(ui->typeBox->currentData().toInt(), ui->typeBox->currentText());
    currentStaff->setType(staffType);
    bool isDev = currentStaff->isDeveloper();
    ui->login->setEnabled(isDev);
    ui->password->setEnabled(isDev);
}

void AddStaffDialog::on_cancelButton_clicked()
{
    reject();
}

void AddStaffDialog::showEvent(QShowEvent *event)
{
    QWidget::showEvent( event );
    for(StaffType type : DaoType::getAll())
            ui->typeBox->addItem(type.getString(), type.getQVariantId());
}

void AddStaffDialog::setForm(Staff staff)
{
    ui->firstname->setText(staff.getFirstname());
    ui->lastname->setText(staff.getLastname());
    int index = ui->typeBox->findText(staff.getType().getString(), Qt::MatchFixedString);
    ui->typeBox->setCurrentIndex(index);
    if(staff.isDeveloper()) {
        ui->login->setText(staff.getLogin());
        ui->login->setText(staff.getPassword());
    }
}
