#include "ATtiny861_Gpio.h"
#include "ATtiny861_Timer0.h"
#include <avr/interrupt.h>

static void toggle_led_state(void)
{
    ATTINY861_STATUS_CODE ret;

    ret = ATtiny861_GpioToggle(ATTN861_PA6);
    if (ret != ATTINY861_SUCCESS)
    {
        return;
    }

    ret = ATtiny861_GpioToggle(ATTN861_PA7);
    if (ret != ATTINY861_SUCCESS)
    {
        return;
    }
}

int main(void)
{
    /*
     * 8 MHz / (1024*255) = 30.6 Hz  => Roughly twice a second.
     */
    ATtiny861_Timer0_Params timer0_params = {
        .clock_source = ATTN861_TIMER0_INTERNAL_CLOCK_PRESCALER_1024,
        .match_value_A = 255
    };
    ATTN861_TIMER0_RETURN_CODE timer_ret;
    ATTINY861_STATUS_CODE ret;

    timer_ret = ATtiny861_Timer0_Create(&timer0_params);
    if (timer_ret != ATTN861_TIMER0_SUCCESS)
    {
        return -1;
    }
    timer_ret = ATtiny861_Timer0_Start();
    if (timer_ret != ATTN861_TIMER0_SUCCESS)
    {
        return -1;
    }

    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_HIGH);
    if (ret != ATTINY861_SUCCESS)
    {
        return -1;
    }

    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);
    if (ret != ATTINY861_SUCCESS)
    {
        return -1;
    }

    timer_ret = ATtiny861_Timer0_RegisterCallback_MatchA(toggle_led_state);
    if (timer_ret != ATTN861_TIMER0_SUCCESS)
    {
        return -1;
    }

    // Enable interrupts
    sei();

    while (1)
        ;

    return 0;
}
