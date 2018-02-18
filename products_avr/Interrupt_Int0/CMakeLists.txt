if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross-compiled")
endif()

set(target Avr_Interrupt_Int0)

add_executable(${target}
    Interrupt_Int0.c
)

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")
