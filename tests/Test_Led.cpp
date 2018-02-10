extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led)
{
    Led led1;
    Led led2;
    LED_RETURN_CODE ret;
    LED_STATE state1;
    LED_STATE state2;

    void setup()
    {
        led1 = Led_Create(LED_1);
        state1 = LED_OFF;
        state2 = LED_OFF;
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

TEST(Led, can_create_led2)
{
    led2 = Led_Create(LED_2);
    CHECK_TRUE(led2 != NULL);
    Led_Destroy(&led2);
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
    ret = Led_GetState(led1, &state1);

    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state1);
}

TEST(Led, can_turn_led1_on)
{
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOn(led1));
    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_ON, state1);
}

TEST(Led, can_turn_led1_off)
{
    Led_TurnOn(led1);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led1));
    Led_GetState(led1, &state1);
    CHECK_EQUAL(LED_OFF, state1);
}

TEST(Led, can_turn_led2_on)
{
    Led_TurnOn(led2);

    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led2));
    Led_GetState(led2, &state2);
    CHECK_EQUAL(LED_OFF, state2);
}

TEST(Led, can_turn_led2_off)
{
    Led_TurnOn(led2);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led2));
    Led_GetState(led2, &state2);
    CHECK_EQUAL(LED_OFF, state2);
}

TEST(Led, will_not_get_state_if_state_pointer_is_null)
{
    ret = Led_GetState(led1, NULL);
    LONGS_EQUAL(ret, LED_NULL_POINTER);
}
