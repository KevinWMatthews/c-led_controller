#include "Led.h"
#include "ATtiny861Gpio.h"
#include "Pinmap_ATtiny861.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    ATTN861_GPIO gpio;
} LedStruct;

Led Led_Create(LED_NUMBER led_num)
{
    Led self = calloc( 1, sizeof(*self) );

    switch (led_num)
    {
        case LED_1:
            self->gpio = PINMAP_LED_1;
            break;
        case LED_2:
            self->gpio = PINMAP_LED_2;
            break;
        //TODO default...
    }
    ATtiny861_GpioSetAsOutput(self->gpio, GPIO_LOW);
    return self;
}

void Led_Destroy(Led * self)
{
    if (self == NULL)
    {
        return;
    }
    free(*self);
    *self = NULL;
}

LED_RETURN_CODE Led_GetState(Led self, LED_STATE *state)
{
    if (state == NULL)
    {
        return LED_NULL_POINTER;
    }

    *state = ATtiny861_GpioGetState(self->gpio);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    ATtiny861_GpioSetState(self->gpio, GPIO_HIGH);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    ATtiny861_GpioSetState(self->gpio, GPIO_LOW);
    return LED_SUCCESS;
}
