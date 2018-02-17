target_sources(ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_Gpio.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_GpioMap.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_GpioMap.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ATtiny861_Timer0.c"
)
