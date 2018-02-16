# Build Setup


## Local compilation
To configure an out-of-tree build, run

    * mkdir build
    * cd build
    * cmake ..
        - -DCOMPILE_TESTS=<yes/no>
        - -DCPPUTEST_HOME=/path/to/CppUTest/install/dir 	# If compiling tests

That's it!

Various make commands can be run from within build/ and will not clutter up the source directory.
Unit test executables are located in the bin/ directory.
If unit tests are not compiled, only libraries are created. I don't yet have an x86-compatible version of the products.


## Cross compilation

### Toolchain setup
AVR provides [precompiled toolchains for download here](http://www.atmel.com/tools/atmelavrtoolchainforlinux.aspx).
Sign in (you need to create an account), locate, and download:

	* avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz

Extract this to a directory of your choosing:

	* cd /path/to/toolchain/dir
	* tar -xvf avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz


### AVRDUDE setup
AVRDUDE makes it easy to flash a chip using at AVR ISP.
It is possible to build this from source, but I found it sufficient to install it to system using a package manager:

	* sudo apt install avrdude
	* sudo apt install avrdude-doc			# Just in case


### Build system setup
To configure an out-of-tree build for cross-compilation, run

    * Edit the Toolchain-*.cmake.example file to be specific to your system, removing the example suffix.
    * mkdir build-<arch>
    * cd build-<arch>
    * cmake ..
        - -DCMAKE_TOOLCHAIN_FILE=Toolchain-*.cmake
        - -DCOMPILE_TESTS=no    # Unit tests are not currently supported on the target architecture.

Verify that CMake located the correct C and C++ compilers.
If it did not, you may need to delete the CMake files and re-generate the build system from scratch. Something in there is hanging on to an out-of-date reference....

Again, various make commands can be run within build-arch/ and will not conflict with builds for the host system or other target architectures.

### Build and install
To build all programs, simply run

	* make

List all products and targets with

	* make help

To build an individual product, specify the basic image format (.elf):

	* make <product>.elf

The part is flashed using AVRDUDE. There is a special target for doing this:

	* make <target>-writeflash

Some targets are AVR specific but very useful for embedded development:

	* <target>-size
		- List size and composition of the target program
	* <target>-disassemble
		- Generate an .lst file containing the assembly code of the target program



## Extensions
Should you be a fan of using Sublime Text, this build configuration does not conflict with the Sublime Text 2 generator.
Select it from the command line using

    * -G "Sublime Text 2 - Unix Makefiles"

or using cmake-gui.
