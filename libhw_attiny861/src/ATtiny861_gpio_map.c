#include "ATtiny861_gpio_map.h"
#include <avr/io.h>
#include <stddef.h>

volatile uint8_t * ATtiny861GpioMap_GetDdrRegister(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
        case ATTN861_PA1:
        case ATTN861_PA2:
        case ATTN861_PA3:
        case ATTN861_PA4:
        case ATTN861_PA5:
        case ATTN861_PA6:
        case ATTN861_PA7:
            return &DDRA;

        case ATTN861_PB0:
        case ATTN861_PB1:
        case ATTN861_PB2:
        case ATTN861_PB3:
        case ATTN861_PB4:
        case ATTN861_PB5:
        case ATTN861_PB6:
        case ATTN861_PB7:
            return &DDRB;

        default:
            return NULL;
    }
    return NULL;
}

volatile uint8_t * ATtiny861GpioMap_GetPortRegister(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
        case ATTN861_PA1:
        case ATTN861_PA2:
        case ATTN861_PA3:
        case ATTN861_PA4:
        case ATTN861_PA5:
        case ATTN861_PA6:
        case ATTN861_PA7:
            return &PORTA;
        case ATTN861_PB0:
        case ATTN861_PB1:
        case ATTN861_PB2:
        case ATTN861_PB3:
        case ATTN861_PB4:
        case ATTN861_PB5:
        case ATTN861_PB6:
        case ATTN861_PB7:
            return &PORTB;
        default:
            return NULL;
    }
    return NULL;
}

int8_t ATtiny861GpioMap_GetDdrBit(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
            return DDA0;
        case ATTN861_PA1:
            return DDA1;
        case ATTN861_PA2:
            return DDA2;
        case ATTN861_PA3:
            return DDA3;
        case ATTN861_PA4:
            return DDA4;
        case ATTN861_PA5:
            return DDA5;
        case ATTN861_PA6:
            return DDA6;
        case ATTN861_PA7:
            return DDA7;

        case ATTN861_PB0:
            return DDB0;
        case ATTN861_PB1:
            return DDB1;
        case ATTN861_PB2:
            return DDB2;
        case ATTN861_PB3:
            return DDB3;
        case ATTN861_PB4:
            return DDB4;
        case ATTN861_PB5:
            return DDB5;
        case ATTN861_PB6:
            return DDB6;
        case ATTN861_PB7:
            return DDB7;

        default:
            return -1;
    }
    return -1;
}

// Returns < 0 on error.
// You **MUST** check the return code!
// If the pin is invalid, you *will* set an undefined bit in memory.
int8_t ATtiny861GpioMap_GetPortBit(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
            return PORTA0;
        case ATTN861_PA1:
            return PORTA1;
        case ATTN861_PA2:
            return PORTA2;
        case ATTN861_PA3:
            return PORTA3;
        case ATTN861_PA4:
            return PORTA4;
        case ATTN861_PA5:
            return PORTA5;
        case ATTN861_PA6:
            return PORTA6;
        case ATTN861_PA7:
            return PORTA7;

        case ATTN861_PB0:
            return PORTB0;
        case ATTN861_PB1:
            return PORTB1;
        case ATTN861_PB2:
            return PORTB2;
        case ATTN861_PB3:
            return PORTB3;
        case ATTN861_PB4:
            return PORTB4;
        case ATTN861_PB5:
            return PORTB5;
        case ATTN861_PB6:
            return PORTB6;
        case ATTN861_PB7:
            return PORTB7;

        default:
            return -1;
    }
    return -1;
}
