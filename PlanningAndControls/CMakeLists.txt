cmake_minimum_required(VERSION 2.8.11)
# project name
PROJECT(kitten)
# add sub dir
add_subdirectory(src bin)

# Instruct CMake to run moc automatically when needed.
# turn it off, incase multi_moc generated. 
# set(CMAKE_AUTOMOC ON)


# Configuring build type
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "Debug" CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
    MESSAGE("Setting build type to '${CMAKE_BUILD_TYPE}'")
ELSE(NOT CMAKE_BUILD_TYPE)
    MESSAGE("Build type set to '${CMAKE_BUILD_TYPE}'")
ENDIF(NOT CMAKE_BUILD_TYPE)

