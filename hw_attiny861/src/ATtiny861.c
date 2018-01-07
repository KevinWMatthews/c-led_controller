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
 *
 * Can use a switch statement or structures.
 */

static volatile uint8_t * get_ddr_register(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
            return &DDRA;
    }
    return NULL;
}

static volatile uint8_t * get_port_register(ATTN861_GPIO gpio)
{
    switch (gpio)
    {
        case ATTN861_PA0:
            return &PORTA;
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
