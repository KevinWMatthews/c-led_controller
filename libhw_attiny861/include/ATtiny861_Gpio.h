#ifndef ATTINY861_GPIO_H_INCLUDED
#define ATTINY861_GPIO_H_INCLUDED

#include "ATtiny861_Pins.h"

typedef enum
{
    GPIO_INVALID    = -1,
    GPIO_LOW        = 0,
    GPIO_HIGH       = 1
} GPIO_STATE;

/*
 * Initialize all GPIO on the ATtiny861.
 *
 * By default, pins are floating inputs.
 * This function leaves all pins as inputs but prevents them from floating by
 * enableing their internal pull-up resistors, as specified in the ATtiny861
 * datasheet, section 10.1.6.
 */
void ATtiny861_GpioInit(void);

typedef enum
{
    ATTINY861_GPIO_INVALID  = -2,
    ATTINY861_NULL_POINTER  = -1,
    ATTINY861_SUCCESS       = 0
} ATTINY861_STATUS_CODE;

/*
 * Set the given gpio as an output and set its initial state.
 * If an invalid pin or state is passed, does nothing.
 */
ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state);

/*
 * Set the given pin to a new state.
 * If an invalid pin or state is passed, does nothing.
 */
//TODO what does this do if the gpio is an input? Enable the internal pull-up?
ATTINY861_STATUS_CODE ATtiny861_GpioSetState(ATTINY861_PIN pin, GPIO_STATE state);

/*
 * Get the state of the given pin.
 *
 * Valid for inputs and outputs.
 */
GPIO_STATE ATtiny861_GpioGetState(ATTINY861_PIN pin);

/*
 * Toggle the state of the given pin.
 * Operates on both inputs and outputs.
 *
 * For outputs, this changes the pin state.
 * For inputs, this enables or disables the internal pull-up.
 */
ATTINY861_STATUS_CODE ATtiny861_GpioToggle(ATTINY861_PIN pin);

#endif
