#include "Led.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    LEDHW_LED_NUMBER gpio;
} LedStruct;

Led Led_Create(LEDHW_LED_NUMBER gpio)
{
    Led self = calloc( 1, sizeof(*self) );
    self->gpio = gpio;

    LedHw_Init(self->gpio);

    return self;
}

void Led_Destroy(Led *self)
{
    if (self)
    {
        free(*self);
        *self = 0;      // Trying to avoid a double-free
    }
    return;
}

LEDHW_STATE Led_GetState(Led self)
{
    return LedHw_GetState(self->gpio);
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    if (!self)
        return LED_NULL_POINTER;

    LedHw_TurnOn(self->gpio);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    if (!self)
        return LED_NULL_POINTER;

    LedHw_TurnOff(self->gpio);
    return LED_SUCCESS;
}
