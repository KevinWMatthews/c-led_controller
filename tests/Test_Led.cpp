extern "C"
{
#include "Led.h"
#include "ATtiny861_Gpio.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Led)
{
    Led led1;
    Led led2;
    LedParams params;
    LED_RETURN_CODE ret;
    LED_STATE state1;
    LED_STATE state2;

    void setup()
    {
        params.active_state = LED_ACTIVE_HIGH;
        params.initial_state = LED_OFF;
        led1 = Led_Create(ATTN861_PA0, &params);
        params.active_state = LED_ACTIVE_HIGH;
        params.initial_state = LED_OFF;
        led2 = Led_Create(ATTN861_PA1,  &params);
        state1 = LED_OFF;
        state2 = LED_OFF;
    }

    void teardown()
    {
        Led_Destroy(&led1);
        Led_Destroy(&led2);
    }
};

TEST_GROUP(Led_ActiveLow)
{
    Led led;
    LedParams params;
    LED_STATE led_state;
    LED_RETURN_CODE ret;
    ATTINY861_PIN pin;
    GPIO_STATE gpio_state;

    void setup()
    {
        params.initial_state = LED_OFF;
        params.active_state = LED_ACTIVE_LOW;
        pin = ATTN861_PB6;

        led = Led_Create(pin, &params);
    }

    void teardown()
    {
        Led_Destroy(&led);
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

TEST(Led, active_high_led_is_off_after_create)
{
    ret = Led_GetState(led1, &state1);

    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state1);
}

TEST(Led, can_turn_led1_on)
{
    ret = Led_TurnOn(led1);

    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_ON, state1);
}

TEST(Led, can_turn_led1_off)
{
    Led_TurnOn(led1);

    ret = Led_TurnOff(led1);

    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state1);
}

TEST(Led, can_turn_led2_on)
{
    Led_TurnOn(led2);

    ret = Led_TurnOff(led2);

    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state2);
}

TEST(Led, can_turn_led2_off)
{
    Led_TurnOn(led2);

    ret = Led_TurnOff(led2);

    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_SUCCESS, ret);
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

TEST(Led, can_toggle_an_led_on)
{
    ret = Led_Toggle(led1);

    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_ON, state1);
}

TEST(Led, can_toggle_an_led_on_and_off)
{
    Led_Toggle(led1);

    ret = Led_Toggle(led1);

    Led_GetState(led1, &state1);
    LONGS_EQUAL(LED_SUCCESS, ret);
    LONGS_EQUAL(LED_OFF, state1);
}

TEST(Led, can_toggle_two_leds)
{
    Led_Toggle(led1);
    Led_Toggle(led2);

    Led_GetState(led1, &state1);
    Led_GetState(led2, &state2);

    LONGS_EQUAL(LED_ON, state1);
    LONGS_EQUAL(LED_ON, state2);
}

TEST(Led, can_toggle_two_leds_in_opposing_states)
{
    Led_TurnOn(led1);

    Led_Toggle(led1);
    Led_Toggle(led2);

    Led_GetState(led1, &state1);
    Led_GetState(led2, &state2);
    LONGS_EQUAL(LED_OFF, state1);
    LONGS_EQUAL(LED_ON, state2);
}


/*
 * Validity checks
 */
TEST(Led, will_not_get_state_if_state_pointer_is_null)
{
    ret = Led_GetState(led1, NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}

TEST(Led, will_not_create_an_invalid_led)
{
    Led led = Led_Create(42, &params);
    CHECK_TRUE(led == NULL);
}

TEST(Led, will_not_create_with_null_params)
{
    Led led = Led_Create(ATTN861_PA7, NULL);
    CHECK_TRUE(led == NULL);
}

TEST(Led, do_not_turn_on_a_null_led)
{
    ret = Led_TurnOn(NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}

TEST(Led, do_not_turn_off_a_null_led)
{
    ret = Led_TurnOff(NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}

TEST(Led, do_not_toggle_a_null_led)
{
    ret = Led_Toggle(NULL);
    LONGS_EQUAL(LED_NULL_POINTER, ret);
}




/*
 * Active low Led
 */
TEST(Led_ActiveLow, can_create_active_low_led)
{
    CHECK_TRUE( led != NULL );
}

TEST(Led_ActiveLow, active_low_led_is_off_after_create)
{
    ret = Led_GetState(led, &led_state);

    ATtiny861_Gpio_GetState(ATTN861_PB6, &gpio_state);
    LONGS_EQUAL( GPIO_HIGH, gpio_state );
    LONGS_EQUAL( LED_OFF, led_state );
}

TEST(Led_ActiveLow, can_turn_led_on)
{
    Led_TurnOn(led);

    ATtiny861_Gpio_GetState(ATTN861_PB6, &gpio_state);
    Led_GetState(led, &led_state);
    LONGS_EQUAL( GPIO_LOW, gpio_state );
    LONGS_EQUAL( LED_ON, led_state );
}
