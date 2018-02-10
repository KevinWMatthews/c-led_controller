add_executable(Test_LedController
    RunAllTests.cpp
    Test_Led2.cpp
)
target_link_libraries(Test_LedController PRIVATE CppUTest LedController)
