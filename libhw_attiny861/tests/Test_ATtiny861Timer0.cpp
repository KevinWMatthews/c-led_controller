extern "C"
{
#include "ATtiny861Timer0.h"
// #include "MockHw_ATtiny861.h"
#include <avr/io.h>
}

//TODO where to put this?
#define BIT_VALUE(bit_number)   (1<<(bit_number))

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
    ATtiny861Timer0_Params params = {
        .match_value = 123
    };
    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ATtiny861Timer0_Create(&params) );
    BYTES_EQUAL( BIT_VALUE(TCW0) | BIT_VALUE(CTC0), TCCR0A );
    BYTES_EQUAL( BIT_VALUE(OCIE0A), TIMSK );
    BYTES_EQUAL( params.match_value, OCR0A );
}

TEST(ATtiny861Timer0, can_not_pass_null_params_to_create)
{
    LONGS_EQUAL( ATTN861_TIMER0_NULL_POINTER, ATtiny861Timer0_Create(NULL) );
}

TEST(ATtiny861Timer0, can_destroy_timer)
{
    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ATtiny861Timer0_Destroy() );
}
