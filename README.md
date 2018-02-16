# LED Controller
Welcome! This is a simple LED controller.
It is intended to be an example of design patterns as a simple project grows to be complex.

# Requirements
gcc
CMake
CppUTest

## Build Setup
This project was designed to be built with CMake.
This is primarily so that it is compatible with CLion and secondarily because I'm sick of using autotools.

To configure an out-of-tree build, run

    * mkdir build
    * cd build
    * cmake ..
        - -DCOMPILE_TESTS=<yes/no>
        - -DCPPUTEST_HOME=/path/to/CppUTest/install/dir

Various make commands can be run from within build/ and will not clutter up the source directory.

To configure an out-of-tree build for cross-compilation,

    * Edit the Toolchain file to be specific to your system.
        -- CMake expects Toolchain files to be system-specific and are processed before CMake Cache variables are read.
    * mkdir build-avr
    * cd build-avr
    * cmake ..
        - -DCMAKE_TOOLCHAIN_FILE=Toolchain-avr-*.cmake
        - -DCOMPILE_TESTS=no    # Unit tests are not currently supported on the target architecture.

Verify that the correct C and C++ compilers were located.
If they were not, you may need to delete the CMakeFiles/ directory and re-generate the build system.
Something in there is hanging on to an old reference....

Again, various make commands can be run within build-arch/ and will not conflict with builds for the host system or other target architectures.
