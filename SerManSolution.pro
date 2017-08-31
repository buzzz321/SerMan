TEMPLATE = subdirs  
CONFIG+=ordered

SUBDIRS +=  serman Test
CONFIG += c++11 -pthread
LIBS += -pthread

app.depends = serman
tests.depends = serman
