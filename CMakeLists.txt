cmake_minimum_required(VERSION 3.5)
project(LedController VERSION 1.0.0)

# Specify CMake version 3.5 to enable:
#   CMP0028 - Double colon in target name means ALIAS or IMPORTED target.
cmake_policy(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CPPUTEST_HOME /usr/local CACHE STRING "Location where CppUTest is installed")
option(COMPILE_TESTS "Compile unit tests" OFF)

if(COMPILE_TESTS)
    # If tests are compiled, the production code links against CppUTest.
    # Find the library before adding any production source code.
    message(STATUS "Searching for CppUTest in CPPUTEST_HOME: ${CPPUTEST_HOME}")
    set(CMAKE_PREFIX_PATH "${CPPUTEST_HOME}")
    find_package(CppUTest 3.8 REQUIRED)

    add_subdirectory(tests)
endif(COMPILE_TESTS)

add_subdirectory(lib/BitManip)
add_subdirectory(lib/ATtiny861)
add_subdirectory(src)
add_subdirectory(products)
add_subdirectory(products_libhw)
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
