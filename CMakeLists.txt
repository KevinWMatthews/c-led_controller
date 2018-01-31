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

# Create a Config.h file for this project
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
)

add_subdirectory(hw_attiny861/tests)

message(STATUS "
-------------------------------------------------------
Current project options:
    CPPUTEST_HOME:                      ${CPPUTEST_HOME}
    CMAKE_INSTALL_PREFIX:               ${CMAKE_INSTALL_PREFIX}

Current compiler options:
    CC:                                 ${CMAKE_C_COMPILER}
    CXX:                                ${CMAKE_CXX_COMPILER}
-------------------------------------------------------"
)
