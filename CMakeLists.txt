cmake_minimum_required (VERSION 3.5)
project (LedController)

# Specify CMake version 3.5 to enable:
#   CMP0028 - Double colon in target name means ALIAS or IMPORTED target.
cmake_policy(VERSION 3.5)

set (LedController_VERSION_MAJOR 0)
set (LedController_VERSION_MINOR 1)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
)

option(COMPILE_TESTS "Compile unit tests" OFF)

if(COMPILE_TESTS)
    # If tests are compiled, the production code links against CppUTest.
    # Find the library before adding any production source code.
    set(CMAKE_PREFIX_PATH "${CPPUTEST_HOME}")
    find_package(CppUTest 3.8 REQUIRED)

    add_subdirectory(tests)
endif(COMPILE_TESTS)

add_subdirectory(libhw_attiny861)
add_subdirectory(src)
add_subdirectory(products)
add_subdirectory(products_libhw_attiny861)
add_subdirectory(products_avr)

message(STATUS "
-------------------------------------------------------
Project options:
    CPPUTEST_HOME:                      ${CPPUTEST_HOME}
    CMAKE_INSTALL_PREFIX:               ${CMAKE_INSTALL_PREFIX}
    CMAKE_PREFIX_PATH:                  ${CMAKE_PREFIX_PATH}
    COMPILE_TESTS:                      ${COMPILE_TESTS}

Compiler options:
    CC:                                 ${CMAKE_C_COMPILER}
    CXX:                                ${CMAKE_CXX_COMPILER}
-------------------------------------------------------"
)
