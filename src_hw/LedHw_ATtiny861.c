#include "LedHw.h"
#include "ATtiny861.h"

void LedHw_Init(LEDHW_LED_NUMBER led_number)
{
    ATtiny861_GpioSetAsOutput(led_number, GPIO_LOW);
}

void LedHw_TurnOn(LEDHW_LED_NUMBER led_number)
{
    // ATtiny861_GpioSetState(gpio, GPIO_HIGH);
}
