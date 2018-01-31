enable_language(CXX)

set(CMAKE_PREFIX_PATH ${CPPUTEST_HOME})

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
find_package(CppUTest 3.8 REQUIRED)
message(STATUS "CppUTest_FOUND: ${CppUTest_FOUND}")

add_executable(Test_ATtiny861Gpio
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
)
target_link_libraries(Test_ATtiny861Gpio CppUTest)
#target_link_libraries(Test_ATtiny861Gpio CppUTestExt)
#target_include_directories(Test_ATtiny861Gpio PRIVATE ${CPPUTEST_HOME}/include)
