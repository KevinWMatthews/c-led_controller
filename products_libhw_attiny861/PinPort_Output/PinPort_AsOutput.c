/*
 * Investigate the difference between reading the PIN and PORT values of a GPIO.
 * The PORT register is used to configure the GPIO.
 * The PIN register is designed for reading the state of a GPIO. 
 *
 * Demonstrate what happens when you read the PORT register vs the PIN register.
 *
 * The datasheet recommends reading the PIN register.
 * This PIN register is routed through a synchronizer while the PORT register is not.
 * This guarantees an accurate read even if the physical pin changes state
 * close to a clock cycle.
 */
#include "ATtiny861_Gpio.h"
#include "ATtiny861_Timer0.h"
#include <avr/interrupt.h>
#include <avr/io.h>

static void toggle_led_state(void)
{
    ATtiny861_GpioToggle(ATTN861_PA0);

    if ( bit_is_set(PINA, PINA0) )
    {
        ATtiny861_GpioSetState(ATTN861_PA6, GPIO_HIGH);
    }
    else
    {
        ATtiny861_GpioSetState(ATTN861_PA6, GPIO_LOW);
    }

    if ( bit_is_set(PORTA, PORTA0) )
    {
        ATtiny861_GpioSetState(ATTN861_PA7, GPIO_HIGH);
    }
    else
    {
        ATtiny861_GpioSetState(ATTN861_PA7, GPIO_LOW);
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

    ATtiny861_Timer0_Create(&timer0_params);
    ATtiny861_Timer0_Start();

    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    ATtiny861_Timer0_RegisterCallback_MatchA(toggle_led_state);

    // Enable interrupts
    sei();

    while (1)
        ;

    return 0;
}
