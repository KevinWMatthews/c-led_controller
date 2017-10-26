#ifndef ATTINY861_H_INCLUDED
#define ATTINY861_H_INCLUDED

// Initialize all GPIO on the ATtiny861.
// Pins default to floating inputs.
// This function leaves all pins as inputs but enables their internal pull-up resistors.
void ATtiny861_GpioInit(void);

#endif
