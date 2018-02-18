add_library(ATtiny861_MockRegisters "")

target_sources(ATtiny861_MockRegisters
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/avr/io.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/avr/interrupt.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/Mock_ATtiny861_Registers.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/src/mock_io.c"
)

target_include_directories(ATtiny861_MockRegisters
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

add_library(ATtiny861::MockRegisters ALIAS ATtiny861_MockRegisters)
