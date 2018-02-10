add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led.cpp
)
target_link_libraries(Test_LedController PRIVATE CppUTest LedController ATtiny::861)
