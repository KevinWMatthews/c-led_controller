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
    ATTINY861_STATUS_CODE ret;
    Led self = NULL;

    ret = ATtiny861_GpioSetAsOutput(pin, GPIO_LOW);
    if (ret < 0)
    {
        return NULL;
    }

    self = calloc( 1, sizeof(*self) );
    self->pin = pin;

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
    ATTINY861_STATUS_CODE ret;
    GPIO_STATE gpio_state;

    if (state == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_GpioGetState(self->pin, &gpio_state);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    // GPIO state is mapped directly to LED state, for now.
    *state = gpio_state;
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    ATTINY861_STATUS_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_GpioSetState(self->pin, GPIO_HIGH);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    ATTINY861_STATUS_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_GpioSetState(self->pin, GPIO_LOW);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}

LED_RETURN_CODE Led_Toggle(Led self)
{
    ATTINY861_STATUS_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_GpioToggle(self->pin);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}
