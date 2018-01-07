extern "C"
{
#include "Led2.h"
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
        Led_Destroy(&led);
    }
};

TEST(Led, create_an_led)
{
}

TEST(Led, can_destroy_a_null_led)
{
    Led_Destroy(NULL);
}

TEST(Led, destroy_sets_led_to_null)
{
    Led_Destroy(&led);
    POINTERS_EQUAL(NULL, led);
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
