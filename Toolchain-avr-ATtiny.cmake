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

function(avr_cross_compile)
    add_executable(LedController.elf main.c)

    # Include source code header files
    target_include_directories(LedController.elf PRIVATE "${PROJECT_SOURCE_DIR}/include")
    # Include generated Config.h file
    target_include_directories(LedController.elf PRIVATE "${PROJECT_BINARY_DIR}/include")


    set_target_properties(LedController.elf
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums"
            LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.map"
    )

    add_custom_target(
        disassemble
        COMMAND
            # avr-objdump <option(s)> <file(s)>
            # -h, --[section-]headers  Display the contents of the section headers
            # -S, --source             Intermix source code with disassembly
            ${CMAKE_OBJDUMP} -h -S "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.elf" > "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.lst"
        DEPENDS
            LedController.elf
    )

    add_custom_target(
        size
        COMMAND
            ${AVR_SIZE} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.elf"
        DEPENDS
            LedController.elf
    )

    # custom commands can not be invoked from the command line - 'make hex' will not work.
    add_custom_command(
        OUTPUT LedController.hex

        COMMAND
            # avr-objcopy [option(s)] in-file [out-file]
            # -j --only-section <name>         Only copy section <name> into the output
            # -O --output-target <bfdname>     Create an output file in format <bfdname>
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.elf" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/LedController.hex"
        DEPENDS
            LedController.elf
    )

    # custom targets can be made directly ('make hex' works)
    # but they are always considered out-of-date; the hex image will be rebuilt every time!
    add_custom_target(
        hex

        COMMAND
            # build the dependency

        DEPENDS
            LedController.hex
    )

install (TARGETS LedController.elf DESTINATION bin)
endfunction()
