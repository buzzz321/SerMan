set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core)
find_package (Qt5Network)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

foreach(plugin ${Qt5Network_PLUGINS})
  get_target_property(_loc ${plugin} LOCATION)
  message("Plugin ${plugin} is at location ${_loc}")
endforeach()

SET(MY_SRCS
  communicator.cc
  fileloader.cc
  main.cc
  searchdialog.cc
  sermanwindow.cc
  util.cc
  history.cc)

ADD_EXECUTABLE(serman "${MY_SRCS}")

target_link_libraries(serman Qt5::Widgets Qt5::Core Qt5::Network)
