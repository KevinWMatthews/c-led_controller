enable_language(CXX)

# Create target for system CppUTest library
# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")


# Create target for ATtiny861 hardware library.
# Link against mock hardware - the tests refer to mock registers, and these must be defined.
add_library(ATtiny861Lib
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861.c"
)
target_include_directories(ATtiny861Lib PUBLIC "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_include_directories(ATtiny861Lib PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
target_compile_options(ATtiny861Lib PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")

add_executable(Test_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861.cpp
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/MockHw_ATtiny861.c"
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/io.c"
)
target_include_directories(Test_ATtiny861 PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
target_include_directories(Test_ATtiny861 PRIVATE "${CPPUTEST_HOME}/include")
target_compile_options(Test_ATtiny861 PRIVATE -include "${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
target_link_libraries(Test_ATtiny861 libCppUTest ATtiny861Lib)
