#include "LedControllerConfig.h"
#include "Led2.h"
#include <stddef.h>

int main(void)
{
    Led led = NULL;
    led = Led_Create(LED_1);
    Led_TurnOn(led);
    return 0;
}
