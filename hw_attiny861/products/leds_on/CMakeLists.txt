set (target ATtinyHwDemo)
# CMake is smart enough to place output form add_executable in the runtime output directory
# Custom targets do not have this luxury; we must manually specify the path.
set (target_path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}")

######################
# Configure elf file #
######################
add_executable(${target}.elf
    main.c
)

#TODO Do we want the Config.h file here? Perhaps we need a config file per project.
#target_include_directories(${target}.elf
#    "${PROJECT_BINARY_DIR}/include"         # Include generated Config.h file
#)

if (CMAKE_CROSS_COMPILING)
    set_target_properties(${target}.elf
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS "${AVR_LINK_FLAGS} -Wl,-Map,${target_path}.map"
    )

    target_link_libraries(${target}.elf PRIVATE ATtiny861::Gpio)

    # Create a list of files that we need to clean.
    #TODO I don't know how to get add_executable to clean extra generated files.
    # To extend this list, use:
    #   list(APPEND avr_clean_files
    #       <filename>
    #   )
    set(avr_clean_files ${target_path}.map)



    ######################
    # Configure hex file #
    ######################
    # Custom targets can be made directly from the command line.
    # They are always considered out-of-date, so any commands that they specify will always be run.
    # Custom targets can not build an OUTPUT file, though they can create BYPRODUCTS.
    add_custom_target(${target}-hex
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
    add_custom_target(writeflash
        COMMAND
            sudo ${AVRDUDE} -c ${AVRDUDE_PROGRAMMERID} -p ${AVR_MCU} -P ${AVRDUDE_PORT} -e -U flash:w:${target_path}.hex
        DEPENDS
            ${target_path}.hex
    )



    #########################
    # Clean generated files #
    #########################
    set_directory_properties(
        PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
            "${avr_clean_files}"
    )
endif (CMAKE_CROSS_COMPILING)

if (COMPILE_TESTS)
    set_target_properties(${target}.elf PROPERTIES
        COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
    )
    target_link_libraries(${target}.elf CppUTest)
endif (COMPILE_TESTS)
