extern "C"
{
#include "ATtiny861Timer0.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtiny861Timer0)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ATtiny861Timer0, can_create_timer)
{
    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ATtiny861Timer_Timer0_Create() );
}

TEST(ATtiny861Timer0, can_destroy_timer)
{
    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ATtiny861Timer_Timer0_Destroy() );
}
