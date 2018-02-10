#ifndef ATTINY861_GPIO_MAP_INCLUDED
#define ATTINY861_GPIO_MAP_INCLUDED

#include "ATtiny861_Pins.h"

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
 */

// Returns a pointer to memory on success, NULL on failure.
volatile uint8_t * ATtiny861_GpioMap_GetDdrRegister(ATTINY861_PIN pin);

// Returns 0-indexed bit number (0-7) on success, -1 on failure.
// You **MUST** check the return code!
// If the pin is invalid, you *will* set an undefined bit in memory.
int8_t ATtiny861_GpioMap_GetDdrBit(ATTINY861_PIN pin);

// Returns a pointer to memory on success, NULL on failure.
volatile uint8_t * ATtiny861_GpioMap_GetPortRegister(ATTINY861_PIN pin);

// Returns 0-indexed bit number (0-7) on success, -1 on failure.
// You **MUST** check the return code!
// If the pin is invalid, you *will* set an undefined bit in memory.
int8_t ATtiny861_GpioMap_GetPortBit(ATTINY861_PIN pin);

#endif
