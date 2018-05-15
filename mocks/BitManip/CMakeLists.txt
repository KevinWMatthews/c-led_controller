enable_language(C)

add_library(MockBitManip INTERFACE)

target_include_directories(MockBitManip
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries(MockBitManip
    INTERFACE
        MockATtiny861Registers::MockATtiny861Registers
)

add_library(MockBitManip::MockBitManip ALIAS MockBitManip)
