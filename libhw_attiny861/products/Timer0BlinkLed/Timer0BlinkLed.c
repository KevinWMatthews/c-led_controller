#include "ATtiny861Gpio.h"
#include "ATtiny861Timer0.h"
#include <avr/interrupt.h>

int main(void)
{
    ATtiny861Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_SYSTEM_CLOCK,
        .match_value = 0xff
    };

    ATtiny861Timer0_Create(&timer0_params);
    ATtiny861Timer0_Start();

    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

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