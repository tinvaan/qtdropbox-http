project(dropbox-api-test)
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_MIN_VERSION "5.5.0")

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS Core Network)

option(BUILD_TESTS "Build the tests and examples" OFF)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
