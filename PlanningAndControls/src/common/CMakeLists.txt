cmake_minimum_required(VERSION 2.8.11)

# generate library for points class 
# and 2d point class. 
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src/common)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(COMMON_LIST point.cpp point2d.cpp space2d.cpp space.cpp)
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

ADD_LIBRARY(common  ${COMMON_LIST} )