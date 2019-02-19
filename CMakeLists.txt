cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)

# Qt
find_package(Qt5Widgets CONFIG REQUIRED)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

INCLUDE_DIRECTORIES(include)
LINK_DIRECTORIES(src)

set(SOURCE_FILES
        src/main.cpp)

add_executable(sysrepo-viewer
        ${SOURCE_FILES})

target_link_libraries(sysrepo-viewer Qt5::Widgets)
