enable_language(CXX)

# Link against system CppUTest library
# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

# Link against library of project source code
add_library(LedControllerLib "${PROJECT_SOURCE_DIR}/src/Led.c")
target_include_directories(LedControllerLib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_executable(Test_LedController RunAllTests.cpp Test_Led.cpp)
target_link_libraries(Test_LedController libCppUTest LedControllerLib)

install (TARGETS Test_LedController DESTINATION bin)
