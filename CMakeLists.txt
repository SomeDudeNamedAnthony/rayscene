cmake_minimum_required(VERSION 3.14...3.50)
project(
  Stager
  VERSION 1.0.0
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES C CXX)

set(STAGER_TARGET "Stager")
set(STAGER_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/Source)
set(STAGER_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/Include/Stager)

set(STAGER_SOURCES
    ${STAGER_INCLUDE_DIR}/Exceptions/DuplicateStageException.hh
    ${STAGER_INCLUDE_DIR}/Exceptions/NonExistentStageException.hh
    ${STAGER_INCLUDE_DIR}/Costume.hh
    ${STAGER_INCLUDE_DIR}/Stage.hh
    ${STAGER_INCLUDE_DIR}/Theatre.hh
    ${STAGER_INCLUDE_DIR}/Actor.hh
    ${STAGER_SOURCE_DIR}/Stage.cc
    ${STAGER_SOURCE_DIR}/Actor.cc
    ${STAGER_SOURCE_DIR}/Costume.cc
    ${STAGER_SOURCE_DIR}/Theatre.cc)

add_library(${STAGER_TARGET} INTERFACE)
add_library(${STAGER_TARGET}::${STAGER_TARGET} ALIAS ${STAGER_TARGET})

target_sources(${STAGER_TARGET} INTERFACE ${STAGER_SOURCES})
target_include_directories(${STAGER_TARGET} INTERFACE ${STAGER_INCLUDE_DIR}/../)
set_target_properties(
  ${STAGER_TARGET}
  PROPERTIES C_STANDARD 17
             C_STANDARD_REQUIRED ON
             C_EXTENSIONS ON
             CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/playground)
endif()
