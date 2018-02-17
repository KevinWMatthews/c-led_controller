target_include_directories(ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_sources(ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/src/mock_io.c"
)

if(COMPILE_TESTS)
    # Override header files!!
    # This allows custom behavior for mocked registers.
    target_include_directories(ATtiny861 BEFORE
        PRIVATE "${CMAKE_CURRENT_LIST_DIR}/bit_manip"
    )
endif()
