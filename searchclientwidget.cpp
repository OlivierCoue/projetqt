#include "searchclientwidget.h"
#include "ui_searchclientwidget.h"

#include <QSqlQueryModel>

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

    clientListModel = DaoClient::search(ui->firstnameInput->text(), ui->lastnameInput->text());
    ui->ClientTableView->setModel(clientListModel);
}
