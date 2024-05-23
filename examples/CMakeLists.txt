project(example)

find_package(raylib REQUIRED)

# Collect all source files and resource files
# into a CMake variable
set(example_sources )

# Get the .c files
file(GLOB example_sources ${CMAKE_CURRENT_LIST_DIR}/*.c)

if (NOT TARGET rayscene)
    find_package(rayscene REQUIRED)
endif ()

# Do each example
foreach (example_source ${example_sources})
    # Create the basename for the example
    get_filename_component(example_name ${example_source} NAME)
    string(REPLACE ".c" "" example_name ${example_name})

    # Setup the example
    add_executable(${example_name} ${example_source})

    target_link_libraries(${example_name} raylib rayscene)
    if (NOT WIN32)
        target_link_libraries(${example_name} m)
    endif()
endforeach ()
