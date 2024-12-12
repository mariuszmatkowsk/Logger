cmake_minimum_required(VERSION 3.27)

project(
    Logger
    VERSION 1.0.0
    DESCRIPTION "Simple Logger library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)

add_subdirectory(include)

option(BUILD_TESTS "Build library tests" ON)
option(BUILD_EXAMPLES "Build example executables" ON)

if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()

install(
    FILES cmake/logger-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/Logger/cmake
)

install(
    EXPORT ${CMAKE_PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/Logger/cmake
)
