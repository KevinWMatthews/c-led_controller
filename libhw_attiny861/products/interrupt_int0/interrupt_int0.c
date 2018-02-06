#include <avr/io.h>         // For register definitions
#include <avr/interrupt.h>  // For sei()
#include "BitManip.h"


int main(void)
{
    // Enable LED, for testing
    SBI(DDRA, DDA0);        // Set direction
    SBI(PORTA, PORTA0);     // Drive output high

    // Set interrupt pin as input with internal pull-up (I think)
    CBI(DDRB, DDB6);        // Set direction
    SBI(PORTB, PORTB6);     // Enable internal pull-up

    // Generate an interrupt request for INT0
    SBI(GIMSK, INT0);

    // Configure interrupt flag
    SBI(GIFR, INTF0);

    // Set interrupt direction
    CBI(MCUCR, ISC01);
    SBI(MCUCR, ISC00);

    // Enable global interrupts
    sei();

    while (1)
    {
        ;   // Hang on!
    }

    return 0;
}

// Define an interrupt handler
// See avr/interrupt.h for funciton declaration, avr/io.h for various vectors
ISR(INT0_vect)
{
    PORTA ^= _BV(PORTA0);
}
