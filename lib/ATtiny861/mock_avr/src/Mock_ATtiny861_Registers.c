#include "Mock_ATtiny861_Registers.h"
#include <avr/io.h>

/*
 * These registers are mapped to specific memory registers in chip-specific avr/io*.h files.
 * Mock registers are defined here to enable testing.
 */

void Mock_ATtiny861_Registers_Reset(void)
{
    ddra = 0x00;
    porta = 0x00;
    pina = 0x00;
    ddrb = 0x00;
    portb = 0x00;
    pinb = 0x00;
}


/*
 * GPIO Bank A
 */
volatile uint8_t ddra;
volatile uint8_t porta;
volatile uint8_t pina;

/*
 * GPIO Bank B
 */
volatile uint8_t ddrb;
volatile uint8_t portb;
volatile uint8_t pinb;

/*
 * Timer0
 */
volatile uint8_t ocr0a;
volatile uint8_t tccr0a;
// volatile uint8_t tcnt0l;
volatile uint8_t tccr0b;

volatile uint8_t timsk;
