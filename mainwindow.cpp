#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->showMessage(tr("Vous venez de vous connecter"));

    searchClientWidget = new SearchClientWidget(this);
    visualizeStaffWidget = new VisualizeStaffWidget(this);
    this->ui->tabWidget->addTab(searchClientWidget, "Rechercher client");
    this->ui->tabWidget->addTab(visualizeStaffWidget, "Visualiser ressources");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    AddClientDialog addClientDialog(this);
    if(addClientDialog.exec() == QDialog::Accepted) {
        searchClientWidget->searchClient();
    }
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionStaff_triggered()
{
    AddStaffDialog addStaffDialog(this);
    if(addStaffDialog.exec() == QDialog::Accepted) {
        visualizeStaffWidget->updateTreeView();
    }
}

void MainWindow::on_actionA_propos_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}
