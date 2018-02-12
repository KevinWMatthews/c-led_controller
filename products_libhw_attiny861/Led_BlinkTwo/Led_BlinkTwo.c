#include "ATtiny861_Gpio.h"
#include "ATtiny861_Timer0.h"
#include <avr/interrupt.h>

static void toggle_led_state(void)
{
    ATtiny861_GpioToggle(ATTN861_PA6);
    ATtiny861_GpioToggle(ATTN861_PA7);
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

    ATtiny861_Timer0_Create(&timer0_params);
    ATtiny861_Timer0_Start();

    ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_HIGH);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    ATtiny861_Timer0_RegisterCallback_MatchA(toggle_led_state);

    // Enable interrupts
    sei();

    while (1)
        ;

    return 0;
}
