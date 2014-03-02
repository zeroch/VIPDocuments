cmake_minimum_required(VERSION 2.8)

# this is a seperate project for testing purpose 
project(point)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin)
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/../common)
# test demo for Points and space 
SET(point_src main.cpp)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../lib)

add_executable(point ${point_src} )

target_link_libraries(point  common)
