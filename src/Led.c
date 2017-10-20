#include "Led.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LedStruct
{
    LEDHW_GPIO gpio;
} LedStruct;

Led Led_Create(LEDHW_GPIO gpio)
{
    Led self = calloc( 1, sizeof(*self) );
    LedHw_Init(gpio);
    return self;
}

void Led_Destroy(Led self)
{
    free(self);
    return;
}

LEDHW_STATE Led_GetState(Led self)
{
    return LEDHW_LED_OFF;//LedHw_GetState(/*gpio*/);
}
