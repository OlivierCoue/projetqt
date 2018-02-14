#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnConnect_clicked()
{
    if(login(ui->lblLogin->text(), ui->lblPassword->text())) {
        accept();
    }
    else {
        QMessageBox mBox(this);
        mBox.setText("Login ou Mot de passe incorrecte !");
        mBox.show();
    }
}


void LoginDialog::on_btnCancel_clicked()
{
    close();
}

bool LoginDialog::login(QString username, QString password)
{
    if(username.compare("admin") == 0 && password.compare("password") == 0) {
        return true;
    }
    return false;
}
