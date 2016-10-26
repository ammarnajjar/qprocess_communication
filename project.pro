TARGET = app

TEMPLATE = app
QT += core
QT += concurrent
QT -= gui

CONFIG += c++11

SOURCES += main.cpp \
    cprocess.cpp \
    connector.cpp

HEADERS += \
    cprocess.h \
    connector.h
