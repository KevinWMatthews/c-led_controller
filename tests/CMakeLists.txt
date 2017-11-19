enable_language(CXX)

# Memory leak detection:
#   The production code library needs to include MemoryLeakDetectorMallocMacros.h.
#   The test code executdable needs to include MemoryLeakDetectorNewMacros.h.
#   When directly including CppUTests's memory leak detection files, do NOT put '-include' inside double quotes.

# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)

# set_property(TARGET <target> PROPERTY <property> <value>)
# TARGET means we will operate on a target, not a directory or source file.



#############################
# Set up CppUTest libraries #
#############################
# Link against system CppUTest library for unit tests
add_library(libCppUTest STATIC IMPORTED)
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

# Link against system CppUTestExt library for mock support
add_library(libCppUTestExt STATIC IMPORTED)
set_property(TARGET libCppUTestExt PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTestExt.a")



##########################################################
# Create library of hardware-independent production code #
##########################################################
# This enables us to use link-time substitution to swap in mock hardware modules.
add_library(LedControllerLib
    "${PROJECT_SOURCE_DIR}/src/Led.c"
)
target_include_directories(LedControllerLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(LedControllerLib PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_compile_options(LedControllerLib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
target_link_libraries(LedControllerLib libCppUTest)



###################################################################
# Create test executable for hardware-independent production code #
###################################################################
add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led.cpp
    "${PROJECT_SOURCE_DIR}/mocks/Mock_LedHw.c"
)
target_include_directories(Test_LedController PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_compile_options(Test_LedController PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedController libCppUTest LedControllerLib)



#######################################################
# Create test executable for hardware interface layer #
#######################################################
add_executable(Test_LedHwATtiny861
    RunAllTests.cpp
    Test_LedHwATtiny861.cpp
    "${PROJECT_SOURCE_DIR}/src_hw/LedHw_ATtiny861.c"
    "${PROJECT_SOURCE_DIR}/mocks/Mock_ATtiny861.cpp"
)
target_include_directories(Test_LedHwATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_include_directories(Test_LedHwATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_compile_options(Test_LedHwATtiny861 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedHwATtiny861 libCppUTest libCppUTestExt LedControllerLib)
