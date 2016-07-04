#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T11:42:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint
TEMPLATE = app

QMAKE_CXXFLAGS = -std=c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    mylabel.cpp \
    brush.cpp \
    linebrush.cpp \
    colorfader.cpp \
    gameoflife.cpp \
    rectanglebrush.cpp \
    circlebrush.cpp

HEADERS  += mainwindow.h \
    image.h \
    mylabel.h \
    brush.h \
    linebrush.h \
    colorfader.h \
    gameoflife.h \
    rectanglebrush.h \
    circlebrush.h

FORMS    += mainwindow.ui
