TEMPLATE = subdirs  
CONFIG+=ordered

SUBDIRS +=  serman Test
CONFIG += c++11

app.depends = serman
tests.depends = serman
