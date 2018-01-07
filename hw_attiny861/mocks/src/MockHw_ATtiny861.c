#include "MockHw_ATtiny861.h"

void MockHw_ATtiny861_Reset(void)
{
    DDRA = 0x00;
    PORTA = 0x00;
    PINA = 0x00;
    DDRB = 0x00;
    PORTB = 0x00;
    PINB = 0x00;
}
