extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led)
{
    Led led1;
    LED_RETURN_CODE ret;
    LED_STATE state;

    void setup()
    {
        led1 = Led_Create(LED_1);
        state = LED_OFF;
    }

    void teardown()
    {
        Led_Destroy(&led1);
    }
};

TEST(Led, can_create_led1)
{
    CHECK_TRUE(led1 != NULL);
}

TEST(Led, can_destroy_an_led)
{
    Led_Destroy(&led1);
    POINTERS_EQUAL(NULL, led1);
}

TEST(Led, can_destroy_a_null_led)
{
    Led_Destroy(NULL);
}

TEST(Led, led_is_off_after_create)
{
    ret = Led_GetState(led1, &state);

    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state);
}

TEST(Led, can_turn_led1_on)
{
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOn(led1));
    Led_GetState(led1, &state);
    LONGS_EQUAL(LED_ON, state);
}

TEST(Led, can_turn_led1_off)
{
    Led_TurnOn(led1);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led1));
    Led_GetState(led1, &state);
    CHECK_EQUAL(LED_OFF, state);
}

TEST(Led, will_not_get_state_if_state_pointer_is_null)
{
    ret = Led_GetState(led1, NULL);
    LONGS_EQUAL(ret, LED_NULL_POINTER);
}
