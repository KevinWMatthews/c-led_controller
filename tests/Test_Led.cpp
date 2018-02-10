extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led)
{
    Led led;
    LED_RETURN_CODE ret;
    LED_STATE state;

    void setup()
    {
        led = Led_Create(LED_1);
        state = LED_OFF;
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
    ret = Led_GetState(led, &state);

    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state);
}

TEST(Led, can_turn_led_on)
{
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOn(led));
    Led_GetState(led, &state);
    LONGS_EQUAL(LED_ON, state);
}

TEST(Led, can_turn_led_off)
{
    Led_TurnOn(led);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led));
    Led_GetState(led, &state);
    CHECK_EQUAL(LED_OFF, state);
}

TEST(Led, will_not_get_state_if_state_pointer_is_null)
{
    ret = Led_GetState(led, NULL);
    LONGS_EQUAL(ret, LED_NULL_POINTER);
}
