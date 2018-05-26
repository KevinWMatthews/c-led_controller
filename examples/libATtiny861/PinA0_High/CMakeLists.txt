if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

add_executable(LibATtiny861_PinA0_High
    PinA0_High.c
)
target_link_libraries(LibATtiny861_PinA0_High
    PRIVATE
        ATtiny861::ATtiny861
)
target_include_directories(LibATtiny861_PinA0_High
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME LibATtiny861_PinA0_High)
