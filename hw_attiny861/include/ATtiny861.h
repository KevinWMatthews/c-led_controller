#ifndef ATTINY861_H_INCLUDED
#define ATTINY861_H_INCLUDED

#include <stdint.h>

typedef enum
{
    GPIO_INVALID    = -1,
    GPIO_LOW        = 0,
    GPIO_HIGH       = 1
} GPIO_STATE;

// Initialize all GPIO on the ATtiny861.
// Pins default to floating inputs.
// This function leaves all pins as inputs but enables their internal pull-up resistors.
void ATtiny861_GpioInit(void);

typedef enum
{
    ATTN861_PA0         = 0,
    ATTN861_PA1         = 1,
    ATTN861_PA2         = 2,
    ATTN861_PA3         = 3,
    ATTN861_PA4         = 4,
    ATTN861_PA5         = 5,
    ATTN861_PA6         = 6,
    ATTN861_PA7         = 7,
    ATTN861_PB0         = 8,
    ATTN861_PB1         = 9,
    ATTN861_PB2         = 10,
    ATTN861_PB3         = 11,
    ATTN861_PB4         = 12,
    ATTN861_PB5         = 13,
    ATTN861_PB6         = 14,
    ATTN861_PB7         = 15,
    ATTN861_GPIO_MAX    = 16
} ATTN861_GPIO;

typedef enum
{
    ATTINY861_GPIO_INVALID  = -1,
    ATTINY861_SUCCESS       = 0
} ATTINY861_STATUS_CODE;

// Set the given gpio as an output.
// Specify if gpio should be driven high or low after initialization.
// If an invalid pin or state is passed, does nothing.
ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state);

// Set the given pin to a new state.
// If an invalid pin or state is passed, does nothing.
//TODO what does this do if the gpio is an input? Re-read the manual....
ATTINY861_STATUS_CODE ATtiny861_GpioSetState(ATTN861_GPIO gpio, GPIO_STATE state);

// Get the state of the given pin.
//TODO does it matter if the pin is an input or an output? Re-read the manual.
GPIO_STATE ATtiny861_GpioGetState(ATTN861_GPIO gpio);

#endif
