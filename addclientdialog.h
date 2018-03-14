#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QTextStream>

#include "client.h"

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0);
    explicit AddClientDialog(Client *client, QWidget *parent = 0);
    ~AddClientDialog();

private slots:
    void on_createClientButton_clicked();

    void on_cancelButton_clicked();

private:
    void setForm(Client client);
    Client * currentClient;
    Ui::AddClientDialog *ui;
};

#endif // ADDCLIENTDIALOG_H
