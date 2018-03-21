#ifndef SEARCHCLIENTWIDGET_H
#define SEARCHCLIENTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QSqlQueryModel>

#include "daoclient.h"
#include "client.h"
#include "addclientdialog.h"

namespace Ui {
class SearchClientWidget;
}

class SearchClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchClientWidget(QWidget *parent = 0);
    void searchClient();
    ~SearchClientWidget();

private slots:
    void on_searchButton_clicked();

    void on_ClientTableView_clicked(const QModelIndex &index);

private:
    Ui::SearchClientWidget *ui;
    QSqlQueryModel * clientListModel = NULL;
};

#endif // SEARCHCLIENTWIDGET_H
