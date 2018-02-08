enable_language(CXX)

add_executable(Test_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861Gpio.cpp
    Test_ATtiny861Timer0.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/../mocks/src/MockHw_ATtiny861.c"
)
target_include_directories(Test_ATtiny861 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../mocks/include")

target_link_libraries(Test_ATtiny861 CppUTest ATtiny::861)
