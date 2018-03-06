#-------------------------------------------------
#
# Project created by QtCreator 2018-02-08T11:13:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    ressource.cpp \
    staff.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    addclientdialog.h \
    addstaffdialog.h \
    aboutdialog.h \
    client.h \
    clientcontroller.h \
    searchclientwidget.h \
    ressource.h \
    staff.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    addclientdialog.ui \
    addstaffdialog.ui \
    aboutdialog.ui \
    searchclientwidget.ui
