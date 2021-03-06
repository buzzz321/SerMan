#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T16:25:54
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerMan
TEMPLATE = app


SOURCES += main.cc \
    sermanwindow.cc \
    history.cc \
    communicator.cc \
    fileloader.cc \
    searchdialog.cc \
    util.cc

HEADERS  += \
    sermanwindow.h \
    history.h \
    communicator.h \
    fileloader.h \
    searchdialog.h \
    util.h

FORMS    += \
    sermanwindow.ui \
    search-dialog.ui
