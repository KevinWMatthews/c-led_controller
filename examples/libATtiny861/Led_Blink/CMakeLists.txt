project(LibATtiny861_Led_Blink VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

configure_file (
    LibATtiny861_Led_Blink_Config.h.in
    LibATtiny861_Led_Blink_Config.h
)

add_executable(LibATtiny861_Led_Blink
    Led_Blink.c
)

target_link_libraries(LibATtiny861_Led_Blink
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(LibATtiny861_Led_Blink
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME LibATtiny861_Led_Blink)
