cmake_minimum_required (VERSION 2.7.1)
project (LedController)

# Check that CppUTest is installed on the build system
if(NOT DEFINED CPPUTEST_HOME)
    message(FATAL_ERROR "CPPUTEST_HOME is not set. You must tell CMake where CppUTest is installed.")
endif()

set (LedController_VERSION_MAJOR 0)
set (LedController_VERSION_MINOR 1)

# Add installation targets
set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install")          # overrides user options!
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(src)

# For now, use this to compile tests only on the local PC.
# In the long run, we'll want to be able to cross-compile tests for,
# say, a BeagleBone Black. However, this is a lot to figure out.
#if (${CMAKE_CROSSCOMPILING} STREQUAL "FALSE")
add_subdirectory(tests)
add_subdirectory(hw_attiny861/tests)
#endif()

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
