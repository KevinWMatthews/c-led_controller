#ifndef AVR_IO_H_INCLUDED
#define AVR_IO_H_INCLUDED

// These registers are mapped to specific memory registers in chip-specific avr/io*.h files.
// Mock registers are declared here to enable testing.
// See avr/io.h and avr/iotnx61.h.

#include <stdint.h>



/*
 * GPIO
 */
extern uint8_t DDRA;
// #define DDRA _SFR_IO8(0x1A)
#define DDA0 0
#define DDA1 1
#define DDA2 2
#define DDA3 3
#define DDA4 4
#define DDA5 5
#define DDA6 6
#define DDA7 7

extern uint8_t PORTA;
// #define PORTA _SFR_IO8(0x1B)
#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

extern uint8_t DDRB;
// #define DDRB _SFR_IO8(0x17)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

extern uint8_t PORTB;
// #define PORTB _SFR_IO8(0x18)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

extern uint8_t PINA;
// #define PINA    _SFR_IO8(0x19)
#define PINA0   0
#define PINA1   1
#define PINA2   2
#define PINA3   3
#define PINA4   4
#define PINA5   5
#define PINA6   6
#define PINA7   7

extern uint8_t PINB;
// #define PINB    _SFR_IO8(0x16)
#define PINB0   0
#define PINB1   1
#define PINB2   2
#define PINB3   3
#define PINB4   4
#define PINB5   5
#define PINB6   6
#define PINB7   7


/*
 * Timer 0
 */
extern uint8_t OCR0A;
// #define OCR0A   _SFR_IO8(0x13)

extern uint8_t TCCR0A;
// #define TCCR0A  _SFR_IO8(0x15)
// #define WGM00   0		/* up to at least datasheet rev. B */
#define CTC0    0		/* newer revisions; change not mentioned
				 * in revision history */
// #define ACIC0   3
// #define ICES0   4
// #define ICNC0   5
// #define ICEN0   6
#define TCW0    7

extern uint8_t TCCR0B;
// #define TCCR0B  _SFR_IO8(0x33)
#define CS00    0
#define CS01    1
#define CS02    2
// #define PSR0    3
// #define TSM     4


extern uint8_t TIMSK;
// #define TIMSK   _SFR_IO8(0x39)
// #define TICIE0  0
// #define TOIE0   1
// #define TOIE1   2
// #define OCIE0B  3
#define OCIE0A  4
// #define OCIE1B  5
// #define OCIE1A  6
// #define OCIE1D  7


/*
 * Interrupts
 *
 * These are defined in chip-specific io*.h files, such as iotn*61.h.
 * Various vector names are defined using the convention:
 *      #define <vector_name>_vect      _VECTOR(<n>)
 *
 * _VECTOR is defined in <avr/sfr_defs.h> as:
 *      #ifndef _VECTOR
 *      #define _VECTOR(N) __vector_ ## N
 *      #endif
 * This is a preprocessor substitution, not a compiler extension or attribute.
 * We should be able to skip the level of indirection and simply define
 * the vectors here.
 */

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect               vector_14_TIMER0_COMPA
// #define TIMER0_COMPA_vect_num		14
// #define TIMER0_COMPA_vect	    	_VECTOR(14)
// #define SIG_OUTPUT_COMPARE0A		_VECTOR(14)

#endif
