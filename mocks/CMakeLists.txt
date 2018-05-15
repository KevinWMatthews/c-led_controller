enable_language(CXX)

add_library(MockATtiny861
    Mock_ATtiny861_Timer0.cpp
)

target_include_directories(MockATtiny861
    PUBLIC
        include
)

target_link_libraries(MockATtiny861
    PRIVATE
        CppUTest
        CppUTestExt
        ATtiny861::MockRegisters
)

add_library(MockATtiny861::MockATtiny861 ALIAS MockATtiny861)
