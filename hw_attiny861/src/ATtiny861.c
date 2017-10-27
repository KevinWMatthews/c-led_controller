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

static void set_gpio_as_output(uint8_t * port, uint8_t pin)
{
    SBI(*port, pin);
}

static void set_gpio_high(uint8_t * port, uint8_t pin)
{
    SBI(*port, pin);
}

void ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    switch (gpio)
    {
    case ATTN861_PA0:
        // This provides useful information
        set_gpio_as_output(&DDRA, DDA0);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA0);
        else
            // This doesn't gain us much; SBI is pretty clear
            set_gpio_high(&PORTA, PORTA0);
        break;
    case ATTN861_PA1:
        set_gpio_as_output(&DDRA, DDA1);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA1);
        else
            set_gpio_high(&PORTA, PORTA1);
        break;
    case ATTN861_PA2:
        set_gpio_as_output(&DDRA, DDA2);
        if (initial_state == GPIO_LOW)
            CBI(PORTA, PORTA2);
        else
            set_gpio_high(&PORTA, PORTA1);
        break;
    case ATTN861_PB0:
        set_gpio_as_output(&DDRB, DDB0);
        break;
    }
}
