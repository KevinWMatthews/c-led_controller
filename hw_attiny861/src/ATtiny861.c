#include "ATtiny861.h"
#include "BitManip.h"

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
        SBI(DDRA, DDA0);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA0);
        else
            SBI(PORTA, PORTA0);
        break;
    case ATTN861_PA1:
        SBI(DDRA, DDA1);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA1);
        else
            SBI(PORTA, PORTA1);
        break;
    case ATTN861_PA2:
        SBI(DDRA, DDA2);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA2);
        else
            SBI(PORTA, PORTA2);
        break;
    case ATTN861_PB0:
        SBI(DDRB, DDB0);
        break;
    }
}
