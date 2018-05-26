add_subdirectory(src)
add_subdirectory(examples)

if(COMPILE_TESTS)
    add_subdirectory(tests)
    add_subdirectory(mocks)
endif()
