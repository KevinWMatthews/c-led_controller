project(Led_BlinkTwoActiveLow VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

configure_file (
    Led_BlinkTwoActiveLow_Config.h.in
    Led_BlinkTwoActiveLow_Config.h
)

add_executable(Led_BlinkTwoActiveLow
    Led_BlinkTwoActiveLow.c
    "${CMAKE_HOME_DIRECTORY}/src/Led_ATtiny861.c"
)

target_link_libraries(Led_BlinkTwoActiveLow
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(Led_BlinkTwoActiveLow
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_BlinkTwoActiveLow)
