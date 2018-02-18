if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "hw_attiny861 products must be cross compiled!")
endif()

set(Libhw_ATtiny861_Led_Blink_VERSION_MAJOR 1)
set(Libhw_ATtiny861_Led_Blink_VERSION_MINOR 0)
set(Libhw_ATtiny861_Led_Blink_VERSION_PATCH 0)

configure_file (
    Libhw_ATtiny861_Led_Blink_Config.h.in
    Libhw_ATtiny861_Led_Blink_Config.h
)

set(target Libhw_Led_Blink)
set(target_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}")

add_executable(${target}.elf
    Led_Blink.c
)

target_link_libraries(${target}.elf
    PRIVATE
        ATtiny861::ATtiny861
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

set_directory_properties(
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        "${avr_clean_files}"
)

include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")
