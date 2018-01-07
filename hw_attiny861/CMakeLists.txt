add_library(ATtiny861Lib
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio.c"
    "${PROJECT_SOURCE_DIR}/hw_attiny861/src/ATtiny861_gpio_map.c"
)
target_include_directories(ATtiny861Lib PUBLIC "${PROJECT_SOURCE_DIR}/hw_attiny861/include")
target_include_directories(ATtiny861Lib PRIVATE "${AVR_TOOLCHAIN_HOME}/avr")

set_target_properties(ATtiny861Lib
    PROPERTIES
        COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
        LINK_FLAGS ${AVR_LINK_FLAGS}
)
