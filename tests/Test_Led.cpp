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
        led2 = Led_Create(LED_2);
        state1 = LED_OFF;
        state2 = LED_OFF;
    }

    void teardown()
    {
        Led_Destroy(&led1);
        Led_Destroy(&led2);
    }
};

TEST(Led, can_create_led1)
{
    CHECK_TRUE(led1 != NULL);
}

TEST(Led, can_create_led2)
{
    CHECK_TRUE(led2 != NULL);
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
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOff(led1));
    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_OFF, state1);
}

TEST(Led, can_turn_led2_on)
{
    Led_TurnOn(led2);

    LONGS_EQUAL(LED_SUCCESS, Led_TurnOff(led2));
    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_OFF, state2);
}

TEST(Led, can_turn_led2_off)
{
    Led_TurnOn(led2);
    LONGS_EQUAL(LED_SUCCESS, Led_TurnOff(led2));
    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_OFF, state2);
}

TEST(Led, can_turn_led1_on_and_led2_off)
{
    Led_TurnOn(led1);
    Led_TurnOff(led2);

    Led_GetState(led1, &state1);
    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_ON, state1);
    LONGS_EQUAL(LED_OFF, state2);
}

TEST(Led, will_not_get_state_if_state_pointer_is_null)
{
    ret = Led_GetState(led1, NULL);
    LONGS_EQUAL(ret, LED_NULL_POINTER);
}

TEST(Led, will_not_create_invalid_led)
{
    LED_NUMBER led_num = (LED_NUMBER)(-1);  // Typecast -1
    Led invalid = Led_Create(led_num);
    CHECK_TRUE(invalid == NULL);
}

TEST(Led, do_not_turn_on_null_led)
{
    ret = Led_TurnOn(NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}

TEST(Led, do_not_turn_off_null_led)
{
    ret = Led_TurnOff(NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}
