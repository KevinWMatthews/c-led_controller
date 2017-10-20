enable_language(CXX)

# Link against system CppUTest library
# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

# Link against library of project source code
add_library(LedControllerLib
    "${PROJECT_SOURCE_DIR}/src/Led.c"
)
target_link_libraries(LedControllerLib libCppUTest)
target_include_directories(LedControllerLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
# Do NOT put '-include' inside the double quotes
target_compile_options(LedControllerLib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led.cpp
    "${PROJECT_SOURCE_DIR}/mocks/Mock_LedHw.c"
)
# Do NOT put '-include' inside the double quotes
target_compile_options(Test_LedController PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_LedController libCppUTest LedControllerLib)

install (TARGETS Test_LedController DESTINATION bin)
