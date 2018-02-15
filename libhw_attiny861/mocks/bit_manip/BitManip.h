#ifndef _BIT_MANIP_INCLUDED
#define _BIT_MANIP_INCLUDED

#include <avr/io.h>

#define BYTE_VALUE(bit_number)          (1<<(bit_number))

#define SET_BIT(byte, bit_number)       (byte) |= BYTE_VALUE(bit_number);

#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BYTE_VALUE(bit_number))

/*
 * Reading a bit in the PIN register reads the same bit in the corresponding PORT register.
 */
// Ouch. I think this is like an 'if/else if' statement.
// Can't think of a better way... a standard 'if' won't work because
// this macro is typically used as an Rvalue.
#define IS_BIT_SET(byte, bit_number) \
    (&byte == &PINA) ? \
    ( (PORTA & BYTE_VALUE(bit_number)) && 1 ) : \
    (&byte == &PINB) ? \
    ( (PORTB & BYTE_VALUE(bit_number)) && 1 ) : \
    ( (byte & BYTE_VALUE(bit_number)) && 1 )


#define IS_BIT_CLEAR(byte, bit_number)  ( !(byte & BYTE_VALUE(bit_number)) )

/*
 * Setting a bit in the PIN register toggles the same bit in the corresponding PORT register.
 */
#define SET_BIT_INTERRUPT(byte, bit_number) \
    if (&byte == &PINA) \
        (PORTA) ^= BYTE_VALUE(bit_number); \
    else if (&byte == &PINB) \
        (PORTB) ^= BYTE_VALUE(bit_number) ;\
    else \
        (byte) = BYTE_VALUE(bit_number)

#endif
