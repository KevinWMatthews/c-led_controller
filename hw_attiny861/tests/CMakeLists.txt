#TODO eventually this layer could become its own library.

enable_language(CXX)

#TODO this is duplicated...
#############################
# Set up CppUTest libraries #
#############################
# Link against CppUTest library for unit tests
# Searches in CMAKE_MODULE_PATH, which is intended to be pass from the command line using -D
find_package(CppUTest 3.8 REQUIRED)
# Does it find the system library or the one that I compiled? How can I/should I check?
#message(STATUS "CppUTest_FOUND: ${CppUTest_FOUND}")



########################################################
# Create library of hardware interface production code #
########################################################
# Create target for ATtiny861 hardware library. Tests only!
# When compiling for x86, link against mock hardware header files. The tests refer to memory registers, and these must be mocked.
# When compiling for ATtiny, the header files are included with the toolchain. Do not use this library.
#add_library(ATtiny861Test
#    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio.c"
#    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio_map.c"
#    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/mock_io.c"
#)
#target_include_directories(ATtiny861Test PUBLIC "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
#target_include_directories(ATtiny861Test PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
#target_link_libraries(ATtiny861Test CppUTest)
#target_compile_options(ATtiny861Test PRIVATE -include "${CMAKE_MODULE_PATH}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")



#################################################################
# Create test executable for hardware interface production code #
#################################################################
add_executable(Test_ATtiny861Gpio
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
    #"${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/MockHw_ATtiny861.c"
)
#target_include_directories(Test_ATtiny861Gpio PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
#??
#target_compile_options(Test_ATtiny861Gpio PRIVATE -include "${CMAKE_MODULE_PATH}/include/CppUTest/MemoryLeakDetectorNewMacros.h")
#target_link_libraries(Test_ATtiny861Gpio CppUTest ATtiny861Test)
target_link_libraries(Test_ATtiny861Gpio CppUTest)
