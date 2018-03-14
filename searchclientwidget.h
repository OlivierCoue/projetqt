#ifndef SEARCHCLIENTWIDGET_H
#define SEARCHCLIENTWIDGET_H

#include <QWidget>
#include <QVector>

#include "daoclient.h"
#include "client.h"

namespace Ui {
class SearchClientWidget;
}

class SearchClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchClientWidget(QWidget *parent = 0);
    ~SearchClientWidget();

private slots:
    void on_searchButton_clicked();

private:
    Ui::SearchClientWidget *ui;
    QSqlQueryModel * clientListModel;
    void searchClient();
};

#endif // SEARCHCLIENTWIDGET_H
