extern "C"
{
#include "Led2.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led2)
{
    Led led;

    void setup()
    {
        led = Led_Create(LED_1);
    }

    void teardown()
    {
        Led_Destroy(&led);
    }
};

TEST(Led2, create_an_led)
{
}

