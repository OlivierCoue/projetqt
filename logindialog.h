#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_btnConnect_clicked();

    void on_btnCancel_clicked();

private:
    Ui::LoginDialog *ui;

    bool login(QString username, QString password);
};

#endif // LOGINDIALOG_H
