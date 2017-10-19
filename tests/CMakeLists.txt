set (TEST_SRC_LIST RunAllTests.cpp Test_LedController.cpp)
set (TEST_EXECUTABLE_NAME "Test_${PROJECT_NAME}")

enable_language(CXX)

include_directories("${PROJECT_SOURCE_DIR}/${INC_DIR}")
include_directories("${CPPUTEST_HOME}/include")

# add_library(<name> <STATIC | SHARED | MODULE> IMPORTED)
add_library(libCppUTest STATIC IMPORTED)
# TARGET means we will operate on a target, not a directory or source file
set_property(TARGET libCppUTest PROPERTY IMPORTED_LOCATION "${CPPUTEST_HOME}/lib/libCppUTest.a")

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SRC_LIST})
target_link_libraries(${TEST_EXECUTABLE_NAME} libCppUTest)

install (TARGETS ${TEST_EXECUTABLE_NAME} DESTINATION ${BIN_DIR})
