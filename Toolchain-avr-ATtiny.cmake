# See https://cmake.org/Wiki/CMake_Cross_Compiling
# for details on how to flags specific to this cross comiplation:
    # # specify the cross compiler
    # CMAKE_FORCE_C_COMPILER(arm-elf-gcc GNU)
    # CMAKE_FORCE_CXX_COMPILER(arm-elf-g++ GNU)

# Cache variables have not been read when the Toolchain file is processed.
# Toolchain files are meant to be specific to the system on which they are run.
#TODO we need to verify that this can be found!!
# set (AVR_TOOLCHAIN_HOME /home/kevin/coding/toolchains/avr8-gnu-toolchain-linux_x86_64)

# cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-avr-ATtiny.cmake -DCPPUTEST_HOME=/home/kmatthews/coding/c/led_controller/install_cpputest/avr ..
set (AVR_TOOLCHAIN_HOME /home/kmatthews/coding/toolchains/avr8-gnu-toolchain-linux_x86_64)

#TODO do we want these? No!! They find the program in /usr/bin. And they run twice....
# find_program(AVR_CC avr-gcc)
# find_program(AVR_CXX avr-g++)
# find_program(AVR_OBJCOPY avr-objcopy)
# find_program(AVR_OBJDUMP avr-objdump)
# find_program(AVR_SIZE_TOOL avr-size)


# The build will not be accurate if the flags in this file are not used.
# Force CMake to use the this toolchain.
INCLUDE(CMakeForceCompiler)

# Target settings - what we are building for
# Name of the system: Linux, Windows, Generic
set (CMAKE_SYSTEM_NAME Generic)
# "used to load a CMAKE_SYSTEM_NAME-compiler-CMAKE_SYSTEM_PROCESSOR.cmake"
# "set this one if you are using a cross compiler where every target hardware needs special build settings."
#TODO set this to the ATtiny861?
# set (CMAKE_SYSTEM_PROCESSOR avr)

# CMAKE_FORCE_*_COMPILER is deprecated.
set (CMAKE_C_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-gcc)
set (CMAKE_CXX_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-g++)

set (AVR_MCU "attiny861")
#TODO watch that video again and see how to set C flags...  See slide 15.
# I should probably create a separate dummy project for compiling for AVR.
# Do I use:
#   target_compile_options()
#   target_compile_definitions()    # requirements?
#   set_target_property(0
#   set_property(TARGET)
set (AVR_C_FLAGS "-mmcu=${AVR_MCU} -Wall -Wstrict-prototypes -funsigned-bitfields -funsigned-char -fpack-struct -fshort-enums")
set (AVR_LINK_FLAGS "-Wl,-Map,map_file.map -mmcu=${AVR_MCU}")


set (AVRDUDE_MCU "t861")        # avrdude -p ? or http://www.nongnu.org/avrdude/user-manual/avrdude_4.html

# ? Not sure what sysroot is/does...
# Will it look for host libraries while building? Target libraries while building?
# SET(CMAKE_SYSROOT avr8-gnu-toolchain-linux_x86_64)      # ??
# STAGING_PREFIX: where to install files on the host (?)
# INSTALL_PREFIX: where to install files on the target (?)
set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)

# An alternative root path for various find_*() operations.
# This should be set to the target system.
set (CMAKE_FIND_ROOT_PATH ${AVR_TOOLCHAIN_HOME})

# Set options to ONLY, NEVER, BOTH
# Programs are typically used only by the host to build the executable
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Libraries are linked into the executable so they must run on the target
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# Like libraries, these are used in/by the target executable
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
