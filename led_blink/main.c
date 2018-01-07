#include "LedControllerConfig.h"
#include "Led2.h"
#include <stddef.h>

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <util/delay.h>

int main(void)
{
    Led led = NULL;
    led = Led_Create(LED_1);
    while (1)
    {
        Led_TurnOn(led);
        _delay_ms(500);
        Led_TurnOff(led);
        _delay_ms(500);
    }

    return 0;
}
