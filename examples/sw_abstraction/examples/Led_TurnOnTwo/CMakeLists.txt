project(Led_TurnOnTwo VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

configure_file (
    Led_TurnOnTwo_Config.h.in
    Led_TurnOnTwo_Config.h
)

add_executable(Led_TurnOnTwo
    Led_TurnOnTwo.c
)

target_link_libraries(Led_TurnOnTwo
    PRIVATE
        LedController::LedController
)

target_include_directories(Led_TurnOnTwo
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_TurnOnTwo)
