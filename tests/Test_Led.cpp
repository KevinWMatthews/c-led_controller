extern "C"
{
#include "Led.h"
}

#include "CppUTest/TestHarness.h"
// #include "CppUTestExt/MockSupport.h"

TEST_GROUP(Led)
{
    Led led, led2;

    void setup()
    {
        led = Led_Create(LEDHW_LED_1);
        led2 = Led_Create(LEDHW_LED_2);
    }

    void teardown()
    {
        Led_Destroy(&led);
        Led_Destroy(&led2);
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
    CHECK_EQUAL(LED_OFF, Led_GetState(led));
}

TEST(Led, can_turn_led_on)
{
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOn(led));
    CHECK_EQUAL(LED_ON, Led_GetState(led));
}

TEST(Led, can_turn_led_off)
{
    LED_SUCCESS, Led_TurnOn(led);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led));
    CHECK_EQUAL(LED_OFF, Led_GetState(led));
}

TEST(Led, turn_on_can_handle_null_pointer)
{
    POINTERS_EQUAL(LED_NULL_POINTER, Led_TurnOn(NULL));
}

TEST(Led, turn_off_can_handle_null_pointer)
{
    POINTERS_EQUAL(LED_NULL_POINTER, Led_TurnOff(NULL));
}

TEST(Led, can_turn_a_second_led_on)
{
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOn(led2));

    CHECK_EQUAL(LED_OFF, Led_GetState(led));
    CHECK_EQUAL(LED_ON, Led_GetState(led2));

    Led_Destroy(&led2);
}

TEST(Led, can_turn_a_second_led_off)
{
    Led_TurnOn(led);
    Led_TurnOn(led2);
    CHECK_EQUAL(LED_SUCCESS, Led_TurnOff(led2));

    CHECK_EQUAL(LED_ON, Led_GetState(led));
    CHECK_EQUAL(LED_OFF, Led_GetState(led2));
}
