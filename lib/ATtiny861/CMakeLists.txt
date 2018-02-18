# Create library
add_library(ATtiny861 "")

include(include/CMakeLists.txt)
include(src/CMakeLists.txt)

target_include_directories(ATtiny861
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${PROJECT_BINARY_DIR}/include"
)

target_link_libraries(ATtiny861
    PRIVATE
        BitManip::BitManip
)


# Create library of mock AVR registers when compiling locally.
if(NOT CMAKE_CROSSCOMPILING)
    add_subdirectory(mock_avr)
endif()


# Create test executable
if(COMPILE_TESTS)
    add_executable(Test_ATtiny861 "")

    include(tests/CMakeLists.txt)
    include(mocks/CMakeLists.txt)

    target_link_libraries(Test_ATtiny861
        PRIVATE
            CppUTest
            CppUTestExt
            ATtiny861::ATtiny861
            ATtiny861::MockRegisters
            BitManip::BitManip
    )
endif()


if(CMAKE_CROSSCOMPILING)
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS ${AVR_LINK_FLAGS}
    )
else()
    target_link_libraries(ATtiny861
        PRIVATE
        ATtiny861::MockRegisters
    )
endif(CMAKE_CROSSCOMPILING)


if(COMPILE_TESTS)
    # Compile production code against CppUTest to enable memory leak detection
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS "-include CppUTest/MemoryLeakDetectorMallocMacros.h"
    )
    target_link_libraries(ATtiny861
        PRIVATE
            CppUTest
    )
endif(COMPILE_TESTS)

add_library(ATtiny861::ATtiny861 ALIAS ATtiny861)
