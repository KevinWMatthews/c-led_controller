enable_language(CXX)

add_executable(TestApp_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861_Gpio.cpp
    Test_ATtiny861_GpioMap.cpp
    Test_ATtiny861_Timer0.cpp
    Test_ATtiny861_Interrupt.cpp
    #TODO these belong in a library...
    "${CMAKE_HOME_DIRECTORY}/mocks/Mock_avr_interrupt.cpp"
)

target_include_directories(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/src/ATtiny861"     # Include for testing a private module
)

target_link_libraries(TestApp_ATtiny861
    PRIVATE
        CppUTest
        ATtiny861::ATtiny861
        MockATtiny861::MockATtiny861
        ATtiny861::MockRegisters
        # Regular or mock BitManip? This works but I don't trust it.
        BitManip::BitManip
)

add_test(
    NAME Test_ATtiny861
    COMMAND TestApp_ATtiny861
)
