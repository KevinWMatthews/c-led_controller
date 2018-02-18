######################################################
# Create custom AVR targets: size, disassemble, etc. #
######################################################

# The primary target (.elf file) must be configured elsewhere.
# target must contain the name of this file.
# target_path must contain the target preceded by the build output directory;
# CMake will not force the output of custom commands into this directory.



########################
# Configure hex target #
########################
# Custom targets can be made directly from the command line.
# They are always considered out-of-date, so any commands that they specify will always be run.
# Custom targets can not build an OUTPUT file, though they can create BYPRODUCTS.
add_custom_target(${target}.hex
    DEPENDS
        ${target_path}.hex
)

add_custom_command(
    OUTPUT
        ${target_path}.hex
    COMMAND
        # avr-objcopy [option(s)] in-file [out-file]
        # -j --only-section <name>         Only copy section <name> into the output
        # -O --output-target <bfdname>     Create an output file in format <bfdname>
        ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${target_path}.elf ${target_path}.hex
    DEPENDS
        ${target}.elf
    COMMENT
        "Generating hex file ${target}.hex"
)



################################
# Configure disassemble target #
################################
add_custom_target(${target}-disassemble
    DEPENDS
        ${target_path}.lst
)

add_custom_command(
    OUTPUT
        ${target_path}.lst
    COMMAND
        # avr-objdump <option(s)> <file(s)>
        # -h, --[section-]headers  Display the contents of the section headers
        # -S, --source             Intermix source code with disassembly
        ${CMAKE_OBJDUMP} -h -S ${target_path}.elf > ${target_path}.lst
    DEPENDS
        ${target}.elf
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
        ${AVR_SIZE} --format=sysv ${target_path}.elf
    COMMAND
        ${AVR_SIZE} --mcu=${AVR_MCU} --format=avr ${target_path}.elf
    DEPENDS
        ${target}.elf
    COMMENT
        "Generating stats for ${target}.elf"
)



#######################################
# Install targets on local filesystem #
#######################################
# Keep everything organized in the build directory
install(
    TARGETS
        ${target}.elf
    DESTINATION
        bin
)



##############################
# Add target to program chip #
##############################
add_custom_target(${target}-writeflash
    COMMAND
        sudo ${AVRDUDE} -c ${AVRDUDE_PROGRAMMERID} -p ${AVR_MCU} -P ${AVRDUDE_PORT} -e -U flash:w:${target_path}.hex
    DEPENDS
        ${target_path}.hex
)
