#include "searchclientwidget.h"
#include "ui_searchclientwidget.h"

SearchClientWidget::SearchClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchClientWidget)
{
    ui->setupUi(this);
}

SearchClientWidget::~SearchClientWidget()
{
    delete ui;
}
