# LED Controller
Welcome! This is a simple LED controller.
It is intended to be an example of design patterns as a simple project grows to be complex.

# Requirements
CMake
cmake-gui
CppUTest

## Build Setup
This project was designed to be built with CMake.
This is primarily so that it is compatible with CLion and secondarily because I'm sick of using autotools.

To configure an out-of-tree build, run

    * mkdir build
    * cd build
    * cmake-gui ..
        - Define CPPUTEST_HOME as location where CppUTest is installed
        - Configure
        - Generate

Various make commands can be run from within build/ and will not clutter up the source directory.

To configure an out-of-tree build for cross-compilation,

    * Edit the Toolchain file to be specific to your system.
        -- CMake expects Toolchain files to be system-specific and are processed before CMake Cache variables are read.
    * mkdir build-arch
    * cd build-arch
    * cmake-guil -DCMAKE\_TOOLCHAIN\_FILE=../Toolchain-avr-ATtiny.cmake ..
        - Define AVR_TOOLCHAIN_HOME as location where the AVR toolchain is installed
        - Configure
        - Generate

Again, various make commands can be run within build-arch/ and will not conflict with builds for the host system or other target architectures.

# Installation
This project designed to run on an embedded platform rather than be installed on a desktop system.
Despite this, it is very useful to run a mock application in a desktop environment.
A desktop-comptabible executable will be installed in the install/ directory.

CMake does not offer a target to uninstall a project. To uninstall, simply delete the install/ directory.
