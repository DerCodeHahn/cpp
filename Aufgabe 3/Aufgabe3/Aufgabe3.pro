TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PayloadPP.cpp

HEADERS += \
    my_vector.h \
    ringbuffer.h
