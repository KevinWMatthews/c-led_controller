#include "Led.h"
#include <stddef.h>

Led Led_Create(void)
{
    return NULL;
}

void Led_Destroy(Led self)
{
    return;
}

LED_STATE Led_GetState(Led self)
{
    return 42;  //TODO this should point to LedHw
}
