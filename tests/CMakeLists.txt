add_executable(TestApp_LedController
    RunAllTests.cpp
    Test_Led.cpp
)
target_link_libraries(TestApp_LedController
    PRIVATE
        CppUTest
        LedController
        ATtiny861::ATtiny861
)

add_test(
    NAME Test_LedController
    COMMAND TestApp_LedController
)
