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
    ATtiny861_Timer0_Params params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        // 1 MHz / (1024*255) = 3.83 Hz
        .match_value_A = 255
    };

    ATtiny861_Timer0_Create(&params);
    ATtiny861_Timer0_RegisterCallback_MatchA(timer_callback);
    led = Led_Create(ATTN861_PA0);
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
