#ifndef AVR_IO_H_INCLUDED
#define AVR_IO_H_INCLUDED

// These registers are mapped to specific memory registers in chip-specific avr/io*.h files.
// Mock registers are declared here to enable testing.
// See avr/io.h and avr/iotnx61.h.

#include <stdint.h>



//************//
//*** GPIO ***//
//************//
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

#endif
