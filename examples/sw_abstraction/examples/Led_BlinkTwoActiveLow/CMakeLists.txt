project(Led_BlinkTwoActiveLow VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

configure_file (
    Led_BlinkTwoActiveLow_Config.h.in
    Led_BlinkTwoActiveLow_Config.h
)

add_executable(Led_BlinkTwoActiveLow
    Led_BlinkTwoActiveLow.c
)

target_link_libraries(Led_BlinkTwoActiveLow
    PRIVATE
        LedController::LedController
)

target_include_directories(Led_BlinkTwoActiveLow
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_BlinkTwoActiveLow)
