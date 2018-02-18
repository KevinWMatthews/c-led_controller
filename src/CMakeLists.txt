if(COMPILE_TESTS)
    # Create library of LedController code for testing.
    # This enables test code to use link-time substitution to swap in mock modules.
    # Individual products specify their own requried source files.
    add_library(LedController
        Led_ATtiny861.c
    )
    target_include_directories(LedController
        PUBLIC
            "${PROJECT_SOURCE_DIR}/include"
        PRIVATE
            "${PROJECT_BINARY_DIR}/include"
            "${PROJECT_SOURCE_DIR}/mocks"
    )
    target_link_libraries(LedController
        PRIVATE
            ATtiny::861
    )

	set_target_properties(LedController
        PROPERTIES
            COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
	)
	target_link_libraries(LedController
        PRIVATE
            CppUTest
    )
endif(COMPILE_TESTS)
