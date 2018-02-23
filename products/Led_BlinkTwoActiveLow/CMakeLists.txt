if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

set(Led_BlinkTwoActiveLow_VERSION_MAJOR 1)
set(Led_BlinkTwoActiveLow_VERSION_MINOR 0)
set(Led_BlinkTwoActiveLow_VERSION_PATCH 0)

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
