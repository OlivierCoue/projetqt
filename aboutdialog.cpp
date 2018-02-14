#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QPixmap polytechLogo("C:/Users/JULIEN/Downloads/polytechlogo.png");
    ui->label->setPixmap(polytechLogo.scaled(200,200,Qt::KeepAspectRatio));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
