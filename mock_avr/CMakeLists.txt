add_library(ATtiny861_MockRegisters
    src/Mock_ATtiny861_Registers.c
)

target_include_directories(ATtiny861_MockRegisters
    PUBLIC
        include
)

add_library(ATtiny861::MockRegisters ALIAS ATtiny861_MockRegisters)
