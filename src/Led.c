#include "Led.h"
#include <stddef.h>

Led Led_Create(LEDHW_GPIO gpio)
{
    return NULL;
}

void Led_Destroy(Led self)
{
    return;
}

LEDHW_STATE Led_GetState(Led self)
{
    return LEDHW_LED_OFF;//LedHw_GetState(/*gpio*/);
}
