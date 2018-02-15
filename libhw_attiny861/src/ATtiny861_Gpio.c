#include "ATtiny861_Gpio.h"
#include "ATtiny861_GpioMap.h"
#include "BitManip.h"       // will replace avr/io.h
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

    SET_BIT(*ddr, bit);

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
        SET_BIT(*port, bit);
    }
    else if (state == GPIO_LOW)
    {
        CLEAR_BIT(*port, bit);
    }

    return ATTINY861_SUCCESS;
}

ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state)
{
    volatile uint8_t *ddr;
    uint8_t ddr_bit;

    volatile uint8_t *port;
    int8_t port_bit;

    ATTINY861_STATUS_CODE ret;
    ATTINY861_GPIOMAP_STATUS_CODE gpiomap_ret;

    ddr = ATtiny861_GpioMap_GetDdrRegister(pin);
    gpiomap_ret = ATtiny861_GpioMap_GetDdrBit(pin, &ddr_bit);
    if (gpiomap_ret < 0)
    {
        return gpiomap_ret;
    }

    port = ATtiny861_GpioMap_GetPortRegister(pin);
    port_bit = ATtiny861_GpioMap_GetPortBit(pin);

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

    port = ATtiny861_GpioMap_GetPortRegister(pin);
    port_bit = ATtiny861_GpioMap_GetPortBit(pin);

    ret = set_gpio_state(port, port_bit, state);
    if (ret < 0)
    {
        return ret;     // Uh oh.
    }

    return ATTINY861_SUCCESS;
}

ATTINY861_STATUS_CODE ATtiny861_GpioGetState(ATTINY861_PIN pin, GPIO_STATE *state)
{
    volatile uint8_t * pin_reg;
    int8_t pin_bit;

    if (state == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }

    pin_reg = ATtiny861_GpioMap_GetPinRegister(pin);
    if (pin_reg == NULL)
    {
        return ATTINY861_GPIO_INVALID;
    }

    pin_bit = ATtiny861_GpioMap_GetPinBit(pin);
    if (pin_bit < 0)
    {
        return ATTINY861_GPIO_INVALID;
    }

    *state = IS_BIT_SET(*pin_reg, pin_bit);
    return ATTINY861_SUCCESS;
}
ATTINY861_STATUS_CODE ATtiny861_GpioToggle(ATTINY861_PIN pin)
{
    volatile uint8_t * pin_reg;
    int8_t pin_bit;

    pin_reg = ATtiny861_GpioMap_GetPinRegister(pin);
    if (pin_reg == NULL)
    {
        return GPIO_INVALID;
    }
    pin_bit = ATtiny861_GpioMap_GetPinBit(pin);
    if (pin_bit < 0)
    {
        return GPIO_INVALID;
    }

    SET_BIT_INTERRUPT(*pin_reg, pin_bit);

    return ATTINY861_SUCCESS;
}
