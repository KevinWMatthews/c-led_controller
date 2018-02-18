# Override header files in production code!!
# This allows custom behavior for mocked registers.
target_include_directories(ATtiny861
    BEFORE PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_sources(Test_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/Mock_ATtiny861_Timer0.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Mock_avr_interrupt.cpp"
)

target_include_directories(Test_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}"
        "${CMAKE_CURRENT_LIST_DIR}/include"
)
