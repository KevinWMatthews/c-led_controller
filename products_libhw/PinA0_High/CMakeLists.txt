if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")

add_executable(Libhw_PinA0_High
    PinA0_High.c
)
target_link_libraries(Libhw_PinA0_High
    PRIVATE
        ATtiny861::ATtiny861
)

create_avr_targets(TARGET_NAME Libhw_PinA0_High)
