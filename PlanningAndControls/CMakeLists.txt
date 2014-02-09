cmake_minimum_required (VERSION 2.8)


PROJECT(GTRIVIP)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)


# include GUI QT file in here. 

#ADD_EXECUTABLE(MyProject main.cpp MyWidget.cpp ${MOCSrcs} ${UISrcs})
#TARGET_LINK_LIBRARIES(MyProject ${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES})


# Library 
# 
#if (USE_LIB)
#  include_directories ("${PROJECT_SOURCE_DIR}/SubModule")
#  add_subdirectory (MathFunctions)
#  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#endif (USE_MYMATH)
# Tell CMake to create the helloworld executable
add_executable(helloworld main.cpp)
 


# indicate the subModules source at the below. 
# example like this. 

#file(SUB SRC . *.cpp)
#add_executable (your_exe_name ${SRC})

# Use the Widgets module from Qt 5.
qt5_use_modules(helloworld Widgets)
