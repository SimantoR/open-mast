cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(FitsJS)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

#* --------------------------- zlib configuration --------------------------- *#
set(ZLIB_FOUND TRUE CACHE BOOL "Build shared libraries" FORCE)
set(ZLIB_LIBRARY zlibstatic CACHE STRING "Name of zlib target" FORCE)
set(ZLIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/zlib ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/zlib CACHE STRING "Include directory for ZLIB" FORCE)

MESSAGE(STATUS ${ZLIB_INCLUDE_DIR})
#* -------------------------------------------------------------------------- *#

set(CMAKE_VERBOSE_MAKEFILE on)

include_directories(include)

add_subdirectory(3rdparty)
add_subdirectory(src)

