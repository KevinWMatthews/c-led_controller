#include "ATtiny861_GpioMap.h"
#include <avr/io.h>
#include <stddef.h>

volatile uint8_t * ATtiny861_GpioMap_GetDdrRegister(ATTINY861_PIN pin)
{
    switch (pin)
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

ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetDdrBit(ATTINY861_PIN pin, uint8_t * bit_number)
{
    if (bit_number == NULL)
    {
        return ATTINY861_GPIOMAP_NULL_POINTER;
    }

    switch (pin)
    {
        case ATTN861_PA0:
            *bit_number = DDA0;
            break;
        case ATTN861_PA1:
            *bit_number = DDA1;
            break;
        case ATTN861_PA2:
            *bit_number = DDA2;
            break;
        case ATTN861_PA3:
            *bit_number = DDA3;
            break;
        case ATTN861_PA4:
            *bit_number = DDA4;
            break;
        case ATTN861_PA5:
            *bit_number = DDA5;
            break;
        case ATTN861_PA6:
            *bit_number = DDA6;
            break;
        case ATTN861_PA7:
            *bit_number = DDA7;
            break;

        case ATTN861_PB0:
            *bit_number = DDB0;
            break;
        case ATTN861_PB1:
            *bit_number = DDB1;
            break;
        case ATTN861_PB2:
            *bit_number = DDB2;
            break;
        case ATTN861_PB3:
            *bit_number = DDB3;
            break;
        case ATTN861_PB4:
            *bit_number = DDB4;
            break;
        case ATTN861_PB5:
            *bit_number = DDB5;
            break;
        case ATTN861_PB6:
            *bit_number = DDB6;
            break;
        case ATTN861_PB7:
            *bit_number = DDB7;
            break;

        default:
            return ATTINY861_GPIOMAP_INVALID_PIN;
    }
    return ATTINY861_GPIOMAP_SUCCESS;
}

volatile uint8_t * ATtiny861_GpioMap_GetPortRegister(ATTINY861_PIN pin)
{
    switch (pin)
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

// Returns < 0 on error.
// You **MUST** check the return code!
// If the pin is invalid, you *will* set an undefined bit in memory.
int8_t ATtiny861_GpioMap_GetPortBit(ATTINY861_PIN pin)
{
    switch (pin)
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

ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetPortBit2(ATTINY861_PIN pin, uint8_t * bit_number)
{
    if (bit_number == NULL)
    {
        return ATTINY861_GPIOMAP_NULL_POINTER;
    }

    switch (pin)
    {
        case ATTN861_PA0:
            *bit_number = PORTA0;
            break;
        case ATTN861_PA1:
            *bit_number = PORTA1;
            break;
        case ATTN861_PA2:
            *bit_number = PORTA2;
            break;
        case ATTN861_PA3:
            *bit_number = PORTA3;
            break;
        case ATTN861_PA4:
            *bit_number = PORTA4;
            break;
        case ATTN861_PA5:
            *bit_number = PORTA5;
            break;
        case ATTN861_PA6:
            *bit_number = PORTA6;
            break;
        case ATTN861_PA7:
            *bit_number = PORTA7;
            break;

        case ATTN861_PB0:
            *bit_number = PORTB0;
            break;
        case ATTN861_PB1:
            *bit_number = PORTB1;
            break;
        case ATTN861_PB2:
            *bit_number = PORTB2;
            break;
        case ATTN861_PB3:
            *bit_number = PORTB3;
            break;
        case ATTN861_PB4:
            *bit_number = PORTB4;
            break;
        case ATTN861_PB5:
            *bit_number = PORTB5;
            break;
        case ATTN861_PB6:
            *bit_number = PORTB6;
            break;
        case ATTN861_PB7:
            *bit_number = PORTB7;
            break;

        default:
            return ATTINY861_GPIOMAP_INVALID_PIN;
    }

    return ATTINY861_GPIOMAP_SUCCESS;
}

volatile uint8_t * ATtiny861_GpioMap_GetPinRegister(ATTINY861_PIN pin)
{
    switch (pin)
    {
        case ATTN861_PA0:
        case ATTN861_PA1:
        case ATTN861_PA2:
        case ATTN861_PA3:
        case ATTN861_PA4:
        case ATTN861_PA5:
        case ATTN861_PA6:
        case ATTN861_PA7:
            return &PINA;
        case ATTN861_PB0:
        case ATTN861_PB1:
        case ATTN861_PB2:
        case ATTN861_PB3:
        case ATTN861_PB4:
        case ATTN861_PB5:
        case ATTN861_PB6:
        case ATTN861_PB7:
            return &PINB;
    }
    return NULL;
}

int8_t ATtiny861_GpioMap_GetPinBit(ATTINY861_PIN pin)
{
    switch (pin)
    {
        case ATTN861_PA0:
            return PINA0;
        case ATTN861_PA1:
            return PINA1;
        case ATTN861_PA2:
            return PINA2;
        case ATTN861_PA3:
            return PINA3;
        case ATTN861_PA4:
            return PINA4;
        case ATTN861_PA5:
            return PINA5;
        case ATTN861_PA6:
            return PINA6;
        case ATTN861_PA7:
            return PINA7;
        case ATTN861_PB0:
            return PINB0;
        case ATTN861_PB1:
            return PINB1;
        case ATTN861_PB2:
            return PINB2;
        case ATTN861_PB3:
            return PINB3;
        case ATTN861_PB4:
            return PINB4;
        case ATTN861_PB5:
            return PINB5;
        case ATTN861_PB6:
            return PINB6;
        case ATTN861_PB7:
            return PINB7;
    }
    return -1;
}
