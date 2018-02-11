add_library(ATtiny861
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_Gpio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_GpioMap.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_Timer0.c"
)
target_include_directories(ATtiny861 PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(ATtiny861 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(ATtiny861 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

if(CMAKE_CROSSCOMPILING)
    target_include_directories(ATtiny861 PRIVATE "${AVR_TOOLCHAIN_HOME}/avr")
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS ${AVR_LINK_FLAGS}
    )
else()
    target_include_directories(ATtiny861 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/mocks/include")
    # Extend the source list of the target.
    # Populate the PRIVATE SOURCES property of the target.
    # If you populate PUBLIC SOURCES, the file could/will be linked against twice.
    target_sources(ATtiny861 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/mocks/src/mock_io.c")
endif(CMAKE_CROSSCOMPILING)


if(COMPILE_TESTS)
    # Compile production code against CppUTest to enable memory leak detection
    set_target_properties(ATtiny861 PROPERTIES
        COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
    )
    target_link_libraries(ATtiny861 PRIVATE CppUTest)
    add_subdirectory(tests)
endif(COMPILE_TESTS)

# Specify an alias library for other targets to link against.
# This is not required but enables to CMake to throw an error while it
# is generating the build system if the library is not found.
# Otherwise, we must wait until the linker fails (after compilation).
add_library(ATtiny::861 ALIAS ATtiny861)
