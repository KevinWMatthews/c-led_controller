cmake_minimum_required (VERSION 2.7.1)
project (LedController)

# Check that CppUTest is installed on the build system
if(DEFINED CPPUTEST_HOME)
    message(STATUS "Using CppUTest found in: ${CPPUTEST_HOME}")
else()
    message(FATAL_ERROR "CPPUTEST_HOME is not set. You must tell CMake where CppUTest is installed.")
endif()

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERISON_MINOR 1)

set (SRC_DIR "src")

# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/Config.h.in"
    "${PROJECT_BINARY_DIR}/Config.h"
    )

# Include the generated config file in the project.
include_directories("${PROJECT_BINARY_DIR}")

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.c)

# Add installation targets
set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install")
install (TARGETS ${PROJECT_NAME} DESTINATION "bin")
install (FILES "${PROJECT_BINARY_DIR}/Config.h" DESTINATION "include")
