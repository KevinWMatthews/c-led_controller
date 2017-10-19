enable_language(CXX)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Add CppUTest library
include_directories("${CPPUTEST_HOME}/include")
# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

add_executable("Test_LedController" RunAllTests.cpp Test_LedController.cpp)
target_link_libraries("Test_LedController" libCppUTest)

install (TARGETS "Test_LedController" DESTINATION "bin")
