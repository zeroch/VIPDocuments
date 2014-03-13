cmake_minimum_required(VERSION 2.8)
#This project is for the purpose of developing unit tests
project(unitTests)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(unitTests_src alltests.cpp)
#CPP UNIT
#setting cmake module path for cppunit cmake
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(CPPUNIT REQUIRED)

include_directories(${CPPUNIT_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/../common ${CPPUNIT_INCLUDE_DIR})

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../lib ${CPPUNIT_LIBRARIES})
add_executable(unitTests ${unitTests_src})

target_link_libraries(unitTests common ${CPPUNIT_LIBRARIES})
