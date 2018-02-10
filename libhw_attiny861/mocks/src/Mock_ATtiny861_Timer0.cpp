extern "C"
{
#include "Mock_ATtiny861_Timer0.h"
#include <avr/io.h>
}

#include "CppUTestExt/MockSupport.h"

void Mock_ATtiny861_Timer0_CompareMatchA(void)
{
    // This will execute the corresponding ISR.
    // ISR will be declared in our mocked <avr/io.h>
    // We'll need to define the corresponding interrupts somewhere...
    // or can we inline them?
    // AVR seems to both declare and define the functions in <avr/io.h>. Try this.
    TIMER0_COMPA_vect();
}
