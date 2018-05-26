if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/cmake/AvrTargets.cmake")

add_executable(LibATtiny861_PinPort_AsOutput
    PinPort_AsOutput.c
)
target_link_libraries(LibATtiny861_PinPort_AsOutput
    PRIVATE
        ATtiny861::ATtiny861
)
target_include_directories(LibATtiny861_PinPort_AsOutput
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

create_avr_targets(TARGET_NAME LibATtiny861_PinPort_AsOutput)
