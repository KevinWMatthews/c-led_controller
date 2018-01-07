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
add_library(LedControllerTestLib
    "${PROJECT_SOURCE_DIR}/src/LedController.c"
    "${PROJECT_SOURCE_DIR}/src/ButtonObserver.c"
    "${PROJECT_SOURCE_DIR}/src/Led.c"
    "${PROJECT_SOURCE_DIR}/src/Button.c"
)
target_include_directories(LedControllerTestLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(LedControllerTestLib PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_compile_options(LedControllerTestLib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
target_link_libraries(LedControllerTestLib libCppUTest)




add_library(LedControllerTestLib2
    "${PROJECT_SOURCE_DIR}/src_hw/Led_ATtiny861.c"
)
target_include_directories(LedControllerTestLib2 PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_options(LedControllerTestLib2 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
target_link_libraries(LedControllerTestLib2 libCppUTest)

add_executable(Test_Led2
    RunAllTests.cpp
    Test_Led2.cpp
)
target_include_directories(Test_Led2 PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_compile_options(Test_Led2 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_Led2 libCppUTest libCppUTestExt LedControllerTestLib2)
install (TARGETS Test_Led2 DESTINATION bin)


###################################################################
# Create test executable for hardware-independent production code #
###################################################################
# I am not sure if we would rather compile all LedController tests
# into a single executable or if we would rather have separate
# executables for each module.
# At the moment I will use a monolithic executable for hardware-independent
# production code and run tests for a specific module using CppUTest flags:
#   -g <group>      contains group
#   -sg <group>     matches group exactly
#   -lg             print all group names
add_executable(Test_LedController
    RunAllTests.cpp
    Test_LedController.cpp
    Test_ButtonObserver.cpp
    Test_Led.cpp
    Test_Button.cpp
    "${PROJECT_SOURCE_DIR}/mocks/Mock_LedHw.c"
    "${PROJECT_SOURCE_DIR}/mocks/Mock_ButtonHw.c"
)
target_include_directories(Test_LedController PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_include_directories(Test_LedController PRIVATE "${PROJECT_SOURCE_DIR}/mocks")
target_compile_options(Test_LedController PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedController libCppUTest libCppUTestExt LedControllerTestLib)
install (TARGETS Test_LedController DESTINATION bin)

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
target_link_libraries(Test_LedHwATtiny861 libCppUTest libCppUTestExt LedControllerTestLib)
