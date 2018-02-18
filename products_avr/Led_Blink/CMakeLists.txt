if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "hw_attiny861 products must be cross compiled!")
endif()

set(Avr_Led_Blink_VERSION_MAJOR 1)
set(Avr_Led_Blink_VERSION_MINOR 0)
set(Avr_Led_Blink_VERSION_PATCH 0)

configure_file (
    Avr_Led_Blink_Config.h.in
    Avr_Led_Blink_Config.h
)

set (target Avr_Led_Blink)

add_executable(${target}
    Led_Blink.c
)

target_include_directories(${target}
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")
