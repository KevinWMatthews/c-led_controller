#include "LedHw.h"

// This file can either:
//      Set up and mock actual function calls
//      Set up 'dummy' memory registers and read and write to these.
// I think we should do the latter.

//TODO Research the hardware and verify that
//          specific initialization registers are set
//          specific status/control registers are set and read

//TODO add sanity checks on gpio - don't access off the end of the array!

static uint8_t dummy_led_registers[LEDHW_GPIO_MAX];

void LedHw_Init(LEDHW_GPIO gpio)
{
    dummy_led_registers[gpio] = LEDHW_LED_OFF;
}

uint8_t LedHw_GetState(LEDHW_GPIO gpio)
{
    return dummy_led_registers[gpio];
}

void LedHw_TurnOn(LEDHW_GPIO gpio)
{
    dummy_led_registers[gpio] = LEDHW_LED_ON;
}

void LedHw_TurnOff(LEDHW_GPIO gpio)
{
    dummy_led_registers[gpio] = LEDHW_LED_OFF;
}
