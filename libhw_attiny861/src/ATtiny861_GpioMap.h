#ifndef ATTINY861_GPIOMAP_INCLUDED
#define ATTINY861_GPIOMAP_INCLUDED

#include "ATtiny861_Pins.h"

typedef enum
{
    ATTINY861_GPIOMAP_SUCCESS       = 0,
    ATTINY861_GPIOMAP_NULL_POINTER  = -1,
    ATTINY861_GPIOMAP_INVALID_PIN   = -2,
} ATTINY861_GPIOMAP_STATUS_CODE;

/*
 * Configuring and using GPIO requires knowledge of three registers:
 *  DDRxn: Data Direction Register, byte x, bit n
 *  PORTxn: Data Register, byte x, bit n
 *  PINxn: Port Input Pin Address, byte x, bit n
 *
 * There are several methods of mapping a GPIO to the appropriate registers and bits:
 *  Manually.
 *      The traditional way?
 *      This spreads an explicit chip dependency throughout the code and is not easily testable.
 *      It also requires frequent references to the manual.
 *  Switch statement
 *      Map using several switch statements.
 *  Struct
 *      Map using structures.
 *  Macros
 *      I bet we could define ATTN861_Pxn in some fancy way
 *      and decode information from this.
 */

// Returns a pointer to memory on success, NULL on failure.
volatile uint8_t * ATtiny861_GpioMap_GetDdrRegister(ATTINY861_PIN pin);

/*
 * Get the 0-indexed bit number (0-7) of the given pin and place it in bit_number.
 *
 * On failure, bit_number is unmodified.
 */
ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetDdrBit(ATTINY861_PIN pin, uint8_t * bit_number);

// Returns a pointer to memory on success, NULL on failure.
volatile uint8_t * ATtiny861_GpioMap_GetPortRegister(ATTINY861_PIN pin);

/*
 * Get the 0-indexed bit number (0-7) of the given pin and place it in bit_number.
 *
 * On failure, bit_number is unmodified.
 */
ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetPortBit(ATTINY861_PIN pin, uint8_t * bit_number);

volatile uint8_t * ATtiny861_GpioMap_GetPinRegister(ATTINY861_PIN pin);

ATTINY861_GPIOMAP_STATUS_CODE ATtiny861_GpioMap_GetPinBit(ATTINY861_PIN pin, uint8_t * bit_number);

#endif
