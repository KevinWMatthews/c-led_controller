#include <avr/io.h>

int main(void)
{
  DDRA = 0;             // Set all pins as inputs (should happen on boot...)
  PORTA = 0xFF;         // Drive all unused inputs high (thus spake the docs)

  DDRA |= (1<<DDA0);    // Configure pin as output
  PORTA |= (1<<PA0);    // Drive output pin high

  DDRA |= (1<<DDA1);    // Configure pin as output
  PORTA &= ~(1<<PA1);   // Drive output pin low

  DDRA &= ~(1<<DDA4);   // Configure pin as input
  PORTA |= (1<<PA4);    // Activate pull-up resistor on input

  PORTA |= (1<<PA1);    // Drive output high
  PORTA &= ~(1<<PA1);   // Drive output low
}
