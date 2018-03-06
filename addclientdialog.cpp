#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "client.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

void AddClientDialog::on_createClientButton_clicked()
{
    Client client(this->ui->firstname->text(),
                  this->ui->lastname->text(),
                  this->ui->address->text(),
                  this->ui->city->text(),
                  this->ui->postalCode->text().toInt(),
                  this->ui->appointmentDate->date(),
                  this->ui->appointmentLength->text().toInt(),
                  this->ui->priority->text().toInt(),
                  this->ui->comment->text(),
                  this->ui->phoneNumber->text()
                  );

    if(client.validate())
        accept();

}

void AddClientDialog::on_cancelButton_clicked()
{
    reject();
}
