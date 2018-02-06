#include <avr/io.h>         // For register definitions
#include <avr/interrupt.h>  // For sei()
#include "BitManip.h"

int main(void)
{
    // Generate an interrupt request for INT0
    SBI(GIMSK, INT0);

    // Set interrupt direction
    SBI(MCUCR, ISC01);  // Falling edge
    CBI(MCUCR, ISC00);

    // Configure interrupt flag
    //TODO Experiment with removing this.
    SBI(GIFR, INTF0);

    // Enable global interrupts
    sei();

    return 0;
}

// Define an interrupt handler
// See avr/interrupt.h for funciton declaration, avr/io.h for various vectors
ISR(INT0_vect)
{
    ;
}
