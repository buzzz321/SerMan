#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T16:25:54
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerMan
TEMPLATE = app


SOURCES += main.cc \
    sermanwindow.cc \
    history.cc

HEADERS  += \
    sermanwindow.h \
    history.h

FORMS    += \
    sermanwindow.ui
