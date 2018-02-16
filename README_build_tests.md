# Build Tests

## CppUTest setup
I prefer to build from source and install it locally. It can be downloaded from zip and installed to the system, but local builds allow the unit test framework itself to be cross-compiled and run on the target.
The instructions provided are for CMake.

```bash
cd led_controller
# This directory has been left empty for this purpose
git clone https://github.com/cpputest/cpputest.git CppUTest
cd CppUTest
git checkout v3.8
# CppUTest provides its own build directory.
cd cpputest_build
cmake .. -DCMAKE_INSTALL_PREFIX=/absolute/path/to/install/dir
make
make test	# Just to be sure
make install
```

There seems to be a bug in CppUTests CMake installation (or I don't know how to link to a CMake library). The library links properly but can not resolve includes.

See ```<your_install_dir>/lib/CppUTest/cmake/CppUTestTargets.cmake```:

```cmake
set_target_properties(CppUTest PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/CppUTest"
)
```

INTERFACE_INCLUDE_DIRECTORIES seems to be set improperly.
Replace:
```cmake
INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/CppUTest"
```
with:
```cmake
INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
```
and the

## LedController setup
Configure this project to link against the test framework and build tests.

```bash
	* cd led_controller
	* mkdir build
	* cd build
	* cmake .. -DCOMPILE_TESTS=ON -DCPPUTEST_HOME=/absolute/path/to/install/dir
	* make
```

Unit test executables are located in the bin/ directory. These can be run manually.

## Unit test options
CppUTest provides several useful options for running unit tests. Details are available in their documentation, but a few of my favorites are here:

| Option      | Effect                                            |
| ----------- |:-------------------------------------------------:|
| -c          | Colorize output                                   |
| -lg         | List all tests groups                             |
| -sg <group> | Run specific test group                           |
| -v          | Verbose (useful for seeing which test segfaulted) |
