cmake_minimum_required(VERSION 3.25)
project(DarkClouds)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(srcDir "${PROJECT_SOURCE_DIR}/source")
file(GLOB_RECURSE srcFiles "${srcDir}/*.cpp")

add_executable(DC_Test ${srcFiles})

target_include_directories(DC_Test PUBLIC ../DC_Lib/source)
target_link_libraries(DC_Test PRIVATE DC_Lib)

enable_testing()

add_test(
    NAME Test_Initialization
    COMMAND DC_Test Init
)

add_test(
    NAME Test_Window
    COMMAND DC_Test Window
)