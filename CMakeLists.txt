cmake_minimum_required(VERSION 3.14)
project(video1
    VERSION 0.0.1
    DESCRIPTION "Access Qt from CMake"
    LANGUAGES CXX)


set(CMAKE_BUILD_TYPE Debug)

set(LINK_FLAGS "-mwindows -mconsole -Wl,-subsystem,console")

# set(QT_INSTALL_PREFIX=C:\Qt\5.12.12\)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.12.12/5.12.12/msvc2017_64")

# Qt features support
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# language features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(sources 
   ./main.cpp
)
add_executable(test WIN32 ${sources})

target_link_libraries(test PRIVATE Qt5::Core ${LINK_FLAGS})

set_property(TARGET test PROPERTY WIN32_EXECUTABLE true)
