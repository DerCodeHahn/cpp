TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fixed_point.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fixed_point.h

