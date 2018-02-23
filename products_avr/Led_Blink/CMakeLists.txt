if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

set(Avr_Led_Blink_VERSION_MAJOR 1)
set(Avr_Led_Blink_VERSION_MINOR 0)
set(Avr_Led_Blink_VERSION_PATCH 0)

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
