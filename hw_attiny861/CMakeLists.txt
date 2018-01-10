add_library(ATtiny861Gpio
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio.c"
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio_map.c"
)
target_include_directories(ATtiny861Gpio PUBLIC "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_include_directories(ATtiny861Gpio PRIVATE "${AVR_TOOLCHAIN_HOME}/avr")
target_link_libraries(ATtiny861Gpio CppUTest)
target_link_libraries(ATtiny861Gpio CppUTestExt)

set_target_properties(ATtiny861Gpio
    PROPERTIES
        COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
        LINK_FLAGS ${AVR_LINK_FLAGS}
)

# Specify an alias library for other targets to link against.
# This is not required but enables to CMake to throw an error while it
# is generating the build system if the library is not found.
# Otherwise, we must wait until the linker fails (after compilation).
add_library(ATtiny861::Gpio ALIAS ATtiny861Gpio)
