#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T22:43:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimplePaint
TEMPLATE = app

QMAKE_CXXFLAGS = -std=c++14 -stdlib=libc++
QMAKE_LFLAGS   = -stdlib=libc++

SOURCES +=        \
   main.cpp       \
   mylabel.cpp    \
   image.cpp      \
   mainwindow.cpp \

HEADERS +=        \
   mylabel.h      \
   image.h        \
   mainwindow.h   \
