#include "Mock_ATtiny861_Registers.h"
#include <avr/io.h>

void Mock_ATtiny861_Registers_Reset(void)
{
    DDRA = 0x00;
    PORTA = 0x00;
    PINA = 0x00;
    DDRB = 0x00;
    PORTB = 0x00;
    PINB = 0x00;
}
