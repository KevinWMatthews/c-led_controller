if(NOT CMAKE_CROSSCOMPILING)
    # It's a trick to figure out how to support both local and cross-compilation
    # for end products. Don't support it for now.
    message(FATAL_ERROR "hw_attiny861 products must be cross compiled!")
endif()

set (target PinA0High)
include("${PROJECT_SOURCE_DIR}/AvrTargets.cmake")
