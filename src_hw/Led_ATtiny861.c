#include "Led2.h"

Led Led_Create(LED_NUMBER led_num)
{
    return NULL;
}

void Led_Destroy(Led * self)
{
}

LED_STATE Led_GetState(Led self)
{
    return LED_OFF;
}

LED_RETURN_CODE Led_TurnOn(Led self)
{
    return LED_SUCCESS;
}
