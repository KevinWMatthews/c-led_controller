#include "ATtiny861Gpio.h"
#include "ATtiny861_gpio_map.h"
#include "BitManip.h"
#include <avr/io.h>
#include <stddef.h>

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

ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state)
{
    volatile uint8_t *ddr;
    int8_t ddr_bit;

    volatile uint8_t *port;
    int8_t port_bit;

    ATTINY861_STATUS_CODE ret;

    ddr = ATtiny861GpioMap_GetDdrRegister(pin);
    ddr_bit = ATtiny861GpioMap_GetDdrBit(pin);

    port = ATtiny861GpioMap_GetPortRegister(pin);
    port_bit = ATtiny861GpioMap_GetPortBit(pin);

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
    //TODO I wonder if these references could/should be extracted?
}

ATTINY861_STATUS_CODE ATtiny861_GpioSetState(ATTINY861_PIN pin, GPIO_STATE state)
{
    volatile uint8_t *port;
    int8_t port_bit;

    ATTINY861_STATUS_CODE ret;

    port = ATtiny861GpioMap_GetPortRegister(pin);
    port_bit = ATtiny861GpioMap_GetPortBit(pin);

    ret = set_gpio_state(port, port_bit, state);
    if (ret < 0)
    {
        return ret;     // Uh oh.
    }

    return ATTINY861_SUCCESS;
}

GPIO_STATE ATtiny861_GpioGetState(ATTINY861_PIN pin)
{
    //TODO need to rewrite to use PIN bit!!

    volatile uint8_t * port_reg;
    int8_t port_bit;

    port_reg = ATtiny861GpioMap_GetPortRegister(pin);
    if (port_reg == NULL)
    {
        return GPIO_INVALID;
    }
    port_bit = ATtiny861GpioMap_GetPortBit(pin);
    if (port_bit < 0)
    {
        return GPIO_INVALID;
    }

    return GET_BIT(*port_reg, port_bit);
}
