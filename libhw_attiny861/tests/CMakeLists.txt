enable_language(CXX)

target_sources(Test_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/RunAllTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Gpio.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_GpioMap.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Timer0.cpp"
)

target_include_directories(Test_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"   # Include for testing a private module
)
