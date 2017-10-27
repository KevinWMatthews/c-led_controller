#ifndef ATTINY861_H_INCLUDED
#define ATTINY861_H_INCLUDED

#include <stdint.h>
#include <avr/io.h>

typedef enum
{
    GPIO_LOW    = 0,
    GPIO_HIGH   = 1
} GPIO_STATE;

// Initialize all GPIO on the ATtiny861.
// Pins default to floating inputs.
// This function leaves all pins as inputs but enables their internal pull-up resistors.
void ATtiny861_GpioInit(void);

typedef enum
{
    ATTN861_PA0 = 0,
    ATTN861_PA1 = 1,
    ATTN861_PA2 = 2,
    ATTN861_PB0 = 8
} ATTN861_GPIO;
void ATtiny861_GpioSetAsOutput(ATTN861_GPIO, GPIO_STATE);

#endif
