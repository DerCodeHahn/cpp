#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T11:42:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    mylabel.cpp

HEADERS  += mainwindow.h \
    image.h \
    mylabel.h

FORMS    += mainwindow.ui
