#include "Led_BlinkTwo_Config.h"
#include "Led.h"
#include "ATtiny861_Timer0.h"
#include "ATtiny861_Interrupt.h"
#include <stddef.h>

// We are not (yet?) able to pass information to the callback,
// so the LED must be file-scope.
static Led led1;
static Led led2;

void timer_callback(void)
{
    Led_Toggle(led1);
    Led_Toggle(led2);
}

int main(void)
{
    ATtiny861_Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        // 1 MHz / (1024*255) = 3.83 Hz
        .match_value_A = 255
    };
    LedParams led1_params = {
        .pin = ATTN861_PA6,
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_HIGH,
    };
    LedParams led2_params = {
        .pin = ATTN861_PA7,
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_HIGH,
    };
    LED_RETURN_CODE ret;

    ATtiny861_Timer0_Create(&timer0_params);
    ATtiny861_Timer0_RegisterCallback_MatchA(timer_callback);

    led1 = Led_Create(&led1_params);
    if (led1 == NULL)
    {
        return -1;
    }
    led2 = Led_Create(&led2_params);
    if (led2 == NULL)
    {
        return -1;
    }

    ret = Led_TurnOn(led1);
    if (ret != LED_SUCCESS)
    {
        return -1;
    }

    ATtiny861_Timer0_Start();
    ATtiny861_Interrupt_GlobalEnable();

    while (1)
    {
        ;
    }

    return 0;
}
