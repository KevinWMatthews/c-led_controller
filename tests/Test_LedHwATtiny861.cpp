extern "C"
{
#include "LedHw.h"
#include "ATtiny861Gpio.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(LedHw_ATtiny861)
{
    void setup()
    {
        mock().strictOrder();
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(LedHw_ATtiny861, initialize_led_1)
{
    mock().expectOneCall("ATtiny861_GpioSetAsOutput")
        .withParameter("gpio", ATTN861_PA7)
        .withParameter("initial_state", GPIO_LOW);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_Init(LEDHW_LED_1) );
}

TEST(LedHw_ATtiny861, initialize_led_2)
{
    mock().expectOneCall("ATtiny861_GpioSetAsOutput")
        .withParameter("gpio", ATTN861_PA6)
        .withParameter("initial_state", GPIO_LOW);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_Init(LEDHW_LED_2) );
}

TEST(LedHw_ATtiny861, initialize_invalid_led)
{
    LONGS_EQUAL( LEDHW_INVALID_LED, LedHw_Init(LEDHW_LED_MAX) );
}

TEST(LedHw_ATtiny861, turn_led_on)
{
    mock().expectOneCall("ATtiny861_GpioSetState")
        .withParameter("gpio", ATTN861_PA7)
        .withParameter("state", GPIO_HIGH);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_TurnOn(LEDHW_LED_1) );
}

TEST(LedHw_ATtiny861, turn_second_led_on)
{
    mock().expectOneCall("ATtiny861_GpioSetState")
        .withParameter("gpio", ATTN861_PA6)
        .withParameter("state", GPIO_HIGH);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_TurnOn(LEDHW_LED_2) );
}

TEST(LedHw_ATtiny861, turn_on_can_handle_invalid_led)
{
    LONGS_EQUAL( LEDHW_INVALID_LED, LedHw_TurnOn(LEDHW_LED_MAX) );
}

TEST(LedHw_ATtiny861, turn_led_off)
{
    mock().expectOneCall("ATtiny861_GpioSetState")
        .withParameter("gpio", ATTN861_PA7)
        .withParameter("state", GPIO_LOW);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_TurnOff(LEDHW_LED_1) );
}

TEST(LedHw_ATtiny861, turn_second_led_off)
{
    mock().expectOneCall("ATtiny861_GpioSetState")
        .withParameter("gpio", ATTN861_PA6)
        .withParameter("state", GPIO_LOW);
    LONGS_EQUAL( LEDHW_SUCCESS, LedHw_TurnOff(LEDHW_LED_2) );
}

TEST(LedHw_ATtiny861, turn_off_can_handle_invalid_led)
{
    LONGS_EQUAL( LEDHW_INVALID_LED, LedHw_TurnOff(LEDHW_LED_MAX) );
}
