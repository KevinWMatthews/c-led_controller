# We could compile this into a library for individual products.
# At the moment, let the products link against the specific files that they require.
# To be rethought as the project expands...
# when I look at this with fresh eyes I expect to see production code do something here.
# If we make this a library we will have better luck tracking versions as the requirements grow.

if(COMPILE_TESTS)
    # Create library of LedController code for testing.
    # This enables test code to use link-time substitution to swap in mock modules.
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
