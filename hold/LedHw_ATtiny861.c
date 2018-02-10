#include "LedHw.h"
#include "ATtiny861Gpio.h"

// This function maps schematic LED labels (LEDHW) to pins on the specific chip.
static ATTN861_GPIO convert_gpio(LEDHW_LED_NUMBER led_number)
{
    switch (led_number)
    {
    case LEDHW_LED_1:
        return ATTN861_PA7;
    case LEDHW_LED_2:
        return ATTN861_PA6;
    }
    return ATTN861_GPIO_MAX;    // Error!
}

LEDHW_STATUS_CODE LedHw_Init(LEDHW_LED_NUMBER led_number)
{
    ATTN861_GPIO gpio;

    if (led_number >= LEDHW_LED_MAX)
    {
        return LEDHW_INVALID_LED;
    }
    gpio = convert_gpio(led_number);
    ATtiny861_GpioSetAsOutput(gpio, GPIO_LOW);
    return LEDHW_SUCCESS;
}

LEDHW_STATUS_CODE LedHw_TurnOn(LEDHW_LED_NUMBER led_number)
{
    ATTN861_GPIO gpio;

    if (led_number >= LEDHW_LED_MAX)
    {
        return LEDHW_INVALID_LED;
    }
    gpio = convert_gpio(led_number);
    ATtiny861_GpioSetState(gpio, GPIO_HIGH);
    return LEDHW_SUCCESS;
}

LEDHW_STATUS_CODE LedHw_TurnOff(LEDHW_LED_NUMBER led_number)
{
    ATTN861_GPIO gpio;

    if (led_number >= LEDHW_LED_MAX)
    {
        return LEDHW_INVALID_LED;
    }
    gpio = convert_gpio(led_number);
    ATtiny861_GpioSetState(gpio, GPIO_LOW);
    return LEDHW_SUCCESS;
}
