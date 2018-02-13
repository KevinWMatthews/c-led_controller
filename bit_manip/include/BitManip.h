#ifndef BIT_MANIP_INCLUDED
#define BIT_MANIP_INCLUDED



/*
 * Convert a (0-indexed) bit number into a byte value.
 *
 * This is the same as AVR's _BV() macro.
 *
 * Ex:
 *      BYTE_VALUE(0) = (1<<0) = 0x00
 *      BYTE_VALUE(1) = (1<<1) = 0x01
 *      BYTE_VALUE(7) = (1<<7) = 0x80
 */
#define BYTE_VALUE(bit_number)           (1<<(bit_number))

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
#define SET_BIT(byte, bit_number)     	(byte) |= BYTE_VALUE(bit_number)



/*
 * Some registers, particularly interrupt enable registers, have special behavior:
 *  writing a 1 performs an operation, such as clearing a flag or toggling a bit.
 *  writing 0 has no effect.
 * In this case it is preferable to write the entire register (using =) rather
 * than using a set bit operation (|=).
 * Only bits that are set will have an effect, and the assembly is more concise.
 * It also avoids some perplexing bugs....
 *
 * From the AVR toolchain FAQ,
 * Why are (many) interrupt flags cleared by writing a logical 1?:
 *      Writing a logical 1 requires only a single OUT instruction, and
 *      it is clear that only this single interrupt request bit will be cleared.
 *      There is no need to perform a read-modify-write cycle
 *      (like, an SBI instruction),
 *      since all bits in these control registers are interrupt bits,
 *      and writing a logical 0 to the remaining bits (as it is done by the
 *      simple OUT instruction) will not alter them, so there is no risk of
 *      any race condition that might accidentally clear another interrupt
 *      request bit.
 *      So instead of writing
 *          TIFR |= _BV(TOV0); // wrong!
 *      simply use
 *          TIFR = _BV(TOV0);
 *
 */
// Do not use this on standard registers! It will clear all other bits.
#define SET_BIT_INTERRUPT(byte, bit_number)         (byte) = BYTE_VALUE(bit_number)



/*
 * Clear the given (0-indexed) bit in the byte.
 *
 * Ex:
 *      SET_BIT(var, 0) =>  var &= ~(1<<0);
 *      SET_BIT(var, 7) =>  var &= ~(1<<7);
 */
#define CLEAR_BIT(byte, bit_number)     (byte) &= ~(BYTE_VALUE(bit_number))


#endif
