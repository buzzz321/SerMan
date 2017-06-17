#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T21:30:15
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../serman

SOURCES += tst_testtest.cc
SOURCES += ../serman/history.cc

DEFINES += SRCDIR=\\\"$$PWD/\\\"
