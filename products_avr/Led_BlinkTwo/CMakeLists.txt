if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

set(Avr_Led_BlinkTwo_VERSION_MAJOR 1)
set(Avr_Led_BlinkTwo_VERSION_MINOR 0)
set(Avr_Led_BlinkTwo_VERSION_PATCH 0)

configure_file (
    Avr_Led_BlinkTwo_Config.h.in
    Avr_Led_BlinkTwo_Config.h
)

set(target Avr_Led_BlinkTwo)
set(target_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}")

add_executable(${target}.elf
    Led_BlinkTwo.c
)

target_include_directories(${target}.elf
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

set_target_properties(${target}.elf
    PROPERTIES
        COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
        LINK_FLAGS "${AVR_LINK_FLAGS} -Wl,-Map,${target_path}.map"
)

set(avr_clean_files ${target_path}.map)
set_directory_properties(PROPERTY
    ADDITIONAL_MAKE_CLEAN_FILES "${avr_clean_files}"
)

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")
