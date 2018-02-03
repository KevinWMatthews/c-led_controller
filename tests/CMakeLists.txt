# Memory leak detection:
#   The production code library needs to include MemoryLeakDetectorMallocMacros.h.
#   The test code executdable needs to include MemoryLeakDetectorNewMacros.h.
#   When directly including CppUTests's memory leak detection files, do NOT put '-include' inside double quotes.
#Update - this no longer seems to be true?



##########################################################
# Create library of hardware-independent production code #
##########################################################
# This enables us to use link-time substitution to swap in mock hardware modules.
# Should this also be done in production code? Or will each target select files as needed?
add_library(ProductionLib
    "${PROJECT_SOURCE_DIR}/src_hw/Led_ATtiny861.c"
)
target_include_directories(ProductionLib PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(ProductionLib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(ProductionLib PRIVATE "${PROJECT_SOURCE_DIR}/libhw_attiny861/include")

# set_target_properties(ProductionLib PROPERTIES
    # COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
# )
target_link_libraries(ProductionLib ATiny861GPIO)
