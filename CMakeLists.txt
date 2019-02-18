cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(include)
LINK_DIRECTORIES(src)

set(SOURCE_FILES
        src/main.cpp)

add_executable(sysrepo-viewer
        ${SOURCE_FILES})