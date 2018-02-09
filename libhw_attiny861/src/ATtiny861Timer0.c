#include "ATtiny861Timer0.h"
#include <avr/io.h>
#include "BitManip.h"

static int timer0_clock_source;

static void enable_8_bit_mode(void)
{
    // CBI(TCCR0A, TCW0);
}

// CTC: Clear Timer on Compare match
static void enable_clear_timer_on_compare_match(void)
{
    SBI(TCCR0A, CTC0);
}

static void enable_compare_match_A_interrupts(void)
{
    SBI(TIMSK, OCIE0A);
}

static void set_compare_A_match_value(uint8_t match_value)
{
    OCR0A = match_value;
}

// See ATtiny861 datasheet, Table 11-4. Clock Select Bit Description
static void set_clock_select_bits(int clock_source)
{
    switch (clock_source)
    {
        // case ATTN861_TIMER0_STOPPED:
        case ATTN861_TIMER0_INTERNAL_CLOCK:
            CBI(TCCR0B, CS02);
            CBI(TCCR0B, CS01);
            SBI(TCCR0B, CS00);
            break;
        case ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024:
            SBI(TCCR0B, CS02);
            CBI(TCCR0B, CS01);
            SBI(TCCR0B, CS00);
            break;
    }
}

ATTN861_TIMER0_RETURN_CODE ATtiny861Timer0_Create(ATtiny861Timer0_Params *params)
{
    if (!params)
    {
        return ATTN861_TIMER0_NULL_POINTER;
    }

    // Disable timer?
    enable_8_bit_mode();
    enable_clear_timer_on_compare_match();
    // CBI(TCCR0A, ICEN0);  // Disable input capture mode.
    enable_compare_match_A_interrupts();
    set_compare_A_match_value(params->match_value);
    // Clear Timer0 prescaler?

    // Do not set the clock source; this would enable the timer.
    // Start() does this.
    timer0_clock_source = params->clock_source;

    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_RETURN_CODE ATtiny861Timer0_Destroy(void)
{
    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_RETURN_CODE ATtiny861Timer0_Start(void)
{
    // Setting the clock source starts the timer.
    set_clock_select_bits(timer0_clock_source);
    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_RETURN_CODE ATtiny861Timer0_RegisterCallback_MatchA(TIMER0_CALLBACK callback)
{
    return ATTN861_TIMER0_SUCCESS;
}
