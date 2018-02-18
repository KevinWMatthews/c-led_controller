if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")

set(Led_Blink_VERSION_MAJOR 1)
set(Led_Blink_VERSION_MINOR 0)
set(Led_Blink_VERSION_PATCH 0)

configure_file (
    Led_Blink_Config.h.in
    Led_Blink_Config.h
)

add_executable(Led_Blink
    Led_Blink.c
    "${PROJECT_SOURCE_DIR}/src/Led_ATtiny861.c"
)

target_link_libraries(Led_Blink
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(Led_Blink
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_Blink)
