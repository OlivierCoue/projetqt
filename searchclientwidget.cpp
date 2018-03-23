#include "searchclientwidget.h"
#include "ui_searchclientwidget.h"


SearchClientWidget::SearchClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchClientWidget)
{
    ui->setupUi(this);
    this->searchClient();
}

SearchClientWidget::~SearchClientWidget()
{
    delete ui;
}

void SearchClientWidget::on_searchButton_clicked()
{
    this->searchClient();
}

void SearchClientWidget::searchClient()
{
    if(clientListModel != nullptr)
        delete clientListModel;

    clientListModel = DaoClient::search(ui->firstnameInput->text(), ui->lastnameInput->text(), ui->idInput->text().toInt(), ui->appointmentDateStartInput->date(), ui->appointmentDateEndInput->date());
    ui->ClientTableView->setModel(clientListModel);
}

void SearchClientWidget::on_ClientTableView_clicked(const QModelIndex &index)
{
    QModelIndex idIndex(ui->ClientTableView->model()->index(index.row(),0));
    int clientId = ui->ClientTableView->model()->data(idIndex, Qt::DisplayRole).toInt();
    qDebug() << "id client a modifier : " << clientId;
    Client * client = DaoClient::get(clientId);
    AddClientDialog addClientDialog(client, this);
    if(addClientDialog.exec() == QDialog::Accepted) {
        searchClient();
    }
    delete client;
}
