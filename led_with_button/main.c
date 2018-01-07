#include "LedControllerConfig.h"
#include "Led.h"
#include <stddef.h>

int main(void)
{
    Led led = NULL;
    Led_Create(LEDHW_LED_1);
    // Led_TurnOn(led);
    return 0;
}
