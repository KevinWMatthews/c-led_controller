if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")

set(Libhw_ATtiny861_Led_Blink_VERSION_MAJOR 1)
set(Libhw_ATtiny861_Led_Blink_VERSION_MINOR 0)
set(Libhw_ATtiny861_Led_Blink_VERSION_PATCH 0)

configure_file (
    Libhw_ATtiny861_Led_Blink_Config.h.in
    Libhw_ATtiny861_Led_Blink_Config.h
)

add_executable(Libhw_Led_Blink
    Led_Blink.c
)

target_link_libraries(Libhw_Led_Blink
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(Libhw_Led_Blink
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(Libhw_Led_Blink)
