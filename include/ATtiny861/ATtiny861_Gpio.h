#ifndef ATTINY861_GPIO_INCLUDED
#define ATTINY861_GPIO_INCLUDED

#include "ATtiny861_Pins.h"
#include "ATtiny861_ReturnCodes.h"

typedef enum
{
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
void ATtiny861_Gpio_Init(void);

/*
 * Set the given gpio as an output and set its initial state.
 * If an invalid pin or state is passed, does nothing.
 */
ATTINY861_RETURN_CODE ATtiny861_Gpio_SetAsOutput(ATTINY861_PIN pin, GPIO_STATE initial_state);

/*
 * Set the given pin to a new state.
 * If an invalid pin or state is passed, does nothing.
 */
//TODO what does this do if the gpio is an input? Enable the internal pull-up?
ATTINY861_RETURN_CODE ATtiny861_Gpio_SetState(ATTINY861_PIN pin, GPIO_STATE state);

/*
 * Get the state of the given pin and place it in state.
 * Valid for inputs and outputs.
 * If pin or state pointer are invalid, does nothing.
 */
ATTINY861_RETURN_CODE ATtiny861_Gpio_GetState(ATTINY861_PIN pin, GPIO_STATE *state);

/*
 * Toggle the state of the given pin.
 * Operates on both inputs and outputs.
 *
 * For outputs, this changes the pin state.
 * For inputs, this enables or disables the internal pull-up.
 */
ATTINY861_RETURN_CODE ATtiny861_Gpio_Toggle(ATTINY861_PIN pin);

#endif
