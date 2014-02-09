cmake_minimum_required (VERSION 2.8)


PROJECT(GTRIVIP)

FIND_PACKAGE(Qt5 REQUIRED)
INCLUDE(${QT_USE_FILE})

# include GUI QT file in here. 

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})


ADD_EXECUTABLE(MyProject main.cpp MyWidget.cpp ${MOCSrcs} ${UISrcs})
TARGET_LINK_LIBRARIES(MyProject ${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES})



# indicate the subModules source at the below. 
# example like this. 

file(SUB SRC . *.cpp)
add_executable (your_exe_name ${SRC})