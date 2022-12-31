cmake_minimum_required(VERSION 3.25)
project(DarkClouds)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

set(srcDir "${PROJECT_SOURCE_DIR}/source")
file(GLOB_RECURSE srcFiles "${srcDir}/*.cpp")

add_library(DC_Lib ${srcFiles})

target_include_directories(DC_Lib PUBLIC /opt/homebrew/Cellar/sdl2/2.26.1/include)
target_link_libraries(DC_Lib PRIVATE SDL2main SDL2)