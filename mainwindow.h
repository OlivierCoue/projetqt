#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include "addclientdialog.h"
#include "addstaffdialog.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionClient_triggered();

    void on_actionQuitter_triggered();

    void on_actionStaff_triggered();

    void on_actionA_propos_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
