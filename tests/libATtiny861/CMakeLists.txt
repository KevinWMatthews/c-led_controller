enable_language(CXX)

add_executable(Test_ATtiny861
    RunAllTests.cpp
    Test_ATtiny861_Gpio.cpp
    Test_ATtiny861_GpioMap.cpp
    Test_ATtiny861_Timer0.cpp
    Test_ATtiny861_Interrupt.cpp
)

target_include_directories(Test_ATtiny861
    PRIVATE
        # Non-standard include for testing a private module.
        # This smells funny...
        "${CMAKE_HOME_DIRECTORY}/src/libATtiny861"
)

target_link_libraries(Test_ATtiny861
    PRIVATE
        CppUTest
        ATtiny861::ATtiny861
        MockATtiny861Registers::MockATtiny861Registers
        MockATtiny861Interrupt::MockATtiny861Interrupt
        # Regular or mock BitManip? This works but I don't trust it.
        BitManip::BitManip
)

add_test(
    NAME Test_ATtiny861
    COMMAND Test_ATtiny861
)
