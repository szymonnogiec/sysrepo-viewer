cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
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

include_directories(include)
link_directories(src)

enable_testing()
add_subdirectory(test)

set(HEADER_FILES
        include/Connector.h
        include/DaemonStateMonitor.h
        include/FormData.h
        include/MainWindow.h
        include/ModulesLister.h
        include/SysrepoViewer.h
        include/Util.h
        )

set(SOURCE_FILES
        src/Connector.cpp
        src/DaemonStateMonitor.cpp
        src/FormData.cpp
        src/main.cpp
        src/MainWindow.cpp
        src/ModulesLister.cpp
        src/SysrepoViewer.cpp
        src/Util.cpp
        )

add_executable(sysrepo-viewer
        ${HEADER_FILES}
        ${SOURCE_FILES})

target_link_libraries(sysrepo-viewer
        pthread
        Qt5::Widgets
        Sysrepo-cpp)