if(COMPILE_TESTS)
    # Override header files in production code!!
    # This allows custom behavior for mocked registers.
    target_include_directories(ATtiny861 BEFORE
        PRIVATE "${CMAKE_CURRENT_LIST_DIR}/bit_manip"
    )

    target_sources(Test_ATtiny861
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/MockHw_ATtiny861.c"
            "${CMAKE_CURRENT_LIST_DIR}/Mock_ATtiny861_Timer0.cpp"
    )

    target_include_directories(Test_ATtiny861
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()
