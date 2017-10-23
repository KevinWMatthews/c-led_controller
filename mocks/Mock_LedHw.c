#include "LedHw.h"

// This file can either:
//      Set up and mock actual function calls
//      Set up 'dummy' memory registers and read and write to these.
// I think we should do the latter.

//TODO Research the hardware and verify that
//          specific initialization registers are set
//          specific status/control registers are set and read

static uint8_t dummy_led_register;

void LedHw_Init(LEDHW_GPIO gpio)
{
    dummy_led_register = LEDHW_LED_OFF;
}

uint8_t LedHw_GetState(LEDHW_GPIO gpio)
{
    return dummy_led_register;
}

void LedHw_TurnOn(LEDHW_GPIO gpio)
{
    dummy_led_register = LEDHW_LED_ON;
}
