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

# Create a Config.h file for this project
# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
    )


#TODO the production code will need to compile hw_attiny861, doesn't it?
# if cross-compiling,
#   build main app
#   link against hw_attiny861 library
# else
#   do not build main app
#   link against mock attiny861 hw
# Both options should build all app tests and hw tests.
# The difference is that the x86 build links against dummy HW.
# Remember that the LedHw app uses mock LedHw while the hw_attiny861 library uses mock registers.
# This is a design decision: should LedHw tests actual registers or should it test function calls
# to set particular pins?

# Tests can currently be compiled for x86_64 and BeagleBoneBlack. The AVR ATtiny861 (actual target) is a work in progress.
# I'd like to remove support for the BBB and focus on x86 and ATtiny861 instead.
if (CMAKE_CROSSCOMPILING)
    add_subdirectory(hw_attiny861)
    add_subdirectory(led_with_button)
else()
    add_subdirectory(tests)
    add_subdirectory(hw_attiny861/tests)        # This will be a separate library in the long run.
endif()

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
