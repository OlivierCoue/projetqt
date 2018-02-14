#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog d;
    MainWindow w ;

    if(d.exec()==QDialog::Rejected)
    {
        w.show();
        return a.exec();
    }
    return 0;

}
