TEMPLATE = subdirs  
CONFIG+=ordered

SUBDIRS +=  QtTest Test
CONFIG += c++11

app.depends = QtTest
tests.depends = QtTest
