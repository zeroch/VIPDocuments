cmake_minimum_required(VERSION 2.8.11)
# QT_Dir configure.
if (DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
    message(${CMAKE_PREFIX_PATH})
    MESSAGE(STATUS "HELLE")

elseif (DEFINED QTDIR)
    MESSAGE(STATUS "HELLO")
    set(CMAKE_PREFIX_PATH ${QTDIR} ${CMAKE_PREFIX_PATH})
    message(STATUS ${CMAKE_PREFIX_PATH})
else ()
    message(STATUS ${CMAKE_PREFIX_PATH})

endif()
add_subdirectory(main)
add_subdirectory(util)
add_subdirectory(common)
#add_subdirectory(tests)
