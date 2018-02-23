if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${CMAKE_HOME_DIRECTORY}/AvrTargets.cmake")

add_executable(SetBit
    SetBit.c
	bit_numbers.c
)

create_avr_targets(TARGET_NAME SetBit)
