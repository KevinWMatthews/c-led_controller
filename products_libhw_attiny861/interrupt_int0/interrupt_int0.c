#include <avr/io.h>         // For register definitions
#include <avr/interrupt.h>  // For sei()


int main(void)
{
    // Enable LED, for testing
    DDRA |= _BV(DDA0);          // Set direction
    PORTA |= _BV(PORTA0);       // Drive output high

    // Set interrupt pin as input with internal pull-up (I think)
    DDRB &= ~_BV(DDB6);         // Set direction
    PORTB |= _BV(PORTB6);       // Enable internal pull-up

    // Generate an interrupt request for INT0
    GIMSK |= _BV(INT0);

    // Configure interrupt flag
    GIFR |= _BV(INTF0);

    // Set interrupt direction
    MCUCR &= ~_BV(ISC01);
    MCUCR |= _BV(ISC00);

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
