#include "Led_BlinkTwoActiveLow_Config.h"
#include "Led.h"
#include "ATtiny861_Timer0.h"
#include "ATtiny861_Interrupt.h"
#include <stddef.h>

static Led led1;
static Led led2;

void toggle_led(void)
{
    Led_Toggle(led1);
    Led_Toggle(led2);
    // No way to signal error at the moment.
}

int main(void)
{
    ATtiny861_Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        .match_value_A = 255,
    };
    LedParams led_params1 = {
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_LOW,
    };
    LedParams led_params2 = {
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_HIGH,
    };
    ATTINY861_PIN pin1 = ATTN861_PA1;
    ATTINY861_PIN pin2 = ATTN861_PA6;

    ATTINY861_RETURN_CODE ret;

    ret = ATtiny861_Timer0_Create(&timer0_params);
    if (ret < 0)
    {
        return -1;
    }

    ret = ATtiny861_Timer0_RegisterCallback_MatchA(toggle_led);
    if (ret < 0)
    {
        return -1;
    }

    led1 = Led_Create(pin1, &led_params1);
    if (led1 == NULL)
    {
        return -1;
    }

    led2 = Led_Create(pin2, &led_params2);
    if (led2 == NULL)
    {
        return -1;
    }

    ATtiny861_Timer0_Start();

    ATtiny861_Interrupt_GlobalEnable();

    while (1)
    {
        ;
    }

    Led_Destroy(&led1);
    Led_Destroy(&led2);
    return 0;
}
