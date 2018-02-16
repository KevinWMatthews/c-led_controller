To configure an out-of-tree build,

    * mkdir build
    * cd build
    * cmake ..
        - -DCOMPILE_TESTS=<yes/no>
        - -DCPPUTEST_HOME=/path/to/CppUTest/install/dir 	# If compiling tests

That's it!

Various make commands can be run from within build/ and will not clutter up the source directory.
Unit test executables are located in the bin/ directory.
If unit tests are not compiled, only libraries are created. I don't yet have an x86-compatible version of the products.

Should you be a fan of using Sublime Text, this build configuration does not conflict with the Sublime Text 2 generator.
Select it from the command line using

    * -G "Sublime Text 2 - Unix Makefiles"

or using cmake-gui.
