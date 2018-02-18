#include "ATtiny861_Gpio.h"
#include "ATtiny861_GpioMap.h"
#include "BitManip.h"
#include <stddef.h>
#include <stdbool.h>

bool is_valid_state(GPIO_STATE state)
{
    if (state == GPIO_LOW)
    {
        return true;
    }
    else if (state == GPIO_HIGH)
    {
        return true;
    }
    return false;
}

//TODO add a direction parameter
static ATTINY861_RETURN_CODE set_gpio_direction(volatile uint8_t * ddr, uint8_t bit)
{
    if (ddr == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }

    SET_BIT(*ddr, bit);

    return ATTINY861_SUCCESS;
}

static ATTINY861_RETURN_CODE set_gpio_state(volatile uint8_t * port, uint8_t bit, GPIO_STATE state)
{
    if (port == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }

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

ATTINY861_RETURN_CODE ATtiny861_Gpio_SetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state)
{
    volatile uint8_t *ddr, *port;
    uint8_t ddr_bit, port_bit;
    ATTINY861_RETURN_CODE ret;
    ATTINY861_RETURN_CODE gpiomap_ret;

    if ( !is_valid_state(initial_state) )
    {
        return ATTINY861_INVALID_STATE;
    }

    ddr = ATtiny861_GpioMap_GetDdrRegister(pin);
    if (ddr == NULL)
    {
        return ATTINY861_INVALID_PIN;
    }

    gpiomap_ret = ATtiny861_GpioMap_GetDdrBit(pin, &ddr_bit);
    if (gpiomap_ret < 0)
    {
        return gpiomap_ret;
    }

    port = ATtiny861_GpioMap_GetPortRegister(pin);
    if (port == NULL)
    {
        return ATTINY861_INVALID_PIN;
    }

    gpiomap_ret = ATtiny861_GpioMap_GetPortBit(pin, &port_bit);
    if (gpiomap_ret < 0)
    {
        return gpiomap_ret;
    }

    ret = set_gpio_direction(ddr, ddr_bit);
    if (ret < 0)
    {
        return ret;
    }

    ret = set_gpio_state(port, port_bit, initial_state);
    if (ret < 0)
    {
        return ret;
    }

    return ATTINY861_SUCCESS;
}

void ATtiny861_Gpio_Init(void)
{
    volatile uint8_t * port_register;

    // Pins should default to inputs on power-up.

    // The ATtiny861 datasheet, section 10.1.6 states that all unconnected pins
    // should be left as inputs and have their internal pull-up resistor driven high.

    // Use any pin to get a pointer to the entire register.
    port_register = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA0);
    if (port_register)
    {
        *port_register = 0xff;
    }

    port_register = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB0);
    if (port_register)
    {
        *port_register = 0xff;
    }
}

ATTINY861_RETURN_CODE ATtiny861_Gpio_SetState(ATTINY861_PIN pin, GPIO_STATE state)
{
    volatile uint8_t *port;
    uint8_t port_bit;
    ATTINY861_RETURN_CODE ret;
    ATTINY861_RETURN_CODE gpiomap_ret;

    if ( !is_valid_state(state) )
    {
        return ATTINY861_INVALID_STATE;
    }

    port = ATtiny861_GpioMap_GetPortRegister(pin);
    if (port == NULL)
    {
        return ATTINY861_INVALID_PIN;
    }

    gpiomap_ret = ATtiny861_GpioMap_GetPortBit(pin, &port_bit);
    if (gpiomap_ret < 0)
    {
        return gpiomap_ret;
    }

    ret = set_gpio_state(port, port_bit, state);
    if (ret < 0)
    {
        return ret;
    }

    return ATTINY861_SUCCESS;
}

ATTINY861_RETURN_CODE ATtiny861_Gpio_GetState(ATTINY861_PIN pin, GPIO_STATE *state)
{
    volatile uint8_t * pin_reg;
    uint8_t pin_bit;
    ATTINY861_RETURN_CODE gpiomap_ret;

    if (state == NULL)
    {
        return ATTINY861_NULL_POINTER;
    }

    pin_reg = ATtiny861_GpioMap_GetPinRegister(pin);
    if (pin_reg == NULL)
    {
        return ATTINY861_INVALID_PIN;
    }

    gpiomap_ret = ATtiny861_GpioMap_GetPinBit(pin, &pin_bit);
    if (gpiomap_ret < 0)
    {
        return ATTINY861_INVALID_PIN;
    }

    *state = IS_BIT_SET(*pin_reg, pin_bit);
    return ATTINY861_SUCCESS;
}

ATTINY861_RETURN_CODE ATtiny861_Gpio_Toggle(ATTINY861_PIN pin)
{
    volatile uint8_t * pin_reg;
    uint8_t pin_bit;
    ATTINY861_RETURN_CODE gpiomap_ret;

    pin_reg = ATtiny861_GpioMap_GetPinRegister(pin);
    if (pin_reg == NULL)
    {
        return ATTINY861_INVALID_PIN;
    }

    gpiomap_ret = ATtiny861_GpioMap_GetPinBit(pin, &pin_bit);
    if (gpiomap_ret < 0)
    {
        return ATTINY861_INVALID_PIN;
    }

    SET_BIT_INTERRUPT(*pin_reg, pin_bit);

    return ATTINY861_SUCCESS;
}
