#include "ATtiny861.h"

void ATtiny861_GpioInit(void)
{
    // Pins should default to inputs on power-up.

    // The ATtiny861 datasheet, section 10.1.6 states that all unconnected pins
    // should be left as inputs and have their internal pull-up resistor driven high.
    PORTA = 0xff;
    PORTB = 0xff;
}

void ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    switch (gpio)
    {
    case ATTN861_PA0:
        DDRA |= (1<<DDA0);
        if (initial_state == GPIO_LOW)
            PORTA &= ~(1<<PORTA0);
        else
            PORTA |= (1<<PORTA0);
        break;
    case ATTN861_PA1:
        DDRA |= (1<<DDA1);
        if (initial_state == GPIO_LOW)
            PORTA &= ~(1<<PORTA1);
        else
            PORTA |= (1<<PORTA1);
        break;
    case ATTN861_PA2:
        DDRA |= (1<<DDA2);
        if (initial_state == GPIO_LOW)
            PORTA &= ~(1<<PORTA2);
        else
            PORTA |= (1<<PORTA2);
        break;
    case ATTN861_PB0:
        DDRB |= (1<<DDB0);
        break;
    }
}
