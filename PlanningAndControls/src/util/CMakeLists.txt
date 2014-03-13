cmake_minimum_required(VERSION 2.8.11)

# this is a seperate project for testing purpose 
project(point)

message("Configure Test Points")
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/../common)
# test demo for Points and space 
SET(point_src main.cpp)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../../lib)

add_executable(point ${point_src} )

target_link_libraries(point  common  ${Qt5Gui_LIBRARIES})
