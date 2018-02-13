#ifndef _BIT_MANIP_INCLUDED
#define _BIT_MANIP_INCLUDED

#define BYTE_VALUE(bit_number)          (1<<(bit_number))

#define SET_BIT(byte, bit_number)       (byte) |= BYTE_VALUE(bit_number);

#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BYTE_VALUE(bit_number))
#define IS_BIT_SET(byte, bit_number)    ( (byte & BYTE_VALUE(bit_number)) && 1 )
#define IS_BIT_CLEAR(byte, bit_number)  ( !(byte & BYTE_VALUE(bit_number)) )

/*
 * Setting a bit in the PIN register toggles the corresponding bit in the associated PORT register.
 */
#define SET_BIT_INTERRUPT(byte, bit_number) \
    if (&byte == &PINA) \
        (PORTA) ^= BYTE_VALUE(bit_number); \
    else if (&byte == &PINB) \
        (PORTB) ^= BYTE_VALUE(bit_number) ;\
    else \
        (byte) = BYTE_VALUE(bit_number)

#endif
