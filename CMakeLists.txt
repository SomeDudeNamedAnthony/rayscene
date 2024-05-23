cmake_minimum_required(VERSION 3.0.0...3.5.0)
project(rayscene)

# Avoid excessive expansion of variables in conditionals. In particular, if
# "PLATFORM" is "DRM" then:
#
# if (${PLATFORM} MATCHES "DRM")
#
# may expand e.g to:
#
# if (/usr/lib/aarch64-linux-gnu/libdrm.so MATCHES "DRM")
#
# See https://cmake.org/cmake/help/latest/policy/CMP0054.html
cmake_policy(SET CMP0054 NEW)

# Makes a hidden visibility preset on a static lib respected
# This is used to hide glfw's symbols from the library exports when building an so/dylib
# See https://cmake.org/cmake/help/latest/policy/CMP0063.html
cmake_policy(SET CMP0063 NEW)

# Directory for easier includes
# Anywhere you see include(...) you can check <root>/cmake for that file
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# Sets compiler flags and language standard
include(CompilerFlags)

# Registers build options that are exposed to cmake
include(${CMAKE_CURRENT_LIST_DIR}/CMakeOptions.cmake)

# RAYLIB_IS_MAIN determines whether the project is being used from root
# or if it is added as a dependency (through add_subdirectory for example).
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  set(RAYSCENE_IS_MAIN ON)
else()
  set(RAYSCENE_IS_MAIN OFF)
endif()

#Ensure that raylib is install.
if(NOT MY_RAYLIB)
    find_package(raylib QUIET)
    if (NOT raylib_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 5.0
            GIT_SHALLOW 1
        )
        FetchContent_MakeAvailable(raylib)
    endif()
else()
    find_package(raylib REQUIRED)
endif()

# Main sources directory (the second parameter sets the output directory name to raylib)
add_subdirectory(src rayscene)

if (${BUILD_EXAMPLES})
  MESSAGE(STATUS "Building examples is enabled")
  add_subdirectory(examples)
endif()
