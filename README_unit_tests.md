# Build Tests


## CppUTest setup
There are several methods of obtaining the [CppUTest unit test framework](http://cpputest.github.io/). The most flexible is to build from source and install to a local directory (not to the system). This allows the test tools themselves to be cross-compiled.
The instructions provided are for CMake. See CppUTest's documentation for Autotools instructions.

```bash
cd c-led_controller
# The cpputest directory has been ignored for this purpose
git clone https://github.com/cpputest/cpputest.git
cd cpputest
git checkout v3.8
# CppUTest provides its own build directory.
cd cpputest_build
cmake .. -DCMAKE_INSTALL_PREFIX=/absolute/path/to/install/dir
make
make test	# Just to be sure
make install
```

There seems to be a bug in CppUTest's CMake installation (or I don't know how to link to a CMake library). The library links properly but can not resolve CppUTest includes.

To fix this, open ```</path/to/CppUTest/install/dir/>/lib/CppUTest/cmake/CppUTestTargets.cmake``` and find:

INTERFACE_INCLUDE_DIRECTORIES seems to be set improperly or not set at all. Search for the lines:

```cmake
set_target_properties(CppUTest PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/CppUTest"
)
```

and replace:
```cmake
INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/CppUTest"
```
with:
```cmake
INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
```

If you can not find the above lines, then search for where the CppUTest library is created:

```cmake
# Create imported target CppUTest
add_library(CppUTest STATIC IMPORTED)
```
and add
```cmake
INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
```
just below.

This should cause CppUTest includes to be resolved.


## LedController setup
Configure this project to link against the test framework and build tests.

```bash
cd c-led_controller
mkdir build
cd build
cmake .. -DCOMPILE_TESTS=ON -DCPPUTEST_HOME=/absolute/path/to/CppUTest/install/dir
make
```

Unit test executables are automatically placed in the build/bin/ directory. These must be run manually.


## Unit test options
CppUTest provides several options for running unit tests. A few of useful ones are here:

| Option      | Effect                                            |
| ----------- |:-------------------------------------------------:|
| -c          | Colorize output                                   |
| -lg         | List all tests groups                             |
| -sg <group> | Run specific test group                           |
| -v          | Verbose (useful for seeing which test segfaulted) |

Full details are available in their documentation.
