add_library(ATtiny861 "")

if(COMPILE_TESTS)
    add_executable(Test_ATtiny861 "")
endif()

include(include/CMakeLists.txt)
include(src/CMakeLists.txt)

target_include_directories(ATtiny861
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${PROJECT_BINARY_DIR}/include"
        "${PROJECT_SOURCE_DIR}/bit_manip/include"
)

if(CMAKE_CROSSCOMPILING)
    set_target_properties(ATtiny861
        PROPERTIES
            COMPILE_FLAGS ${AVR_COMPILE_FLAGS}
            LINK_FLAGS ${AVR_LINK_FLAGS}
    )
else()
    # Create and link against mock AVR registers.
    add_subdirectory(mock_avr)
    target_link_libraries(ATtiny861 PRIVATE ATtiny861::MockRegisters)
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

    target_link_libraries(Test_ATtiny861
        PRIVATE
            CppUTest
            CppUTestExt
            ATtiny::861
            ATtiny861::MockRegisters
    )

    include(tests/CMakeLists.txt)
    include(mocks/CMakeLists.txt)
endif(COMPILE_TESTS)

add_library(ATtiny::861 ALIAS ATtiny861)
