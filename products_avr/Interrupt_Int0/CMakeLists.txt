if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")

add_executable(Avr_Interrupt_Int0
    Interrupt_Int0.c
)

create_avr_targets(TARGET_NAME Avr_Interrupt_Int0)
