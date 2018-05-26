project(Avr_Led_BlinkTwo VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

configure_file (
    Avr_Led_BlinkTwo_Config.h.in
    Avr_Led_BlinkTwo_Config.h
)

add_executable(Avr_Led_BlinkTwo
    Led_BlinkTwo.c
)

target_include_directories(Avr_Led_BlinkTwo
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Avr_Led_BlinkTwo)
