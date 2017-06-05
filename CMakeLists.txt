cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(serman)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_SUBDIRECTORY(QtTest)
ADD_SUBDIRECTORY(Test)

#find_package(Qt4 REQUIRED)
#add_executable(subscriber subscriber.cpp)
#target_link_libraries(subscriber Qt4::QtGui Qt4::QtDBus)
