#include "LedControllerConfig.h"
#include "Led.h"
#include "ATtiny861Timer0.h"
#include <stddef.h>
#include <avr/interrupt.h>     // For global interrupts.

// We are not (yet?) able to pass information to the callback,
// so the LED must be file-scope.
static Led led1;
static Led led2;

static void toggle_led(Led led)
{
    LED_STATE led_state;
    LED_RETURN_CODE ret;

    ret = Led_GetState(led, &led_state);
    if (ret != LED_SUCCESS)
    {
        return;
    }

    if (led_state == LED_OFF)
    {
        Led_TurnOn(led);
    }
    else
    {
        Led_TurnOff(led);
    }
}

void timer_callback(void)
{
    static uint8_t count;

    if (count < 10)
    {
        ++count;
        return;
    }
    count = 0;
    toggle_led(led1);
    toggle_led(led2);
}

int main(void)
{
    ATtiny861Timer0_Params params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        // Set timer to 10 Hz:
        //  match_value = 1MHZ / (1024*10Hz)
        .match_value_A = 97
    };

    ATtiny861Timer0_Create(&params);
    ATtiny861Timer0_RegisterCallback_MatchA(timer_callback);
    led1 = Led_Create(LED_1);
    led2 = Led_Create(LED_2);

    Led_TurnOn(LED_1);      // check return value?
    ATtiny861Timer0_Start();
    sei();      // Enable global interrupts

    while (1)
    {
        ;
    }

    return 0;
}