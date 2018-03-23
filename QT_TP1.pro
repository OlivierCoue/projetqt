#-------------------------------------------------
#
# Project created by QtCreator 2018-02-08T11:13:48
#
#-------------------------------------------------

QT       += core gui \
    sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = QT_TP1
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    addclientdialog.cpp \
    addstaffdialog.cpp \
    aboutdialog.cpp \
    client.cpp \
    clientcontroller.cpp \
    searchclientwidget.cpp \
    c_init_bd.cpp \
    daoclient.cpp \
    dbutil.cpp \
    ressource.cpp \
    staff.cpp \
    stafftype.cpp \
    daotype.cpp \
    daostaff.cpp \
    visualizestaffwidget.cpp \
    daoaccount.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    addclientdialog.h \
    addstaffdialog.h \
    aboutdialog.h \
    client.h \
    clientcontroller.h \
    searchclientwidget.h \
    c_init_bd.h \
    daoclient.h \
    dbutil.h \
    ressource.h \
    stafftype.h \
    staff.h \
    daotype.h \
    daostaff.h \
    visualizestaffwidget.h \
    daoaccount.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    addclientdialog.ui \
    addstaffdialog.ui \
    aboutdialog.ui \
    searchclientwidget.ui \
    visualizestaffwidget.ui
