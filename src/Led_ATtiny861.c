#include "Led.h"
#include "ATtiny861_Gpio.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    ATTINY861_PIN pin;
} LedStruct;

Led Led_Create(ATTINY861_PIN pin)
{
    Led self = NULL;
    self = calloc( 1, sizeof(*self) );
    self->pin = pin;
    ATtiny861_GpioSetAsOutput(self->pin, GPIO_LOW);
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
    //TODO need to have gpio state consistent across modules.
    //Status codes, too.
    ATTINY861_STATUS_CODE ret;
    GPIO_STATE gpio_state;

    if (state == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_GpioGetState(self->pin, &gpio_state);
    //TODO what if this fails?

    *state = gpio_state;    //TODO Nice typecast.
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

LED_RETURN_CODE Led_Toggle(Led self)
{
    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }
    ATtiny861_GpioToggle(self->pin);
    return LED_SUCCESS;
}
