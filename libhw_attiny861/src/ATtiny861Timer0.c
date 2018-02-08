#include "ATtiny861Timer0.h"
#include <avr/io.h>
#include "BitManip.h"

ATTN861_TIMER0_STATUS_CODE ATtiny861Timer_Timer0_Create(ATtiny861Timer0_Params *params)
{
    // Disable timer?
    SBI(TCCR0A, TCW0);
    SBI(TCCR0A, CTC0);
    // CBI(TCCR0A, ICEN0);
    SBI(TIMSK, OCIE0A);
    OCR0A = params->match_value;
    // Clear Timer0 prescaler?
    // SBI(CS02
    return ATTN861_TIMER0_SUCCESS;
}

ATTN861_TIMER0_STATUS_CODE ATtiny861Timer_Timer0_Destroy(void)
{
    return ATTN861_TIMER0_SUCCESS;
}
