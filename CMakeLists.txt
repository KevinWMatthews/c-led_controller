cmake_minimum_required (VERSION 2.7.1)
project (LedController)

# Check that CppUTest is installed on the build system
if(NOT DEFINED CPPUTEST_HOME)
    message(FATAL_ERROR "CPPUTEST_HOME is not set. You must tell CMake where CppUTest is installed.")
endif()

set (LedController_VERSION_MAJOR 0)
set (LedController_VERSION_MINOR 1)

# Add installation targets
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(src)

# Tests can currently be compiled for x86_64 and BeagleBoneBlack. The AVR ATtiny861 (actual target) is a work in progress.
add_subdirectory(tests)
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
