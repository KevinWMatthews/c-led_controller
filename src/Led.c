#include "Led.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    LEDHW_LED_NUMBER hw_led;
} LedStruct;

Led Led_Create(LEDHW_LED_NUMBER hw_led)
{
    Led self = calloc( 1, sizeof(*self) );
    self->hw_led = hw_led;

    LedHw_Init(self->hw_led);

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
    return LedHw_GetState(self->hw_led);
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    if (!self)
        return LED_NULL_POINTER;

    LedHw_TurnOn(self->hw_led);
    return LED_SUCCESS;
}

LED_RETURN_CODE Led_TurnOff(Led self)
{
    if (!self)
        return LED_NULL_POINTER;

    LedHw_TurnOff(self->hw_led);
    return LED_SUCCESS;
}
