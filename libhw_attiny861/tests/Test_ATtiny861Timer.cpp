extern "C"
{
#include "ATtiny861Timer.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtiny861Timer)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ATtiny861Timer, can_create_timer)
{
    LONGS_EQUAL( ATTN861_TIMER_SUCCESS, ATtiny861Timer_Timer0_Create() );
}

TEST(ATtiny861Timer, can_destroy_timer)
{
    LONGS_EQUAL( ATTN861_TIMER_SUCCESS, ATtiny861Timer_Timer0_Destroy() );
}
