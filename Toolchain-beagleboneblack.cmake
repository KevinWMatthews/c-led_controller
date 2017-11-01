# set (BBB_TOOLCHAIN_HOME /home/kevin/coding/toolchains/avr8-gnu-toolchain-linux_x86_64)#_cpputest)
set (BBB_TOOLCHAIN_HOME /home/kmatthews/coding/toolchains/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf)

message(STATUS "Setting up cross-compiler using toolchain found in:
${BBB_TOOLCHAIN_HOME}")

set (CMAKE_SYSTEM_NAME Linux)

set (CMAKE_STAGING_PREFIX ${PROJECT_BINARY_DIR}/staging)

set (CMAKE_C_COMPILER ${BBB_TOOLCHAIN_HOME}/bin/arm-linux-gnueabihf-gcc)
set (CMAKE_CXX_COMPILER ${BBB_TOOLCHAIN_HOME}/bin/arm-linux-gnueabihf-g++)

set (CMAKE_FIND_ROOT_PATH ${BBB_TOOLCHAIN_HOME})
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
