#include "ATtiny861_Interrupt.h"
#include <avr/interrupt.h>

void ATtiny861_Interrupt_GlobalEnable(void)
{
    sei();
}
