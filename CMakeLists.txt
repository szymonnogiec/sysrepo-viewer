cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# set additional search path for ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/ui)
# Qt
find_package(Qt5Widgets CONFIG REQUIRED)

INCLUDE_DIRECTORIES(include)
LINK_DIRECTORIES(src)

set(HEADER_FILES
        include/MainWindow.h
        include/SysrepoConnector.h
        include/Util.h
        include/SysrepoViewer.h include/FormData.h)

set(SOURCE_FILES
        src/main.cpp
        src/MainWindow.cpp
        src/SysrepoConnector.cpp
        src/Util.cpp src/SysrepoViewer.cpp src/FormData.cpp)

add_executable(sysrepo-viewer
        ${HEADER_FILES}
        ${SOURCE_FILES})

target_link_libraries(sysrepo-viewer
        Qt5::Widgets
        Sysrepo-cpp)