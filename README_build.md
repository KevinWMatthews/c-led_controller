# Build Setup


## Local compilation
To configure an out-of-tree build, run

```bash
mkdir build
cd build
# Specify CPPUTEST_HOME only if compiling tests
cmake .. -DCOMPILE_TESTS=<yes/no> -DCPPUTEST_HOME=/path/to/CppUTest/install/dir
```

For instructions on installing CppUTest and running unit tests, see the [unit test README](README_unit_tests.md).

Various make commands can be run from within build/ and will not clutter up the source directory.
Unit test executables are located in the build/bin/ directory.
If unit tests are not compiled, only libraries are created. The products themselves are not yet compatible with x86.


## Cross compilation

### Toolchain setup
AVR provides precompiled toolchains for download here.
Sign in (you need to create an account), locate, and download:

	* avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz

Extract this to a directory of your choosing:

```bash
cd /path/to/toolchain/dir
tar -xvf avr8-gnu-toolchain-3.5.4.1709-linux.any.x86_64.tar.gz
```


### AVRDUDE setup
AVRDUDE makes it easy to flash a chip using an AVR ISP.
It is possible to build this from source, but I found it sufficient to install it to system using a package manager:

```bash
sudo apt install avrdude
sudo apt install avrdude-doc			# Just in case
```


### Build system setup
To configure an out-of-tree build for cross-compilation, first save a copy of ```Toolchain-*.cmake.example``` as ```Toolchain-*.cmake```.
Then edit AVR_TOOLCHAIN_HOME to point to the newly extracted toolchain:

```cmake
set(AVR_TOOLCHAIN_HOME /path/to/toolchain/dir/avr8-gnu-toolchain-*)
```

The new ```Toolchain-*.cmake``` file will not and should not be tracked.

Then run

```bash
mkdir build-<arch>
cd build-<arch>
# Unit tests are not currently supported on the target architecture
cmake .. -DCMAKE_TOOLCHAIN_FILE=Toolchain-*.cmake -DCOMPILE_TESTS=no
```

Verify that CMake located the correct C and C++ compilers.
If it did not, you may need to delete the CMake files and re-generate the build system from scratch. Something in CMake is hanging on to an out-of-date reference....
Do not try to switch between local and cross-compiled builds in the same directory! It is safer to use different directories for different target architectures.

Again, various make commands can be run within ```build-<arch>/``` and will not conflict with builds for the host system or other target architectures.


### Build
To build all programs, simply run

```bash
make
```

List all products and targets with

```bash
make help
```

To build an individual product, specify the basic image format (.elf):

```bash
make <product>.elf
```

Some targets are AVR specific but very useful for embedded development:

	* make <target>-size
		- List size and composition of the target program
	* make <target>-disassemble
		- Generate an .lst file containing the assembly code of the target program


## Install
The part is flashed using AVRDUDE. There is a special target for doing this:

```bash
make <target>-writeflash
```


## Extensions
Should you be a fan of using Sublime Text, these build configurations do not conflict with CMake's Sublime Text 2 generator.
Select it from the command line using the option

```bash
-G "Sublime Text 2 - Unix Makefiles"
```

or using cmake-gui.
