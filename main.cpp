#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QDebug>
#include "dbutil.h"
#include "c_init_bd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    C_INIT_BD::Creation_BD();
    LoginDialog d;
    MainWindow w ;

    if(d.exec()==QDialog::Accepted)
    {    
        w.show();
        return a.exec();
    }

    return 0;
}
