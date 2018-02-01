enable_language(CXX)

add_executable(Test_ATtiny861Gpio
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/mock_io.c"
    "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/src/MockHw_ATtiny861.c"
)
target_include_directories(Test_ATtiny861Gpio PRIVATE "${PROJECT_SOURCE_DIR}/hw_attiny861/mocks/include")

target_link_libraries(Test_ATtiny861Gpio CppUTest ATtiny861::Gpio)
