enable_language(CXX)

target_sources(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/RunAllTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Gpio.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_GpioMap.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Timer0.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Interrupt.cpp"
)

target_include_directories(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/src/ATtiny861/src"   # Include for testing a private module
)

add_test(
    NAME Test_ATtiny861
    COMMAND TestApp_ATtiny861
)
