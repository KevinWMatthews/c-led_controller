#include "LedHw.h"
#include "ATtiny861.h"

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

void LedHw_Init(LEDHW_LED_NUMBER led_number)
{
    if (led_number >= LEDHW_LED_MAX)
        return;
    ATTN861_GPIO gpio = convert_gpio(led_number);
    ATtiny861_GpioSetAsOutput(gpio, GPIO_LOW);
}

void LedHw_TurnOn(LEDHW_LED_NUMBER led_number)
{
    // ATtiny861_GpioSetState(gpio, GPIO_HIGH);
}
