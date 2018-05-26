project(Led_Blink VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

configure_file (
    Led_Blink_Config.h.in
    Led_Blink_Config.h
)

add_executable(Led_Blink
    Led_Blink.c
)

target_link_libraries(Led_Blink
    PRIVATE
        LedController::LedController
)

target_include_directories(Led_Blink
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_Blink)

add_library(LedController::LedController ALIAS LedController)
