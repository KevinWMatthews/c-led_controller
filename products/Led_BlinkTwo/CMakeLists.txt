project(Led_BlinkTwo VERSION 1.0.0)

if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

configure_file (
    Led_BlinkTwo_Config.h.in
    Led_BlinkTwo_Config.h
)

add_executable(Led_BlinkTwo
    Led_BlinkTwo.c
    "${CMAKE_HOME_DIRECTORY}/src/Led/Led_ATtiny861.c"
)

target_link_libraries(Led_BlinkTwo
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(Led_BlinkTwo
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/include"
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME Led_BlinkTwo)
