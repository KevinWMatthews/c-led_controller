enable_language(CXX)

# Link against system CppUTest library
# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

add_library(libCppUTestExt STATIC IMPORTED)
set_property(TARGET libCppUTestExt PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTestExt.a")

# Link against library of project source code
add_library(LedControllerLib
    "${PROJECT_SOURCE_DIR}/src/Led.c"
)
#TODO I'll bet that we'll need this... target_include_directories(Test_LedHwATtiny861 PRIVATE "${CPPUTEST_HOME}/include")
target_link_libraries(LedControllerLib libCppUTest)
target_include_directories(LedControllerLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(LedControllerLib PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
# Do NOT put '-include' inside the double quotes
target_compile_options(LedControllerLib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led.cpp
    "${PROJECT_SOURCE_DIR}/mocks/Mock_LedHw.c"
)
target_include_directories(Test_LedController PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
# Do NOT put '-include' inside the double quotes
target_compile_options(Test_LedController PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedController libCppUTest LedControllerLib)

add_executable(Test_LedHwATtiny861
    RunAllTests.cpp
    Test_LedHwATtiny861.cpp
    "${PROJECT_SOURCE_DIR}/src_hw/LedHw_ATtiny861.c"
    "${PROJECT_SOURCE_DIR}/mocks/Mock_ATtiny861.cpp"
)
target_include_directories(Test_LedHwATtiny861 PRIVATE "${CPPUTEST_HOME}/include")
target_include_directories(Test_LedHwATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/include_hw")
target_include_directories(Test_LedHwATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_compile_options(Test_LedHwATtiny861 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedHwATtiny861 libCppUTest libCppUTestExt LedControllerLib)

install (TARGETS Test_LedController DESTINATION bin)
