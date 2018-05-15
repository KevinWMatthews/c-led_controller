add_library(MockHw_ATtiny861
    src/Mock_ATtiny861_Registers.c
)

target_include_directories(MockHw_ATtiny861
    PUBLIC
        include
)

add_library(MockHw_ATtiny861::MockHw_ATtiny861 ALIAS MockHw_ATtiny861)



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
