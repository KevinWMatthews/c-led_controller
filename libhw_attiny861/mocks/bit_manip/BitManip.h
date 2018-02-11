#ifndef _BIT_MANIP_INCLUDED
#define _BIT_MANIP_INCLUDED

#define BIT_VALUE(bit_number)           (1<<(bit_number))
#define SET_BIT(byte, bit_number)       (byte) |= BIT_VALUE(bit_number)
#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BIT_VALUE(bit_number))
#define IS_BIT_SET(byte, bit_number)    ( (byte & BIT_VALUE(bit_number)) && 1 )
#define IS_BIT_CLEAR(byte, bit_number)  ( !(byte & BIT_VALUE(bit_number)) )

#endif
