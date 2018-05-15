enable_language(C)

add_library(MockBitManip INTERFACE)

target_include_directories(MockBitManip
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}"
)

target_link_libraries(MockBitManip
    INTERFACE
        MockHw_ATtiny861::MockHw_ATtiny861
)

add_library(MockBitManip::MockBitManip ALIAS MockBitManip)
