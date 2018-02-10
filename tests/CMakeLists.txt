# Create library of production code.
# This enables us to use link-time substitution to swap in mock modules.
#TODO This doesn't seem right...
add_library(ProductionLib
    "${PROJECT_SOURCE_DIR}/src_hw/Led_ATtiny861.c"
)
target_include_directories(ProductionLib PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(ProductionLib PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(ProductionLib PRIVATE CppUTest ATtiny::861)

set_target_properties(ProductionLib PROPERTIES
    COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
)

add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led2.cpp
)
target_link_libraries(Test_LedController PRIVATE CppUTest ProductionLib)
