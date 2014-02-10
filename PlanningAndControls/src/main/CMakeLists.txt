cmake_minimum_required(VERSION 2.8)


# Find the QtWidgets library
#find_package(Qt5Widgets)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

SET(SRC_LIST main.cpp)


MESSAGE(STATUS "This is BINARY dir " ${PROJECT_SOURCE_DIR})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)


ADD_EXECUTABLE(hello ${SRC_LIST})

TARGET_LINK_LIBRARIES(hello util)

# Use the Widgets module from Qt 5.
#qt5_use_modules(hello Widgets)




