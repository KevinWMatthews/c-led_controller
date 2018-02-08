#include "ATtiny861Timer0.h"
#include <avr/io.h>
#include "BitManip.h"

static void enable_8_bit_mode(void)
{
    SBI(TCCR0A, TCW0);
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

ATTN861_TIMER0_STATUS_CODE ATtiny861Timer_Timer0_Create(ATtiny861Timer0_Params *params)
{
    // Disable timer?
    enable_8_bit_mode();
    enable_clear_timer_on_compare_match();
    // CBI(TCCR0A, ICEN0);  // Disable input capture mode.
    enable_compare_match_A_interrupts();
    set_compare_A_match_value(params->match_value);
    // Clear Timer0 prescaler?
    // Do not enable timer. Start() does this.
    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_STATUS_CODE ATtiny861Timer_Timer0_Destroy(void)
{
    return ATTN861_TIMER0_SUCCESS;
}
