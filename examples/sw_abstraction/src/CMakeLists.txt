add_library(LedController
    Led_ATtiny861.c
)
target_include_directories(LedController
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/../include"
    }
    PRIVATE
        "${PROJECT_BINARY_DIR}/include"
)
# Expose the ATtiny861 library untile I create a pinmap
target_link_libraries(LedController
    PUBLIC
        ATtiny861::ATtiny861
)

if(COMPILE_TESTS)
    # Create library of LedController code for testing.
    # This enables test code to use link-time substitution to swap in mock modules.
	set_target_properties(LedController
        PROPERTIES
            COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
	)
	target_link_libraries(LedController
        PRIVATE
            CppUTest
    )
endif(COMPILE_TESTS)
