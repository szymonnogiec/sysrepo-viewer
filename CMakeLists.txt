cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)
# Qt
find_package(Qt5Widgets CONFIG REQUIRED)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# sysrepo project

ExternalProject_Add(
        sysrepo
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/sysrepo"
        CMAKE_ARGS -DCMAKE_BUILD_TYPE=Debug ..
        INSTALL_COMMAND sudo make install
)

INCLUDE_DIRECTORIES(include)
LINK_DIRECTORIES(src)
set(SOURCE_FILES
        src/main.cpp
        src/SysrepoConnector.cpp
        )

add_executable(sysrepo-viewer
        ${SOURCE_FILES})

add_dependencies(sysrepo-viewer sysrepo)
target_link_libraries(sysrepo-viewer Qt5::Widgets)