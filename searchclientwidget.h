#ifndef SEARCHCLIENTWIDGET_H
#define SEARCHCLIENTWIDGET_H

#include <QWidget>

namespace Ui {
class SearchClientWidget;
}

class SearchClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchClientWidget(QWidget *parent = 0);
    ~SearchClientWidget();

private:
    Ui::SearchClientWidget *ui;
};

#endif // SEARCHCLIENTWIDGET_H
