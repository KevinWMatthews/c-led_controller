#ifndef ATTINY861_GPIOMAP_INCLUDED
#define ATTINY861_GPIOMAP_INCLUDED

#include "ATtiny861_Pins.h"

/*
 * Configuring and using GPIO requires knowledge of three registers:
 *  DDRxn:      Data Direction Register, byte x, bit n
 *  PORTxn:     Data Register, byte x, bit n
 *  PINxn:      Port Input Pin Address, byte x, bit n
 *
 * This module provides functions to easily access these values.
 */

typedef enum
{
    ATTINY861_GPIOMAP_SUCCESS       = 0,
    ATTINY861_GPIOMAP_NULL_POINTER  = -1,
    ATTINY861_GPIOMAP_INVALID_PIN   = -2,
} ATTINY861_GPIOMAP_STATUS_CODE;

/*
 * Get a pointer to the Data Direction Register for the given pin.
 *
 * Returns NULL on failure.
 */
volatile uint8_t * ATtiny861_GpioMap_GetDdrRegister(ATTINY861_PIN pin);

/*
 * Get the 0-indexed bit number (0-7) of the given pin in the Data Direction register.
 * Place the result in bit_number.
 *
 * On failure, bit_number is unmodified.
 */
ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetDdrBit(ATTINY861_PIN pin, uint8_t * bit_number);

/*
 * Get a pointer to the Port Register for the given pin.
 *
 * Returns NULL on failure.
 */
volatile uint8_t * ATtiny861_GpioMap_GetPortRegister(ATTINY861_PIN pin);

/*
 * Get the 0-indexed bit number (0-7) of the given pin in the PORT register.
 * Place the result in bit_number.
 *
 * On failure, bit_number is unmodified.
 */
ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetPortBit(ATTINY861_PIN pin, uint8_t * bit_number);

/*
 * Get a pointer to the Pin Register for the given pin.
 *
 * Returns NULL on failure.
 */
volatile uint8_t * ATtiny861_GpioMap_GetPinRegister(ATTINY861_PIN pin);

/*
 * Get the 0-indexed bit number (0-7) of the given pin in the PIN register.
 * Place the result in bit_number.
 *
 * On failure, bit_number is unmodified.
 */
ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetPinBit(ATTINY861_PIN pin, uint8_t * bit_number);

#endif
