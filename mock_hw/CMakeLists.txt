add_library(MockATtiny861Registers
    src/Mock_ATtiny861_Registers.c
)

target_include_directories(MockATtiny861Registers
    PUBLIC
        include
)

add_library(MockATtiny861Registers::MockATtiny861Registers ALIAS MockATtiny861Registers)



add_library(MockAvrInterrupt
    src/Mock_avr_interrupt.cpp
)

target_include_directories(MockAvrInterrupt
    PRIVATE
        include
)

target_link_libraries(MockAvrInterrupt
    PRIVATE
        CppUTest
        CppUTestExt
)

add_library(MockAvrInterrupt::MockAvrInterrupt ALIAS MockAvrInterrupt)
