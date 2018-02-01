enable_language(CXX)

set(CMAKE_PREFIX_PATH "${CPPUTEST_HOME}")

find_package(CppUTest 3.8 REQUIRED)

add_executable(Test_ATtiny861Gpio
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
)
target_link_libraries(Test_ATtiny861Gpio CppUTest ATtiny861::Gpio)
target_include_directories(Test_ATtiny861Gpio PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")
