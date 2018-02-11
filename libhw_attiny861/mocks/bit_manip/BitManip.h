#ifndef _BIT_MANIP_INCLUDED
#define _BIT_MANIP_INCLUDED

#define BIT_VALUE(bit_number)           (1<<(bit_number))
#define SET_BIT(byte, bit_number)       (byte) |= BIT_VALUE(bit_number)
#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BIT_VALUE(bit_number))

#endif
