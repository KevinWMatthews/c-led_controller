# Create library of LedController code.
# Individual products link against this.
# This enables test code to use link-time substitution to swap in mock modules.
add_library(LedController
	Led_ATtiny861.c
)
target_include_directories(LedController PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(LedController PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(LedController PRIVATE ATtiny::861)

if(COMPILE_TESTS)
	set_target_properties(LedController PROPERTIES
	    COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
	)
	target_link_libraries(LedController PRIVATE CppUTest)
endif(COMPILE_TESTS)
