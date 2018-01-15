
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Test)

SET(MY_SRC
    tst_testtest.cc
    )

ADD_EXECUTABLE(historytests "${MY_SRCS}" )

target_link_libraries(historytests Qt5::Test)

