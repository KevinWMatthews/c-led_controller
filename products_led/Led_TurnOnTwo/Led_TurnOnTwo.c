#include "Led_TurnOnTwo_Config.h"
#include "Led.h"

int main(void)
{
    LedParams led_params1 = {
        .pin = ATTN861_PA1,
        .initial_state = LED_ON,
        .active_state = LED_ACTIVE_LOW,
    };
    LedParams led_params2 = {
        .pin = ATTN861_PA7,
        .initial_state = LED_ON,
        .active_state = LED_ACTIVE_HIGH,
    };

    Led led1 = Led_Create(&led_params1);
    Led led2 = Led_Create(&led_params2);

    while (1)
        ;

    Led_Destroy(&led1);
    Led_Destroy(&led2);

	return 0;
}
