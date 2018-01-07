#TODO eventually this layer could become its own library.

enable_language(CXX)

#TODO this is duplicated...
#############################
# Set up CppUTest libraries #
#############################
# Link against system CppUTest library for unit tests
add_library(libCppUTest STATIC IMPORTED)
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")



########################################################
# Create library of hardware interface production code #
########################################################
# Create target for ATtiny861 hardware library. Tests only!
# When compiling for x86, link against mock hardware header files. The tests refer to memory registers, and these must be mocked.
# When compiling for ATtiny, the header files are included with the toolchain. Do not use this library.
add_library(ATtiny861TestLib
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861.c"
)
target_include_directories(ATtiny861TestLib PUBLIC "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_include_directories(ATtiny861TestLib PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
target_compile_options(ATtiny861TestLib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")



#################################################################
# Create test executable for hardware interface production code #
#################################################################
add_executable(Test_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861.cpp
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/MockHw_ATtiny861.c"
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/mock_io.c"
)
target_include_directories(Test_ATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
target_compile_options(Test_ATtiny861 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_ATtiny861 libCppUTest ATtiny861TestLib)
