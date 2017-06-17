
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core)

SET(MY_SRC
  history.cc
  main.cc
  sermanwindow.cc)

ADD_EXECUTABLE(serman
    ${MY_SRCS}
)

target_link_libraries(serman Qt5::Widgets Qt5::Core)

