enable_language(CXX)

include("${CMAKE_HOME_DIRECTORY}/mocks/CMakeLists.txt")

add_executable(TestApp_ATtiny861 "")

target_sources(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/RunAllTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Gpio.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_GpioMap.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Timer0.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Test_ATtiny861_Interrupt.cpp"
)

target_sources(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/mocks/Mock_ATtiny861_Timer0.cpp"
        "${CMAKE_HOME_DIRECTORY}/mocks/Mock_avr_interrupt.cpp"
)

target_include_directories(TestApp_ATtiny861
    PRIVATE
        "${CMAKE_HOME_DIRECTORY}/src/ATtiny861"     # Include for testing a private module
        "${CMAKE_HOME_DIRECTORY}/mocks"
        "${CMAKE_HOME_DIRECTORY}/mocks/include"
)

target_link_libraries(TestApp_ATtiny861
    PRIVATE
        CppUTest
        CppUTestExt
        ATtiny861::ATtiny861
        ATtiny861::MockRegisters
        BitManip::BitManip
)

add_test(
    NAME Test_ATtiny861
    COMMAND TestApp_ATtiny861
)
