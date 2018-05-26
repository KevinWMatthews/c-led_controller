project(Avr_Led_Blink VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

configure_file (
    Avr_Led_Blink_Config.h.in
    Avr_Led_Blink_Config.h
)

add_executable(Avr_Led_Blink
    Led_Blink.c
)

target_include_directories(Avr_Led_Blink
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Avr_Led_Blink)
