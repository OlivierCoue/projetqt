#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->showMessage(tr("window opened"));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    AddClientDialog addClientDialog(this);
    addClientDialog.exec();
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionStaff_triggered()
{
    AddStaffDialog addStaffDialog(this);
    addStaffDialog.exec();
}

void MainWindow::on_actionA_propos_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}
