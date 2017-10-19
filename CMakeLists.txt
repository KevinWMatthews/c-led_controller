cmake_minimum_required (VERSION 2.7.1)
project (LedController)

# Check that CppUTest is installed on the build system
if(DEFINED CPPUTEST_HOME)
    message(STATUS "Using CppUTest found in: ${CPPUTEST_HOME}")
else()
    message(FATAL_ERROR "CPPUTEST_HOME is not set. You must tell CMake where CppUTest is installed.")
endif()

set (LedController_VERSION_MAJOR 0)
set (LedController_VERISON_MINOR 1)

# Add installation targets
set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install")

add_subdirectory(src)
add_subdirectory(tests)
