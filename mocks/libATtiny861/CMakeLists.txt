add_library(MockATtiny861Registers
    src/Mock_ATtiny861_Registers.c
)

target_include_directories(MockATtiny861Registers
    PUBLIC
        include
)

add_library(MockATtiny861Registers::MockATtiny861Registers ALIAS MockATtiny861Registers)



add_library(MockATtiny861Interrupt
    src/Mock_avr_interrupt.cpp
)

target_include_directories(MockATtiny861Interrupt
    PRIVATE
        include
)

target_link_libraries(MockATtiny861Interrupt
    PRIVATE
        CppUTest
        CppUTestExt
)

add_library(MockATtiny861Interrupt::MockATtiny861Interrupt ALIAS MockATtiny861Interrupt)
