enable_language(CXX)

add_executable(TestApp_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861_Gpio.cpp
    Test_ATtiny861_GpioMap.cpp
    Test_ATtiny861_Timer0.cpp
    Test_ATtiny861_Interrupt.cpp
    #TODO these belong in a library...
    "${CMAKE_HOME_DIRECTORY}/mocks/Mock_ATtiny861_Timer0.cpp"
    "${CMAKE_HOME_DIRECTORY}/mocks/Mock_avr_interrupt.cpp"
)

target_include_directories(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/src/ATtiny861"     # Include for testing a private module
        "${CMAKE_HOME_DIRECTORY}/mocks"
        "${CMAKE_HOME_DIRECTORY}/mocks/include"
)

target_link_libraries(TestApp_ATtiny861
    PRIVATE
        CppUTest
        CppUTestExt
        ATtiny861::ATtiny861
        ATtiny861::MockRegisters
        BitManip::BitManip
)

add_test(
    NAME Test_ATtiny861
    COMMAND TestApp_ATtiny861
)
