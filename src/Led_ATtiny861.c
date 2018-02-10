#include "Led.h"
#include "ATtiny861Gpio.h"
#include "Pinmap_ATtiny861.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    ATTINY861_PIN pin;
} LedStruct;

Led Led_Create(LED_NUMBER led_num)
{
    Led self = NULL;
    ATTINY861_PIN pin;

    switch (led_num)
    {
        case LED_1:
            pin = PINMAP_LED_1;
            break;
        case LED_2:
            pin = PINMAP_LED_2;
            break;
        default:
            return NULL;
    }

    self = calloc( 1, sizeof(*self) );
    self->pin = pin;
    ATtiny861_GpioSetAsOutput(pin, GPIO_LOW);
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

    *state = ATtiny861_GpioGetState(self->pin);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ATtiny861_GpioSetState(self->pin, GPIO_HIGH);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ATtiny861_GpioSetState(self->pin, GPIO_LOW);
    return LED_SUCCESS;
}
