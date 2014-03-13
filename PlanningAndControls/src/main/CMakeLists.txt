cmake_minimum_required(VERSION 2.8.11)

message("configure Main Gui")
# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(${Qt5Core_INCLUDES} ${Qt5Widgets_INCLUDES})
# linking dir
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

# src and header
SET(kitten_SOURCE main.cpp mainwindow.cpp)
SET(kitten_HEADER mainwindow.h)
message("debug: ${Qt5Widgets_LIBRARIES}")

#MOC wrapper
QT5_WRAP_CPP(kitten_HEADER_MOCS ${kitten_HEADER})

ADD_EXECUTABLE(kitten ${kitten_SOURCE} ${kitten_HEADER} ${kitten_HEADER_MOCS})

TARGET_LINK_LIBRARIES(kitten  ${Qt5Widgets_LIBRARIES})
