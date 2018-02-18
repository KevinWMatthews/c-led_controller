if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")

set(Avr_Led_BlinkTwo_VERSION_MAJOR 1)
set(Avr_Led_BlinkTwo_VERSION_MINOR 0)
set(Avr_Led_BlinkTwo_VERSION_PATCH 0)

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

create_avr_targets(Avr_Led_BlinkTwo)
