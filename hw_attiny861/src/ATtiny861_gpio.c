#include "ATtiny861.h"
#include "BitManip.h"
#include <avr/io.h>
#include <stddef.h>

/*
 * We need to know:
 *  DDRxn
 *      x is the byte
 *      n is the bit
 *  PORTxn
 *      byte x
 *      bit n
 *  PINxn
 *      byte x
 *      bit n
 */

static volatile uint8_t * get_ddr_register(ATTN861_GPIO gpio)
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

static volatile uint8_t * get_port_register(ATTN861_GPIO gpio)
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

// Returns < 0 on error.
// You **MUST** check the return code!
// If the pin is invalid, you *will* set an undefined bit in memory.
static int8_t get_ddr_bit(ATTN861_GPIO gpio)
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
int8_t get_port_bit(ATTN861_GPIO gpio)
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

//TODO add a direction parameter
static ATTINY861_STATUS_CODE set_gpio_direction(volatile uint8_t * ddr, int8_t bit)
{
    if (ddr == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }
    if (bit < 0)
    {
        return ATTINY861_GPIO_INVALID;
    }

    SBI(*ddr, bit);

    return ATTINY861_SUCCESS;
}

static ATTINY861_STATUS_CODE set_gpio_state(volatile uint8_t * port, int8_t bit, GPIO_STATE state)
{
    if (port == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }
    if (bit < 0)
    {
        return ATTINY861_GPIO_INVALID;
    }
    //TODO check for invalid state

    if (state == GPIO_HIGH)
    {
        SBI(*port, bit);
    }
    else if (state == GPIO_LOW)
    {
        CBI(*port, bit);
    }

    return ATTINY861_SUCCESS;
}

ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    volatile uint8_t *ddr;
    int8_t ddr_bit;

    volatile uint8_t *port;
    int8_t port_bit;

    ATTINY861_STATUS_CODE ret;

    ddr = get_ddr_register(gpio);
    ddr_bit = get_ddr_bit(gpio);

    port = get_port_register(gpio);
    port_bit = get_port_bit(gpio);

    //TODO Extract this.
    ret = set_gpio_direction(ddr, ddr_bit);
    if (ret < 0)
    {
        return ret;
    }

    ret = set_gpio_state(port, port_bit, initial_state);
    if (ret < 0)
    {
        return ret;     // Uh oh.
    }

    return ATTINY861_SUCCESS;
}
void ATtiny861_GpioInit(void)
{
    // Pins should default to inputs on power-up.

    // The ATtiny861 datasheet, section 10.1.6 states that all unconnected pins
    // should be left as inputs and have their internal pull-up resistor driven high.
    PORTA = 0xff;
    PORTB = 0xff;
}

GPIO_STATE ATtiny861_GpioGetState(ATTN861_GPIO gpio)
{
    //TODO need to rewrite to use PIN bit!!

    volatile uint8_t * port_reg;
    int8_t port_bit;

    port_reg = get_port_register(gpio);
    if (port_reg == NULL)
    {
        return GPIO_INVALID;
    }
    port_bit = get_port_bit(gpio);
    if (port_bit < 0)
    {
        return GPIO_INVALID;
    }

    return GET_BIT(*port_reg, port_bit);
}
