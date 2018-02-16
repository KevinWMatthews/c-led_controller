To configure an out-of-tree build for cross-compilation,

    * Edit the Toolchain-*.cmake.example file to be specific to your system, removing the example suffix.
    * mkdir build-<arch>
    * cd build-<arch>
    * cmake ..
        - -DCMAKE_TOOLCHAIN_FILE=Toolchain-*.cmake
        - -DCOMPILE_TESTS=no    # Unit tests are not currently supported on the target architecture.

Verify that CMake located the correct C and C++ compilers.
If it did not, you may need to delete the CMake files and re-generate the build system from scratch. Something in there is hanging on to an out-of-date reference....

Again, various make commands can be run within build-arch/ and will not conflict with builds for the host system or other target architectures.

Should you be a fan of using Sublime Text, this build configuration does not conflict with the Sublime Text 2 generator.
Select it from the command line using

    * -G "Sublime Text 2 - Unix Makefiles"

or using cmake-gui.
