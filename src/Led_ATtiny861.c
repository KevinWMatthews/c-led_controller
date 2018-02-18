#include "Led.h"
#include "ATtiny861_Gpio.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    ATTINY861_PIN pin;
} LedStruct;

Led Led_Create(ATTINY861_PIN pin, LedParams *params)
{
    ATTINY861_RETURN_CODE ret;
    Led self = NULL;

    ret = ATtiny861_Gpio_SetAsOutput(pin, GPIO_LOW);
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
    ATTINY861_RETURN_CODE ret;
    GPIO_STATE gpio_state;

    if (state == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_Gpio_GetState(self->pin, &gpio_state);
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
    ATTINY861_RETURN_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_Gpio_SetState(self->pin, GPIO_HIGH);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    ATTINY861_RETURN_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_Gpio_SetState(self->pin, GPIO_LOW);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}

LED_RETURN_CODE Led_Toggle(Led self)
{
    ATTINY861_RETURN_CODE ret;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    ret = ATtiny861_Gpio_Toggle(self->pin);
    if (ret < 0)
    {
        //TODO untested. Don't know how.
        return LED_ERROR;
    }

    return LED_SUCCESS;
}
