enable_language(CXX)

add_executable(Test_ATtiny861Gpio
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/../mocks/src/mock_io.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../mocks/src/MockHw_ATtiny861.c"
)
target_include_directories(Test_ATtiny861Gpio PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../mocks/include")

target_link_libraries(Test_ATtiny861Gpio CppUTest ATtiny861::Gpio)
