#include "ATtiny861Gpio.h"
#include <avr/interrupt.h>

int main(void)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    // Set to 8-bit mode
    // Disable input capture mode
    // Set to compare mode
    TCCR0A = (1<<CTC0);
    // Enable Timer 0 Compare Match A interrupts
    TIMSK = (1<<OCIE0A);

    // Set counter value
    OCR0A = 255;

    // Reset counter register
    TCNT0L = 0;

    // Reset prescaler
    TCCR0B |= (1<<PSR0);

    // Set clock source to internal system, prescaler 1024
    TCCR0B = (1<<CS02) | (1<<CS00);

    // Enable interrupts
    sei();

    while (1)
        ;

    return 0;
}

static unsigned char led_state;

ISR(TIMER0_COMPA_vect)
{
    if (led_state)
    {
        ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);
        led_state = 0;
    }
    else
    {
        ATtiny861_GpioSetState(ATTN861_PA0, GPIO_HIGH);
        led_state = 1;
    }
}
