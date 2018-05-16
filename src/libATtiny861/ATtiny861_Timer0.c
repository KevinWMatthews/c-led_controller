#include "ATtiny861_Timer0.h"
#include "BitManip.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/*
 * File-scope variables.
 */
static int timer0_clock_source;
static TIMER0_CALLBACK timer0_match_a_callback;

static void enable_8_bit_mode(void)
{
    // CLEAR_BIT(TCCR0A, TCW0);
}

// CTC: Clear Timer on Compare match
static void enable_clear_timer_on_compare_match(void)
{
    SET_BIT(TCCR0A, CTC0);
}

static void enable_compare_match_A_interrupts(void)
{
    SET_BIT(TIMSK, OCIE0A);
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
            CLEAR_BIT(TCCR0B, CS02);
            CLEAR_BIT(TCCR0B, CS01);
            SET_BIT(TCCR0B, CS00);
            break;
        case ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024:
            SET_BIT(TCCR0B, CS02);
            CLEAR_BIT(TCCR0B, CS01);
            SET_BIT(TCCR0B, CS00);
            break;
    }
}

ATTINY861_RETURN_CODE ATtiny861_Timer0_Create(ATtiny861_Timer0_Params *params)
{
    if (!params)
    {
        return ATTINY861_NULL_POINTER;
    }

    // Disable timer?
    enable_8_bit_mode();
    enable_clear_timer_on_compare_match();
    // CLEAR_BIT(TCCR0A, ICEN0);  // Disable input capture mode.
    enable_compare_match_A_interrupts();
    set_compare_A_match_value(params->match_value_A);
    // Clear Timer0 prescaler?

    // Do not set the clock source; this would enable the timer.
    // Start() does this.
    timer0_clock_source = params->clock_source;

    return ATTINY861_SUCCESS;
}

void ATtiny861_Timer0_Start(void)
{
    // Setting the clock source starts the timer.
    set_clock_select_bits(timer0_clock_source);
}

ATTINY861_RETURN_CODE ATtiny861_Timer0_RegisterCallback_MatchA(TIMER0_CALLBACK callback)
{
    timer0_match_a_callback = callback;
    return ATTINY861_SUCCESS;
}

ISR(TIMER0_COMPA_vect)
{
    if (timer0_match_a_callback)
    {
        timer0_match_a_callback();
    }
}
