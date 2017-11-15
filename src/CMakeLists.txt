# Create a Config.h file for this project
# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
    )

add_executable(LedController main.c)
# Include source code header files
target_include_directories(LedController PRIVATE "${PROJECT_SOURCE_DIR}/include")
# Include generated Config.h file
target_include_directories(LedController PRIVATE "${PROJECT_BINARY_DIR}/include")

if (CMAKE_CROSSCOMPILING)
    set_target_properties(
        LedController
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums"
            LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,LedController.map"
    )

    add_custom_target(
        disassemble
        COMMAND
            # avr-objdump <option(s)> <file(s)>
            # -h, --[section-]headers  Display the contents of the section headers
            # -S, --source             Intermix source code with disassembly
            ${CMAKE_OBJDUMP} -h -S LedController > LedController.lst
        DEPENDS
            LedController
    )

    # use find_program?
    add_custom_target(
        size
        COMMAND
            ${AVR_SIZE} LedController
        DEPENDS
            LedController
    )

    # This should actually be a custom_command? This works for now.
    # custom targets can be made directly (make hex)
    # but they are always considered out-of-date; the hex image will be rebuilt every time!
    add_custom_target(
        hex
        COMMAND
            # avr-objcopy [option(s)] in-file [out-file]
            # -j --only-section <name>         Only copy section <name> into the output
            # -O --output-target <bfdname>     Create an output file in format <bfdname>
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex LedController LedControlle.hex
        DEPENDS
            LedController
    )
endif()

install (TARGETS LedController DESTINATION bin)
