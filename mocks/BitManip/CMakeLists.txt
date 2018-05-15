enable_language(C)

add_library(MockBitManip INTERFACE)

target_include_directories(MockBitManip
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries(MockBitManip
    INTERFACE
        ATtiny861::MockRegisters
)

add_library(MockBitManip::MockBitManip ALIAS MockBitManip)
