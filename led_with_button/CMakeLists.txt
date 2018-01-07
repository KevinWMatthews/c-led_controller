if (CMAKE_CROSSCOMPILING)
    set (target_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}")

    ######################
    # Configure elf file #
    ######################
    #TODO does this belong in the toolchain file? Hmmm...
    add_executable(${target}.elf main.c)

    target_include_directories(${target}.elf
        PRIVATE
            "${PROJECT_SOURCE_DIR}/include"     # Include header files for application
            "${PROJECT_SOURCE_DIR}/include_hw"  # Include header files for hardware layer
            "${PROJECT_BINARY_DIR}/include"     # Include generated Config.h file
    )

    set_target_properties(${target}.elf
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums"
            LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,${target_path}.map"
    )

    # Create a list of files that we need to clean.
    set(avr_clean_files ${target_path}.map)



    ######################
    # Configure hex file #
    ######################
    # Custom targets can be made directly ('make hex' works) but
    # they are always considered out-of-date; the hex image will be rebuilt every time!
    # Custom targets do not build an OUTPUT file.
    add_custom_target(hex
        COMMAND
            # build the dependency
        DEPENDS
            ${target}.hex
    )

    # Custom commands can not be invoked from the command line - 'make hex' will not work.
    # Instead, they specify how to build the OUTPUT file.
    add_custom_command(
        OUTPUT
            ${target}.hex
        COMMAND
            # avr-objcopy [option(s)] in-file [out-file]
            # -j --only-section <name>         Only copy section <name> into the output
            # -O --output-target <bfdname>     Create an output file in format <bfdname>
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${target_path}.elf ${target_path}.hex
        DEPENDS
            ${target}.elf
        COMMENT
            "hex: Generating .hex file"
    )

    list(APPEND avr_clean_files
        ${target_path}.hex
    )

    ###
    # Alternatively, we can create a custom target and then attach a custom command to it.
    #add_custom_target(hex
    #    DEPENDS
    #        ${target_name}.elf
    #    COMMENT
    #        "hex target"
    #)

    #add_custom_command(
    #    TARGET              # Attach this command to the specified target
    #        hex
    #    COMMAND
    #        # avr-objcopy [option(s)] in-file [out-file]
    #        # -j --only-section <name>         Only copy section <name> into the output
    #        # -O --output-target <bfdname>     Create an output file in format <bfdname>
    #        ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${target}.elf ${target}.hex
    #    COMMENT
    #        "hex command"
    #)



    ################################
    # Configure disassemble target #
    ################################
    add_custom_target(disassemble
        COMMAND
            # avr-objdump <option(s)> <file(s)>
            # -h, --[section-]headers  Display the contents of the section headers
            # -S, --source             Intermix source code with disassembly
            ${CMAKE_OBJDUMP} -h -S ${target_path}.elf > ${target_path}.lst
        DEPENDS
            ${target}.elf
        COMMENT
            "disassemble: Generating .lst file"
    )

    list(APPEND avr_clean_files
        ${target_path}.lst
    )



    #########################
    # Configure size target #
    #########################
    add_custom_target(size
        COMMAND
            ${AVR_SIZE} ${target_path}.elf
        DEPENDS
            ${target}.elf
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
    add_custom_target(writeflash
        COMMAND
            sudo ${AVRDUDE} -c ${AVRDUDE_PROGRAMMERID} -p ${AVR_MCU} -P ${AVRDUDE_PORT} -e -U flash:w:${target_path}.hex
        DEPENDS
            ${target}.hex
    )



    #########################
    # Clean generated files #
    #########################
    set_directory_properties(
        PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
            "${avr_clean_files}"
    )
endif()
