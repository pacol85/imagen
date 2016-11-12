#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T06:37:07
#
#-------------------------------------------------

QT       += core gui
QT        += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imagen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filedownloader.cpp

HEADERS  += mainwindow.h \
    filedownloader.h

FORMS    += mainwindow.ui
