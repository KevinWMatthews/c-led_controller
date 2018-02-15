#ifndef ATTINY861_PINS_INCLUDED
#define ATTINY861_PINS_INCLUDED

#include <inttypes.h>

/*
 * A list of pins on the ATtiny861.
 * Any integer constant is sufficient.
 * These are mapped to the pin numbers on the chip.
 *
 * See ATtiny861 datasheet, Figure 1-1.
 */
#define ATTN861_PA0     20
#define ATTN861_PA1     19
#define ATTN861_PA2     18
#define ATTN861_PA3     17
#define ATTN861_PA4     14
#define ATTN861_PA5     13
#define ATTN861_PA6     12
#define ATTN861_PA7     11
#define ATTN861_PB0     10
#define ATTN861_PB1     9
#define ATTN861_PB2     8
#define ATTN861_PB3     7
#define ATTN861_PB4     4
#define ATTN861_PB5     3
#define ATTN861_PB6     2
#define ATTN861_PB7     1

typedef uint8_t ATTINY861_PIN;

#endif
