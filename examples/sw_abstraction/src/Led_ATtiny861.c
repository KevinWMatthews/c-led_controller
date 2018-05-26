#include "Led.h"
#include "ATtiny861_Gpio.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    ATTINY861_PIN pin;
    LED_ACTIVE_STATE active_state;
} LedStruct;

static LED_STATE convert_gpio_state_to_gpio_state(LED_ACTIVE_STATE active_state, GPIO_STATE gpio_state)
{
    if (active_state == LED_ACTIVE_LOW)
    {
        // This will fail if we change the GPIO_STATE and LED_STATE macros.
        return !gpio_state;
    }
    return gpio_state;
}

static GPIO_STATE convert_led_state_to_gpio_state(LED_ACTIVE_STATE active_state, LED_STATE led_state)
{
    if (active_state == LED_ACTIVE_LOW)
    {
        // This will fail if we change the GPIO_STATE and LED_STATE macros.
        return !led_state;
    }
    return led_state;
}

Led Led_Create(LedParams *params)
{
    ATTINY861_RETURN_CODE ret;
    Led self = NULL;
    GPIO_STATE gpio_state;

    if (params == NULL)
    {
        return NULL;
    }

    gpio_state = convert_led_state_to_gpio_state(params->active_state, params->initial_state);
    ret = ATtiny861_Gpio_SetAsOutput(params->pin, gpio_state);
    if (ret < 0)
    {
        return NULL;
    }

    self = calloc( 1, sizeof(*self) );
    self->pin = params->pin;
    self->active_state = params->active_state;

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

    *state = convert_gpio_state_to_gpio_state(self->active_state, gpio_state);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    ATTINY861_RETURN_CODE ret;
    GPIO_STATE gpio_state;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    gpio_state = convert_led_state_to_gpio_state(self->active_state, LED_ON);
    ret = ATtiny861_Gpio_SetState(self->pin, gpio_state);
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
    GPIO_STATE gpio_state;

    if (self == NULL)
    {
        return LED_NULL_POINTER;
    }

    gpio_state = convert_led_state_to_gpio_state(self->active_state, LED_OFF);
    ret = ATtiny861_Gpio_SetState(self->pin, gpio_state);
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
