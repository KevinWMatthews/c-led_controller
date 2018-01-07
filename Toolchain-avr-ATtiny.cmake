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

# Build and install setup
#set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)
set (CMAKE_FIND_ROOT_PATH ${AVR_TOOLCHAIN_HOME})
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# avrdude programming options
set (AVRDUDE avrdude)
set (AVRDUDE_PORT usb)
set (AVRDUDE_MCU t861)
set (AVRDUDE_PROGRAMMERID avrispmkII)


#TODO make sure that we can find the toolchain - use find_path()? use find_program?
