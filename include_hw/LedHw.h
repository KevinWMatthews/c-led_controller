#ifndef LED_HW_INCLUDED
#define LED_HW_INCLUDED

#include <stdint.h>

// This enum specifies LED numbers according to the end-user's perspective.
// This should match the schematic labels.
typedef enum
{
    LEDHW_LED_1     = 0,
    LEDHW_LED_2     = 1,
    LEDHW_LED_MAX   = 2
} LEDHW_LED_NUMBER;

typedef enum
{
    LEDHW_LED_OFF = 0,
    LEDHW_LED_ON  = 1
} LEDHW_STATE;

typedef enum
{
    LEDHW_INVALID_LED   = -1,
    LEDHW_SUCCESS       = 0
} LEDHW_STATUS_CODE;

// Initialize the physical hardware so it can control an LED.
// Verify that the LED is off.
LEDHW_STATUS_CODE LedHw_Init(LEDHW_LED_NUMBER led_number);

uint8_t LedHw_GetState(LEDHW_LED_NUMBER led_number);

// Turn an LED on.
LEDHW_STATUS_CODE LedHw_TurnOn(LEDHW_LED_NUMBER led_number);

// Turn an LED on.
LEDHW_STATUS_CODE LedHw_TurnOff(LEDHW_LED_NUMBER led_number);

#endif
