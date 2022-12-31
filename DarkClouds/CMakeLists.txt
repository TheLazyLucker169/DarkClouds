cmake_minimum_required(VERSION 3.25)
project(DarkClouds)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(srcDir "${PROJECT_SOURCE_DIR}/source")
file(GLOB_RECURSE srcFiles "${srcDir}/*.cpp")

add_executable(DarkClouds ${srcFiles})

target_include_directories(DarkClouds PUBLIC ../DC_Lib/source)
target_link_libraries(DarkClouds PRIVATE DC_Lib)