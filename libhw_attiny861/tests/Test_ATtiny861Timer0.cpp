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
    ATTN861_TIMER0_RETURN_CODE ret;

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
        .clock_source = ATTN861_TIMER0_STOPPED,
        .match_value = 123
    };
    ret = ATtiny861Timer0_Create(&params);

    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ret );
    BYTES_EQUAL( BIT_VALUE(CTC0), TCCR0A );
    BYTES_EQUAL( BIT_VALUE(OCIE0A), TIMSK );
    BYTES_EQUAL( params.match_value, OCR0A );
}

TEST(ATtiny861Timer0, can_not_pass_null_params_to_create)
{
    ret = ATtiny861Timer0_Create(NULL);
    LONGS_EQUAL( ATTN861_TIMER0_NULL_POINTER, ret );
}

TEST(ATtiny861Timer0, can_destroy_timer)
{
    ret = ATtiny861Timer0_Destroy();
    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ret );
}

TEST(ATtiny861Timer0, can_start_timer_using_system_clock)
{
    ATtiny861Timer0_Params params = {
        .clock_source = ATTN861_TIMER0_SYSTEM_CLOCK,
        .match_value = 123
    };
    uint8_t expected = 0;
    //TODO rewrite with SBI and CBI
    expected &= ~BIT_VALUE(CS02);
    expected &= ~BIT_VALUE(CS01);
    expected |= BIT_VALUE(CS00);

    ATtiny861Timer0_Create(&params);

    ret = ATtiny861Timer0_Start();

    LONGS_EQUAL( ATTN861_TIMER0_SUCCESS, ret );
    BYTES_EQUAL( expected, TCCR0B );
}
