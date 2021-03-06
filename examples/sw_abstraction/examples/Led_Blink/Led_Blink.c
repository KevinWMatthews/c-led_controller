#include "Led_Blink_Config.h"
#include "Led.h"
#include "ATtiny861_Timer0.h"
#include "ATtiny861_Interrupt.h"
#include <stddef.h>

// We are not (yet?) able to pass information to the callback,
// so the LED must be file-scope.
static Led led;

void timer_callback(void)
{
    Led_Toggle(led);
}

int main(void)
{
    ATtiny861_Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        // 1 MHz / (1024*255) = 3.83 Hz
        .match_value_A = 255
    };
    LedParams led_params = {
        .pin = ATTN861_PA0,
        .initial_state = LED_OFF,
        .active_state = LED_ACTIVE_HIGH,
    };

    ATtiny861_Timer0_Create(&timer0_params);
    ATtiny861_Timer0_RegisterCallback_MatchA(timer_callback);
    led = Led_Create(&led_params);
    if (led == NULL)
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
