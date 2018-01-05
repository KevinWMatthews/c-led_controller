# Load this Toolchain file for an out-of-source build using:
#   cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-avr-ATtiny.cmake -DCPPUTEST_HOME=/home/kmatthews/coding/c/led_controller/install_cpputest/avr ..
#TODO how can we/should we separate this path from the rest of the Toolchain file?

# For further details on cross compiling using CMake, see:
#   https://cmake.org/Wiki/CMake_Cross_Compiling

set (AVR_MCU "attiny861")
set (AVR_TOOLCHAIN_HOME /home/kevin/coding/toolchains/avr8-gnu-toolchain-linux_x86_64) 

set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_C_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-gcc)
set (CMAKE_CXX_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-g++)
set (AVR_SIZE ${AVR_TOOLCHAIN_HOME}/bin/avr-size)
#TODO set CMAKE_AR=ar, CMAKE_LINKER=ld, CMAKE_NM=nm, CMAKE_OBJCOPY=objcopy, CMAKE_OBJDUMP=objdump, CMAKE_STRIP=strip, CMAKE_RANLIB=ranlib.
#TODO "set avr linker libs: -lc -lm -lgcc" ?

#set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)
set (CMAKE_FIND_ROOT_PATH ${AVR_TOOLCHAIN_HOME})
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#TODO make sure that we can find the toolchain - use find_path()? use find_program?

macro(create_avr_targets target_name)
    #TODO Re-watch the CMake tutorial and see if they like this. Aren't they anti-variable?
    set(elf_file ${target_name}.elf)
    set(map_file ${target_name}.map)
    set(hex_file ${target_name}.hex)
    set(lst_file ${target_name}.lst)
    message(STATUS "Set executables:
    elf_file: ${elf_file}
    map_file: ${map_file}
    hex_file: ${hex_file}
    lst_file: ${lst_file}")
endmacro()

function(avr_cross_compile)
    create_avr_targets(LedController)

    add_executable(${elf_file} main.c)

    # Include source code header files
    target_include_directories(${elf_file} PRIVATE "${PROJECT_SOURCE_DIR}/include")
    # Include generated Config.h file
    target_include_directories(${elf_file} PRIVATE "${PROJECT_BINARY_DIR}/include")


    set_target_properties(
        ${elf_file}
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums"
            LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${map_file}"
    )

    add_custom_target(
        disassemble
        COMMAND
            # avr-objdump <option(s)> <file(s)>
            # -h, --[section-]headers  Display the contents of the section headers
            # -S, --source             Intermix source code with disassembly
            ${CMAKE_OBJDUMP} -h -S "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file}" > "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${lst_file}"
        DEPENDS
            ${elf_file}
    )

    add_custom_target(
        size
        COMMAND
            ${AVR_SIZE} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file}"
        DEPENDS
            ${elf_file}
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
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${hex_file}"
        DEPENDS
            ${elf_file}
    )

    install (TARGETS ${elf_file} DESTINATION bin)
endfunction()
