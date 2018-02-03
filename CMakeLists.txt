cmake_minimum_required (VERSION 3.5)
project (LedController)

# Specify CMake version 3.5 to enable:
#   CMP0028 - Double colon in target name means ALIAS or IMPORTED target.
cmake_policy(VERSION 3.5)

set (LedController_VERSION_MAJOR 0)
set (LedController_VERSION_MINOR 1)

# Specify where files are installed
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# Create a header file with project information
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
)

# Enable project options
option(COMPILE_TESTS "Compile unit tests" OFF)

# Search for libraries
if(COMPILE_TESTS)
    set(CMAKE_PREFIX_PATH "${CPPUTEST_HOME}")
    message(STATUS ${CMAKE_PREFIX_PATH})
    find_package(CppUTest 3.8 REQUIRED)
endif(COMPILE_TESTS)

# Add subdirectories
# Compile source code libraries
add_subdirectory(hw_attiny861)

# Compile unit tests
if(COMPILE_TESTS)
    add_subdirectory(hw_attiny861/tests)
endif(COMPILE_TESTS)

# Create executables
# Cross-compilation only until/unless I get the build straightened out.
if(CMAKE_CROSSCOMPILING)
add_subdirectory(hw_attiny861/products/pin_a0_high)
add_subdirectory(hw_attiny861/products/pin_a1_high)
endif(CMAKE_CROSSCOMPILING)

message(STATUS "
-------------------------------------------------------
Project options:
    CPPUTEST_HOME:                      ${CPPUTEST_HOME}
    CMAKE_INSTALL_PREFIX:               ${CMAKE_INSTALL_PREFIX}
    COMPILE_TESTS:                      ${COMPILE_TESTS}

Compiler options:
    CC:                                 ${CMAKE_C_COMPILER}
    CXX:                                ${CMAKE_CXX_COMPILER}
-------------------------------------------------------"
)
