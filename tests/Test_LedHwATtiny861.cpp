extern "C"
{
#include "LedHw.h"
#include "ATtiny861.h"
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
        .withParameter("gpio", ATTN861_PA0)
        .withParameter("initial_state", GPIO_LOW);
    LedHw_Init(LEDHW_LED_1);
}

TEST(LedHw_ATtiny861, initialize_led_2)
{
    mock().expectOneCall("ATtiny861_GpioSetAsOutput")
        .withParameter("gpio", ATTN861_PA1)
        .withParameter("initial_state", GPIO_LOW);
    LedHw_Init(LEDHW_LED_2);
}
