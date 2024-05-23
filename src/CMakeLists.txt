# Setup the project and settings
project(rayscene C)
set(PROJECT_VERSION 1.0.0)
string(REPLACE "." "" API_VERSION ${PROJECT_VERSION})

include(GNUInstallDirs)
include(JoinPaths)

# Sets build type if not set by now
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    if(RAYLIB_IS_MAIN)
        set(default_build_type Debug)
    else()
        message(WARNING "Default build type is not set (CMAKE_BUILD_TYPE)")
    endif()

    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")

    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(rayscene_headers
    rayscene.h
)

set(rayscene_sources
    rayentity.c
)

add_library(
    rayscene
    ${rayscene_sources}
    ${rayscene_headers}
)

if (NOT BUILD_SHARED_LIBS)
    MESSAGE(STATUS "Building rayscene as a static library/object.")
    add_library(rayscene_static ALIAS rayscene)
else()
    MESSAGE(STATUS "Building rayscene as a shared library.")
    target_compile_definitions(
        rayscene
            PRIVATE $<BUILD_INTERFACE:BUILD_LIBTYPE_SHARED>
            INTERFACE $<INSTALL_INTERFACE:USE_LIBTYPE_SHARED>
    )
endif()

set_target_properties(
    rayscene
    PROPERTIES
        PUBLIC_HEADER "${rayscene_headers}"
        VERSION ${PROJECT_VERSION}
        SOVERSION ${API_VERSION}
)


if (WITH_PIC OR BUILD_SHARED_LIBS)
    set_property(
        TARGET rayscene
        PROPERTY
            POSITION_INDEPENDENT_CODE ON)
endif ()

if (BUILD_SHARED_LIBS)
    # Hide raylib's symbols by default so RLAPI can expose them
    set_property(
        TARGET rayscene
        PROPERTY
            C_VISIBILITY_PRESET "hidden")
endif ()

target_link_libraries(rayscene raylib)

# Registering include directories
target_include_directories(
    rayscene
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Copy the header files to the build directory for convenience
file(COPY ${rayscene_headers} DESTINATION "include")

# Includes information on how the library will be installed on the system
# when cmake --install is run
include(InstallConfigurations)
