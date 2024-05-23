include(CMakeDependentOption)

option(WITH_PIC "Build with positional independent code." ON)
option(BUILD_EXAMPLES "Allows for customization of the library." ON)
option(BUILD_SHARED_LIBS "Build as a shared library." ON)
option(MY_RAYLIB "Force use host's raylib instead of bundling it." OFF)
