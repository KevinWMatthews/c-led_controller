#include "Led_BlinkSixteen_Config.h"
#include "Led.h"
#include "ATtiny861_Timer0.h"
#include "ATtiny861_Interrupt.h"
#include <stddef.h>

#define NUM_LEDS    16
static Led leds[NUM_LEDS];

// This is complex behavior. We could create an LedBank object.

void timer_callback(void)
{
    size_t i;
    for (i = 0; i < NUM_LEDS; i++)
        Led_Toggle(leds[i]);
}

int set_led_params(LedParams params[])
{
    if (params == NULL)
        return -1;

    params[0].pin = ATTN861_PA0;
    params[0].initial_state = LED_OFF;
    params[0].active_state = LED_ACTIVE_HIGH;

    params[1].pin = ATTN861_PA1;
    params[1].initial_state = LED_OFF;
    params[1].active_state = LED_ACTIVE_HIGH;

    params[2].pin = ATTN861_PA2;
    params[2].initial_state = LED_OFF;
    params[2].active_state = LED_ACTIVE_HIGH;

    params[3].pin = ATTN861_PA3;
    params[3].initial_state = LED_OFF;
    params[3].active_state = LED_ACTIVE_HIGH;

    params[4].pin = ATTN861_PA4;
    params[4].initial_state = LED_OFF;
    params[4].active_state = LED_ACTIVE_HIGH;

    params[5].pin = ATTN861_PA5;
    params[5].initial_state = LED_OFF;
    params[5].active_state = LED_ACTIVE_HIGH;

    params[6].pin = ATTN861_PA6;
    params[6].initial_state = LED_OFF;
    params[6].active_state = LED_ACTIVE_HIGH;

    params[7].pin = ATTN861_PA7;
    params[7].initial_state = LED_OFF;
    params[7].active_state = LED_ACTIVE_HIGH;

    params[8].pin = ATTN861_PB0;
    params[8].initial_state = LED_OFF;
    params[8].active_state = LED_ACTIVE_HIGH;

    params[9].pin = ATTN861_PB1;
    params[9].initial_state = LED_OFF;
    params[9].active_state = LED_ACTIVE_HIGH;

    params[10].pin = ATTN861_PB2;
    params[10].initial_state = LED_OFF;
    params[10].active_state = LED_ACTIVE_HIGH;

    params[11].pin = ATTN861_PB3;
    params[11].initial_state = LED_OFF;
    params[11].active_state = LED_ACTIVE_HIGH;

    params[12].pin = ATTN861_PB4;
    params[12].initial_state = LED_OFF;
    params[12].active_state = LED_ACTIVE_HIGH;

    params[13].pin = ATTN861_PB5;
    params[13].initial_state = LED_OFF;
    params[13].active_state = LED_ACTIVE_HIGH;

    params[14].pin = ATTN861_PB6;
    params[14].initial_state = LED_OFF;
    params[14].active_state = LED_ACTIVE_HIGH;

    params[15].pin = ATTN861_PB7;
    params[15].initial_state = LED_OFF;
    params[15].active_state = LED_ACTIVE_HIGH;

    return 0;
}

int create_leds(Led leds[], LedParams params[])
{
    size_t i;
    for (i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = Led_Create(&params[i]);
        if (leds[i] == NULL)
            return -1;
    }
    return 0;
}

int main(void)
{
    ATtiny861_Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        // 1 MHz / (1024*255) = 3.83 Hz
        .match_value_A = 255
    };

    LedParams led_params[16] = {};

    ATtiny861_Timer0_Create(&timer0_params);
    ATtiny861_Timer0_RegisterCallback_MatchA(timer_callback);

    set_led_params(led_params);

    create_leds(leds, led_params);

    ATtiny861_Timer0_Start();
    ATtiny861_Interrupt_GlobalEnable();

    while (1)
    {
        ;
    }

    return 0;
}
