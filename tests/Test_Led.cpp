extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led)
{
    Led led;

    void setup()
    {
        led = Led_Create(LED_1);
    }

    void teardown()
    {
    }
};

TEST(Led, create_an_led)
{
}

TEST(Led, led_is_off_after_create)
{
    LONGS_EQUAL(LED_OFF, Led_GetState(led));
}

TEST(Led, can_turn_led_on)
{
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOn(led));
    LONGS_EQUAL(LED_ON, Led_GetState(led));
}

TEST(Led, can_turn_led_off)
{
    Led_TurnOn(led);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led));
    CHECK_EQUAL(LED_OFF, Led_GetState(led));
}
