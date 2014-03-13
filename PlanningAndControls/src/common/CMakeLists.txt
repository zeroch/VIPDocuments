cmake_minimum_required(VERSION 2.8.11)

message("Configure Common Lib")
# generate library for points class 
# and 2d point class. 
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
link_directories(${Qt5Gui_LIBRARIES} ${Qt5Widgets_LIBRARIES})

set(space_SOURCE space2d.cpp)
set(space_HEADER space2d.h)
Qt5_WRAP_CPP(space_HEADER_MOCS ${space_HEADER})

set(COMMON_LIST point.cpp point2d.cpp  space.cpp path.cpp astar.cpp algorithm.cpp)

ADD_LIBRARY(common  ${COMMON_LIST} ${space_SOURCE} ${space_HEADER} ${space_HEADER_MOCS})
target_link_libraries(common ${Qt5Gui_LIBRARIES})
