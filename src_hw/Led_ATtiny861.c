#include "Led2.h"
#include "ATtiny861Gpio.h"

Led Led_Create(LED_NUMBER led_num)
{
    //TODO map Led number to gpio number
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);
    return NULL;
}

void Led_Destroy(Led * self)
{
}

LED_STATE Led_GetState(Led self)
{
    // GPIO_STATE is mapped directly to LED_STATE at the moment.
    return ATtiny861_GpioGetState(ATTN861_PB0);
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    ATtiny861_GpioSetState(ATTN861_PB0, GPIO_HIGH);
    return LED_SUCCESS;
}
