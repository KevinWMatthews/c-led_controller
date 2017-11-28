# Load this Toolchain file for an out-of-source build using:
#   cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-avr-ATtiny.cmake -DCPPUTEST_HOME=/home/kmatthews/coding/c/led_controller/install_cpputest/avr ..

# For further details on cross compiling using CMake, see:
#   https://cmake.org/Wiki/CMake_Cross_Compiling

set (AVR_MCU "attiny861")
set (AVR_TOOLCHAIN_HOME /home/kevin/coding/toolchains/avr8-gnu-toolchain-linux_x86_64) 

set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_C_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-gcc)
set (CMAKE_CXX_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-g++)
set (AVR_SIZE ${AVR_TOOLCHAIN_HOME}/bin/avr-size)

set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)
set (CMAKE_FIND_ROOT_PATH ${AVR_TOOLCHAIN_HOME})
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


function(avr_cross_compile)
    add_executable(LedController main.c)

    # Include source code header files
    target_include_directories(LedController PRIVATE "${PROJECT_SOURCE_DIR}/include")
    # Include generated Config.h file
    target_include_directories(LedController PRIVATE "${PROJECT_BINARY_DIR}/include")


    set_target_properties(
        LedController
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums"
            LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,LedController.map"
    )

    #TODO I broke this somehow... before I started editing this time around.
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
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex LedController LedController.hex
        DEPENDS
            LedController
    )

    install (TARGETS LedController DESTINATION bin)
endfunction()
