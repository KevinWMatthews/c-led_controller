if(NOT CMAKE_CROSSCOMPILING)
    message(FATAL_ERROR "Products must be cross compiled!")
endif()

set(Led_Blink_VERSION_MAJOR 1)
set(Led_Blink_VERSION_MINOR 0)
set(Led_Blink_VERSION_PATCH 0)

configure_file (
    Led_Blink_Config.h.in
    Led_Blink_Config.h
)

set(target Led_Blink)
set(target_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}")

add_executable(${target}.elf
    Led_Blink.c
    "${PROJECT_SOURCE_DIR}/src/Led_ATtiny861.c"
)
target_link_libraries(${target}.elf
    PRIVATE
        ATtiny861::ATtiny861
)

target_include_directories(${target}.elf
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
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
