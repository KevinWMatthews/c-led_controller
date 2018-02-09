#ifndef MOCK_ATTINY861_TIMER0_INCLUDED
#define MOCK_ATTINY861_TIMER0_INCLUDED

// Execute the Timer/Counter0 Compare Match A, if configured.
void Mock_ATtiny861Timer0_CompareMatchA(void);

/*
 * Expose the individual interrupts so that the Mock can execute them.
 * See the mock <avr/io.h> for the convention for naming interrupts and
 * <avr/interrupt.h> for the definition of ISR.
 */
void vector_14_TIMER0_COMPA(void);

#endif
