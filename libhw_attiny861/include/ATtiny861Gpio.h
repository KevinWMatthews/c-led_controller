#ifndef ATTINY861GPIO_H_INCLUDED
#define ATTINY861GPIO_H_INCLUDED

#include "ATtiny861_Pins.h"

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
    ATTINY861_GPIO_INVALID  = -2,
    ATTINY861_NULL_POINTER  = -1,
    ATTINY861_SUCCESS       = 0
} ATTINY861_STATUS_CODE;

// Set the given gpio as an output.
// Specify if gpio should be driven high or low after initialization.
// If an invalid pin or state is passed, does nothing.
ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state);

// Set the given pin to a new state.
// If an invalid pin or state is passed, does nothing.
//TODO what does this do if the gpio is an input? Re-read the manual....
ATTINY861_STATUS_CODE ATtiny861_GpioSetState(ATTINY861_PIN pin, GPIO_STATE state);

// Get the state of the given pin.
//TODO does it matter if the pin is an input or an output? Re-read the manual.
GPIO_STATE ATtiny861_GpioGetState(ATTINY861_PIN pin);

#endif
