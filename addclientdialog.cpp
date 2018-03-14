#include "addclientdialog.h"
#include "ui_addclientdialog.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    currentClient = new Client();
}

AddClientDialog::AddClientDialog(Client *client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    currentClient = client;
    setForm(*client);
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

void AddClientDialog::on_createClientButton_clicked()
{
    currentClient->setFirstname(ui->firstname->text());
    currentClient->setLastname(ui->lastname->text());
    currentClient->setAddress(ui->address->text());
    currentClient->setCity(ui->city->text());
    currentClient->setPostalCode(ui->postalCode->text().toInt());
    currentClient->setAppointmentDate(ui->appointmentDate->date());
    currentClient->setAppointmentLength(ui->appointmentLength->text().toInt());
    currentClient->setPriority(ui->priority->text().toInt());
    currentClient->setComment(ui->comment->text());
    currentClient->setPhoneNumber(ui->phoneNumber->text());

    if(currentClient->validate())
        accept();
}

void AddClientDialog::on_cancelButton_clicked()
{
    reject();
}

void AddClientDialog::setForm(Client client)
{
    ui->createClientButton->setText("Modify client");
    ui->firstname->setText(client.getFirstname());
    ui->lastname->setText(client.getLastname());
    ui->address->setText(client.getAddress());
    ui->city->setText(client.getCity());
    ui->postalCode->setText(QString::number(client.getPostalCode()));
    ui->appointmentDate->setDate(client.getAppointmentDate());
    ui->appointmentLength->setText(QString::number(client.getAppointmentLength()));
    ui->priority->setText(QString::number(client.getPriority()));
    ui->comment->setText(client.getComment());
    ui->phoneNumber->setText(client.getPhoneNumber());
}
