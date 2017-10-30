# Cache variables have not been read when the Toolchain file is processed.
# Toolchain files are meant to be specific to the system on which they are run.
set (AVR_TOOLCHAIN_HOME /home/kevin/coding/Setup/avr8-gnu-toolchain-linux_x86_64)

# Target settings - what we are building for
# Name of the system: Linux, Windows, Generic
set (CMAKE_SYSTEM_NAME Generic)
# "used to load a CMAKE_SYSTEM_NAME-compiler-CMAKE_SYSTEM_PROCESSOR.cmake"
# "set this one if you are using a cross compiler where every target hardware needs special build settings."
# set (CMAKE_SYSTEM_PROCESSOR arm)

# ? Not sure what sysroot is/does...
# Will it look for host libraries while building? Target libraries while building?
# SET(CMAKE_SYSROOT avr8-gnu-toolchain-linux_x86_64)      # ??
# STAGING_PREFIX: where to install files on the host (?)
# INSTALL_PREFIX: where to install files on the target (?)
set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)

set (CMAKE_C_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-gcc)
set (CMAKE_CXX_COMPILER ${AVR_TOOLCHAIN_HOME}/bin/avr-g++)

# An alternative root path for various find_*() operations.
# This should be set to the target system.
set (CMAKE_FIND_ROOT_PATH ${AVR_TOOLCHAIN_HOME})

# Set options to ONLY, NEVER, BOTH
# Programs are typically used only by the host to build the executable
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Libraries are linked into the executable so they must run on the target
set (CMAKE_FIND_ROOT_PATH_LIBRARY ONLY)
# Like libraries, these are used in/by the target executable
set (CMAKE_FIND_ROOT_PATH_INCLUDE ONLY)
