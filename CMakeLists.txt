cmake_minimum_required(VERSION 3.14)
project(
    test
    VERSION 0.0.1
    LANGUAGES CXX
)


# set(CMAKE_BUILD_TYPE Debug)

# set(LINK_FLAGS "-mwindows -mconsole -Wl,-subsystem,console")

set(CMAKE_PREFIX_PATH C:/Qt/6.8.2/msvc2022_64)

# Qt features support
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt$(QT_VERSION_MAJOR) COMPONENTS Core REQUIRED)

# language features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(sources
   ./main.cpp
)
add_executable(test ${sources})

target_link_libraries(test PRIVATE Qt$(QT_VERSION_MAJOR)::Core)

# set_property(TARGET test PROPERTY WIN32_EXECUTABLE true)
