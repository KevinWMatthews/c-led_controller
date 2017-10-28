extern "C"
{
#include "LedHw.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedHw_ATtiny861)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(LedHw_ATtiny861, initialize_led_1)
{
    LedHw_Init(LEDHW_LED_1);
}
