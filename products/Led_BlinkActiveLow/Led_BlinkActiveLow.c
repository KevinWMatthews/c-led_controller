#include "Led.h"



int main(void)
{
    Led led = NULL;
    LedParams led_params = {
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_LOW,
    };

    led = Led_Create(ATTN861_PA0, &led_params);

    return 0;
}
