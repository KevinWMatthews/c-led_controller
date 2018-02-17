add_library(ATtiny861 "")

if(COMPILE_TESTS)
    add_executable(Test_ATtiny861 "")
endif()

include(include/CMakeLists.txt)
include(src/CMakeLists.txt)

target_include_directories(ATtiny861
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${PROJECT_BINARY_DIR}/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/bit_manip/include"
)

if(CMAKE_CROSSCOMPILING)
    target_include_directories(ATtiny861 PRIVATE "${AVR_TOOLCHAIN_HOME}/avr")
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS ${AVR_LINK_FLAGS}
    )
else()
    include(mock_avr/CMakeLists.txt)
endif(CMAKE_CROSSCOMPILING)


if(COMPILE_TESTS)
    # Compile production code against CppUTest to enable memory leak detection
    set_target_properties(ATtiny861 PROPERTIES
        COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
    )
    target_link_libraries(ATtiny861 PRIVATE CppUTest)

    target_link_libraries(Test_ATtiny861 CppUTest CppUTestExt ATtiny::861)

    include(tests/CMakeLists.txt)
    include(mocks/CMakeLists.txt)
endif(COMPILE_TESTS)

# Specify an alias library for other targets to link against.
# This is not required but enables to CMake to throw an error while it
# is generating the build system if the library is not found.
# Otherwise, we must wait until the linker fails (after compilation).
add_library(ATtiny::861 ALIAS ATtiny861)
