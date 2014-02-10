cmake_minimum_required(VERSION 2.8)

PROJECT(hello)
add_subdirectory(src bin)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

#set(CMAKE_PREFIX_PATH $ENV{QT_DIR})
