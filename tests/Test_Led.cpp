extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"
// #include "CppUTestExt/MockSupport.h"

TEST_GROUP(Led)
{
};

TEST(Led, create_an_led)
{
    Led led = Led_Create();
    Led_Destroy(led);
}
