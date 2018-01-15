cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(serman)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

#find_package(Qt5Widgets)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_SUBDIRECTORY(serman)
ADD_SUBDIRECTORY(Test)

#find_package(Qt4 REQUIRED)
#add_executable(subscriber subscriber.cpp)
#target_link_libraries(subscriber Qt4::QtGui Qt4::QtDBus)
