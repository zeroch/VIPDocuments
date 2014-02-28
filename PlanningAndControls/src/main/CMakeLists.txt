cmake_minimum_required(VERSION 2.8.11)


message(STATUS ${QTDIR})
# QT_Dir configure. 
if (DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
    message(${CMAKE_PREFIX_PATH})
    MESSAGE(STATUS "HELLE")

elseif (DEFINED QTDIR)
    MESSAGE(STATUS "HELLOE")
    set(CMAKE_PREFIX_PATH ${QTDIR} ${CMAKE_PREFIX_PATH})
    message(STATUS ${CMAKE_PREFIX_PATH})
else ()
    message(STATUS ${CMAKE_PREFIX_PATH})

endif()


# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


SET(INC_DIR ${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDES} ${Qt5Widgets_INCLUDES} ${INC_DIR})
# linking dir
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

# src and header
SET(kitten_SOURCE main.cpp mainwindow.cpp)
SET(kitten_HEADER mainwindow.h)

#MOC wrapper
QT5_WRAP_CPP(kitten_HEADER_MOCS ${kitten_HEADER})

ADD_EXECUTABLE(kitten ${kitten_SOURCE} ${kitten_HEADER} ${kitten_HEADER_MOCS})

TARGET_LINK_LIBRARIES(kitten  ${Qt5Widgets_LIBRARIES})
