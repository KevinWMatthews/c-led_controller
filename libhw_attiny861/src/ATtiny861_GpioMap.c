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

ATTINY861_RETURN_CODE ATtiny861_GpioMap_GetDdrBit(ATTINY861_PIN pin, uint8_t * bit_number)
{
    if (bit_number == NULL)
    {
        return ATTINY861_NULL_POINTER;
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
            return ATTINY861_PIN_INVALID;
    }
    return ATTINY861_SUCCESS;
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

ATTINY861_RETURN_CODE ATtiny861_GpioMap_GetPortBit(ATTINY861_PIN pin, uint8_t * bit_number)
{
    if (bit_number == NULL)
    {
        return ATTINY861_NULL_POINTER;
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
            return ATTINY861_PIN_INVALID;
    }

    return ATTINY861_SUCCESS;
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

ATTINY861_RETURN_CODE ATtiny861_GpioMap_GetPinBit(ATTINY861_PIN pin, uint8_t * bit_number)
{
    if (bit_number == NULL)
    {
        return ATTINY861_NULL_POINTER;
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
            *bit_number = PINB0;
            break;
        case ATTN861_PB1:
            *bit_number = PINB1;
            break;
        case ATTN861_PB2:
            *bit_number = PINB2;
            break;
        case ATTN861_PB3:
            *bit_number = PINB3;
            break;
        case ATTN861_PB4:
            *bit_number = PINB4;
            break;
        case ATTN861_PB5:
            *bit_number = PINB5;
            break;
        case ATTN861_PB6:
            *bit_number = PINB6;
            break;
        case ATTN861_PB7:
            *bit_number = PINB7;
            break;

        default:
            return ATTINY861_PIN_INVALID;
    }
    return ATTINY861_SUCCESS;
}
