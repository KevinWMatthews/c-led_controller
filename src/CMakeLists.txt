# Create a Config.h file for this project
# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
    )

add_executable(LedController main.c)
# Include source code header files
target_include_directories(LedController PRIVATE "${PROJECT_SOURCE_DIR}/include")
# Include generated Config.h file
target_include_directories(LedController PRIVATE "${PROJECT_BINARY_DIR}/include")

install (TARGETS LedController DESTINATION bin)
