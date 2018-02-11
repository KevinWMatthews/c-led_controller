#ifndef BIT_MANIP_INCLUDED
#define BIT_MANIP_INCLUDED



/*
 * Convert a (0-indexed) bit number into a byte value.
 *
 * This is the same as AVR's _BV() macro.
 *
 * Ex:
 *      BIT_VALUE(0) = (1<<0) = 0x00
 *      BIT_VALUE(1) = (1<<1) = 0x01
 *      BIT_VALUE(7) = (1<<7) = 0x80
 */
#define BIT_VALUE(bit_number)           (1<<(bit_number))

/*
 * AVR removed support for their sbi() and cbi() macros for reasons that
 * are not yet clear to me. Perhaps very old sbi() and cbi() macros gave
 * direct access to the SBI() and CBI() assembler instructions? Not sure.
 * See <compat/deprecated.h> for details.
 *
 * There seems to be no harm in reimplementing macros to make code more readable.
 * The assembly was the same in the tests that I ran.
 */

/*
 * Set the given (0-indexed) bit in the byte.
 *
 * Ex:
 *      SET_BIT(var, 0) =>  var |= 1<<0;
 *      SET_BIT(var, 7) =>  var |= 1<<7;
 */
#define SET_BIT(byte, bit_number)       (byte) |= BIT_VALUE(bit_number)

/*
 * Clear the given (0-indexed) bit in the byte.
 *
 * Ex:
 *      SET_BIT(var, 0) =>  var &= ~(1<<0);
 *      SET_BIT(var, 7) =>  var &= ~(1<<7);
 */
#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BIT_VALUE(bit_number))

#endif
