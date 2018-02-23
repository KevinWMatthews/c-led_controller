if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

set(Led_TurnOnTwo_VERSION_MAJOR 1)
set(Led_TurnOnTwo_VERSION_MINOR 0)
set(Led_TurnOnTwo_VERSION_PATCH 0)

configure_file (
    Led_TurnOnTwo_Config.h.in
    Led_TurnOnTwo_Config.h
)

add_executable(Led_TurnOnTwo
    Led_TurnOnTwo.c
    "${CMAKE_HOME_DIRECTORY}/src/Led_ATtiny861.c"
)

target_link_libraries(Led_TurnOnTwo
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(Led_TurnOnTwo
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_TurnOnTwo)
