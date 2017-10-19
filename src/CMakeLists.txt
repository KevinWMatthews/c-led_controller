include_directories("${PROJECT_SOURCE_DIR}/include")

# configure_file(<input> <output>)
# Copy input file to output file and perform variable substitution.
configure_file (
    "${PROJECT_SOURCE_DIR}/include/LedControllerConfig.h.in"
    "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h"
    )

# Include the generated config file in the project.
include_directories(${PROJECT_BINARY_DIR})

add_executable(LedController main.c)
install (TARGETS LedController DESTINATION "bin")
install (FILES "${PROJECT_BINARY_DIR}/include/LedControllerConfig.h" DESTINATION "include")
