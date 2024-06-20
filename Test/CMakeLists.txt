cmake_minimum_required(VERSION 3.14...3.50)
project(playground)

find_package(SDL2 REQUIRED)
add_executable(app main.cpp)
target_link_libraries(app PRIVATE Stager::Stager SDL2)
set_target_properties(
  app
  PROPERTIES C_STANDARD 17
             C_STANDARD_REQUIRED ON
             C_EXTENSIONS ON
             CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS ON)
