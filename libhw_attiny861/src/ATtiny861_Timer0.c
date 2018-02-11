#include "ATtiny861_Timer0.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*
 * File-scope variables.
 */
static int timer0_clock_source;
static TIMER0_CALLBACK timer0_match_a_callback;

static void enable_8_bit_mode(void)
{
    // TCCR0A &= ~_BV(TCW0);
}

// CTC: Clear Timer on Compare match
static void enable_clear_timer_on_compare_match(void)
{
    TCCR0A |= _BV(CTC0);
}

static void enable_compare_match_A_interrupts(void)
{
    TIMSK |= _BV(OCIE0A);
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
            TCCR0B &= ~_BV(CS02);
            TCCR0B &= ~_BV(CS01);
            TCCR0B |= _BV(CS00);
            break;
        case ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024:
            TCCR0B |= _BV(CS02);
            TCCR0B &= ~_BV(CS01);
            TCCR0B |= _BV(CS00);
            break;
    }
}

ATTN861_TIMER0_RETURN_CODE ATtiny861_Timer0_Create(ATtiny861_Timer0_Params *params)
{
    if (!params)
    {
        return ATTN861_TIMER0_NULL_POINTER;
    }

    // Disable timer?
    enable_8_bit_mode();
    enable_clear_timer_on_compare_match();
    // TCCR0A &= ~_BV(ICEN0);  // Disable input capture mode.
    enable_compare_match_A_interrupts();
    set_compare_A_match_value(params->match_value_A);
    // Clear Timer0 prescaler?

    // Do not set the clock source; this would enable the timer.
    // Start() does this.
    timer0_clock_source = params->clock_source;

    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_RETURN_CODE ATtiny861_Timer0_Start(void)
{
    // Setting the clock source starts the timer.
    set_clock_select_bits(timer0_clock_source);
    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_RETURN_CODE ATtiny861_Timer0_RegisterCallback_MatchA(TIMER0_CALLBACK callback)
{
    timer0_match_a_callback = callback;
    return ATTN861_TIMER0_SUCCESS;
}

ISR(TIMER0_COMPA_vect)
{
    if (timer0_match_a_callback)
    {
        timer0_match_a_callback();
    }
}
