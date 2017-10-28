#include "LedHw.h"
#include "ATtiny861.h"

void LedHw_Init(LEDHW_GPIO gpio)
{
    ATtiny861_GpioSetAsOutput(gpio, GPIO_LOW);
}

void LedHw_TurnOn(LEDHW_GPIO gpio)
{
    // ATtiny861_GpioSetState(gpio, GPIO_HIGH);
}
