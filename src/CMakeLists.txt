if(COMPILE_TESTS)
    # Create library of LedController code for testing.
    # This enables test code to use link-time substitution to swap in mock modules.
    # Individual products specify their own requried source files.
    add_library(LedController
        Led_ATtiny861.c
    )
    target_include_directories(LedController
        PUBLIC
            "${CMAKE_HOME_DIRECTORY}/include"
        PRIVATE
            "${PROJECT_BINARY_DIR}/include"
            "${CMAKE_HOME_DIRECTORY}/mocks"
    )
    target_link_libraries(LedController
        PRIVATE
            ATtiny861::ATtiny861
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
