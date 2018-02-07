#ifndef ATTINY861_TIMER_INCLUDED
#define ATTINY861_TIMER_INCLUDED

typedef enum
{
    ATTN861_TIMER_SUCCESS   = 0
} ATTN861_TIMER_STATUS_CODE;

/*
 * Create a Timer using the ATtiny's Timer/Counter0.
 *
 * Can not be created again without first being destroyed -
 * there is only a single Timer0 available in hardware.
 */
ATTN861_TIMER_STATUS_CODE ATtiny861Timer_Timer0_Create(void);

/*
 * Destroy Timer0.
 *
 * Multiple destroys have no effect.
 */
ATTN861_TIMER_STATUS_CODE ATtiny861Timer_Timer0_Destroy(void);

#endif
