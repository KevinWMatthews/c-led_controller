project(Avr_Led_BlinkSixteen VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

configure_file(
    Avr_Led_BlinkSixteen_Config.h.in
    Avr_Led_BlinkSixteen_Config.h
)

add_executable(Avr_Led_BlinkSixteen
    Led_BlinkSixteen.c
)

target_include_directories(Avr_Led_BlinkSixteen
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Avr_Led_BlinkSixteen)
