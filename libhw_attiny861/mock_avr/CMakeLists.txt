target_sources(ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/src/mock_io.c"
)

target_include_directories(ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

if(COMPILE_TESTS)
    target_include_directories(Test_ATtiny861
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/include"
    )
endif()
