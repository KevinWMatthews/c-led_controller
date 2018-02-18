######################################################
# Create custom AVR targets: size, disassemble, etc. #
######################################################

# Before including this file,
#   add an executable (and specify its source code list)
#   define target as the executable name

# To customize compile or link flags, set these target properties after including this file.
# This will overwrite whatever settings are defined here.

#########################
# Configure .elf target #
#########################
# The .elf file is the output of the CMake executable target.
get_target_property(target_path ${target} RUNTIME_OUTPUT_DIRECTORY)
set_target_properties(${target}
    PROPERTIES
        SUFFIX .elf
        COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
        LINK_FLAGS "${AVR_LINK_FLAGS} -Wl,-Map,${target_path}/${target}.map"
)

set(avr_clean_files ${target_path}/${target}.map)
set_directory_properties(PROPERTY
    ADDITIONAL_MAKE_CLEAN_FILES "${avr_clean_files}"
)


########################
# Configure hex target #
########################
# Custom targets can be made directly from the command line.
# They are always considered out-of-date, so any commands that they specify will always be run.
# Custom targets can not build an OUTPUT file, though they can create BYPRODUCTS.
add_custom_target(${target}.hex
    DEPENDS
        ${target_path}/${target}.hex
)

add_custom_command(
    OUTPUT
        ${target_path}/${target}.hex
    COMMAND
        # avr-objcopy [option(s)] in-file [out-file]
        # -j --only-section <name>         Only copy section <name> into the output
        # -O --output-target <bfdname>     Create an output file in format <bfdname>
        ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${target_path}/${target}.elf ${target_path}/${target}.hex
    DEPENDS
        ${target}
    COMMENT
        "Generating hex file ${target}.hex"
)



################################
# Configure disassemble target #
################################
add_custom_target(${target}-disassemble
    DEPENDS
        ${target_path}/${target}.lst
)

add_custom_command(
    OUTPUT
        ${target_path}/${target}.lst
    COMMAND
        # avr-objdump <option(s)> <file(s)>
        # -h, --[section-]headers  Display the contents of the section headers
        # -S, --source             Intermix source code with disassembly
        ${CMAKE_OBJDUMP} -h -S ${target_path}/${target}.elf > ${target_path}/${target}.lst
    DEPENDS
        ${target}
    COMMENT
        "Generating lst file ${target}.lst"
)



#########################
# Configure size target #
#########################
# Custom targets are always out-of-date, so the COMMANDS that they specify are always run.
# This is ideal for the 'size' target, where we always wish to see the output.
add_custom_target(${target}-size
    # avr-size [option(s)] [file(s)]
    #   --format: sysv, berkeley, avr
    #   --mcu=<avr_mcu>
    COMMAND
        ${AVR_SIZE} --format=sysv ${target_path}/${target}.elf
    COMMAND
        ${AVR_SIZE} --mcu=${AVR_MCU} --format=avr ${target_path}/${target}.elf
    DEPENDS
        ${target_path}/${target}.elf
    COMMENT
        "Generating stats for ${target}.elf"
)



##############################
# Add target to program chip #
##############################
add_custom_target(${target}-writeflash
    COMMAND
        sudo ${AVRDUDE} -c ${AVRDUDE_PROGRAMMERID} -p ${AVR_MCU} -P ${AVRDUDE_PORT} -e -U flash:w:${target_path}/${target}.hex
    DEPENDS
        ${target_path}/${target}.hex
)
