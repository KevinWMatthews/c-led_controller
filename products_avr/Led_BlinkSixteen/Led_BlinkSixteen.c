#include "Avr_Led_BlinkSixteen_Config.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    // Configure Timer0
    TCCR0A &= ~_BV(TCW0);   // Enable 8-bit mode
    TCCR0A |= _BV(CTC0);    // CTC mode; clear timer on compare match rather than overflowing
    TIMSK |= _BV(OCIE0A);   // Enable Compare Match A interrupts
    OCR0A = 255;            // Set Compare Register A match value: 1 MHz / (1024*255) = 3.83 Hz

    // Configure PA0 as gpio
    DDRA |= _BV(DDA0);          // Set PA0 as output
    PORTA &= ~(_BV(PORTA0));    // Set initial state low

    // Configure PA1 as gpio
    DDRA |= _BV(DDA1);          // Set PA1 as output
    PORTA &= ~(_BV(PORTA1));    // Set initial state low

    // Configure PA2 as gpio
    DDRA |= _BV(DDA2);          // Set PA2 as output
    PORTA &= ~(_BV(PORTA2));    // Set initial state low

    // Configure PA3 as gpio
    DDRA |= _BV(DDA3);          // Set PA3 as output
    PORTA &= ~(_BV(PORTA3));    // Set initial state low

    // Configure PA4 as gpio
    DDRA |= _BV(DDA4);          // Set PA4 as output
    PORTA &= ~(_BV(PORTA4));    // Set initial state low

    // Configure PA5 as gpio
    DDRA |= _BV(DDA5);          // Set PA5 as output
    PORTA &= ~(_BV(PORTA5));    // Set initial state low

    // Configure PA6 as gpio
    DDRA |= _BV(DDA6);          // Set PA6 as output
    PORTA &= ~(_BV(PORTA6));    // Set initial state low

    // Configure PA7 as gpio
    DDRA |= _BV(DDA7);          // Set PA7 as output
    PORTA &= ~(_BV(PORTA7));    // Set initial state low


    // Configure PB0 as gpio
    DDRB |= _BV(DDB0);          // Set PB0 as output
    PORTB &= ~(_BV(PORTB0));    // Set initial state low

    // Configure PB1 as gpio
    DDRB |= _BV(DDB1);          // Set PB1 as output
    PORTB &= ~(_BV(PORTB1));    // Set initial state low

    // Configure PB2 as gpio
    DDRB |= _BV(DDB2);          // Set PB2 as output
    PORTB &= ~(_BV(PORTB2));    // Set initial state low

    // Configure PB3 as gpio
    DDRB |= _BV(DDB3);          // Set PB3 as output
    PORTB &= ~(_BV(PORTB3));    // Set initial state low

    // Configure PB4 as gpio
    DDRB |= _BV(DDB4);          // Set PB4 as output
    PORTB &= ~(_BV(PORTB4));    // Set initial state low

    // Configure PB5 as gpio
    DDRB |= _BV(DDB5);          // Set PB5 as output
    PORTB &= ~(_BV(PORTB5));    // Set initial state low

    // Configure PB6 as gpio
    DDRB |= _BV(DDB6);          // Set PB6 as output
    PORTB &= ~(_BV(PORTB6));    // Set initial state low

    // Configure PB7 as gpio
    DDRB |= _BV(DDB7);          // Set PB7 as output
    PORTB &= ~(_BV(PORTB7));    // Set initial state low


    // Start timer
    TCCR0B |= _BV(CS02) | _BV(CS00);    // Start timer with prescaler 1024

    // Enable interrupts
    sei();

    while (1)
        ;

    return 0;
}

ISR(TIMER0_COMPA_vect)
{
    // Toggle PA0
    PINA |= _BV(PINA0);
    // Toggle PA1
    PINA |= _BV(PINA1);
    // Toggle PA2
    PINA |= _BV(PINA2);
    // Toggle PA3
    PINA |= _BV(PINA3);
    // Toggle PA4
    PINA |= _BV(PINA4);
    // Toggle PA5
    PINA |= _BV(PINA5);
    // Toggle PA6
    PINA |= _BV(PINA6);
    // Toggle PA7
    PINA |= _BV(PINA7);

    // Toggle PB0
    PINB |= _BV(PINB0);
    // Toggle PB1
    PINB |= _BV(PINB1);
    // Toggle PB2
    PINB |= _BV(PINB2);
    // Toggle PB3
    PINB |= _BV(PINB3);
    // Toggle PB4
    PINB |= _BV(PINB4);
    // Toggle PB5
    PINB |= _BV(PINB5);
    // Toggle PB6
    PINB |= _BV(PINB6);
    // Toggle PB7
    PINB |= _BV(PINB7);
}
