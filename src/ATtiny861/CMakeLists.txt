project(ATtiny861 VERSION 1.0.0)

# Some IDEs require listing header files here
add_library(ATtiny861
    ATtiny861_Gpio.c
    ATtiny861_GpioMap.h
    ATtiny861_GpioMap.c
    ATtiny861_Timer0.c
    ATtiny861_Interrupt.c
)

target_include_directories(ATtiny861
    PUBLIC
        "${CMAKE_HOME_DIRECTORY}/include/ATtiny861"
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}/include"
)
if(COMPILE_TESTS)
    # Override production header files !!
    # This allows us to create macros that simulate chip behavior during bitwise operations.
    target_include_directories(ATtiny861
        BEFORE PRIVATE
            "${CMAKE_HOME_DIRECTORY}/mocks/BitManip"
    )
endif()


target_link_libraries(ATtiny861
    PRIVATE
        BitManip::BitManip
)
if(NOT CMAKE_CROSSCOMPILING)
    target_link_libraries(ATtiny861
        PRIVATE
        ATtiny861::MockRegisters
    )
endif()
if(COMPILE_TESTS)
    target_link_libraries(ATtiny861
        PRIVATE
            CppUTest
    )
endif()


if(CMAKE_CROSSCOMPILING)
    # Add AVR-specific compiler and linker flags
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS ${AVR_LINK_FLAGS}
    )
endif(CMAKE_CROSSCOMPILING)
if(COMPILE_TESTS)
    # Set flag to enable CppUTest's memory leak detection
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
    )
endif(COMPILE_TESTS)

add_library(ATtiny861::ATtiny861 ALIAS ATtiny861)
