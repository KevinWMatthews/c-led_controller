#if 1
// Equal_FunctionNotOptimized
// Requires adding bit_numbers.c to CMakeLists.txt
#include "bit_numbers.h"
#include <avr/io.h>

int main(void)
{
    int bit_number = get_bit_number();
    PINA = (1<<bit_number);
    return 0;
}
#endif

#if 0
// OrEqual_FunctionNotOptimized
// Requires adding bit_numbers.c to CMakeLists.txt
#include "bit_numbers.h"
#include <avr/io.h>

int main(void)
{
    int bit_number = get_bit_number();
    PINA |= (1<<bit_number);
    return 0;
}
#endif

#if 0
// OrEqual_FunctionStillOptimized
#include <avr/io.h>
int get_bit_number(int pin)
{
    switch (pin)
    {
        case 6:
        return PINA6;
        case 7:
        return PINA7;
    }
    return PINA0;
}

int main(void)
{
    int bit_number = get_bit_number(6);
    PINA |= (1<<bit_number);
    return 0;
}
#endif

#if 0
// OrEqual_FunctionOptimized
#include <avr/io.h>

int get_bit_number(void)
{
    return PINA6;
}

int main(void)
{
    int bit_number = get_bit_number();
    PINA |= (1<<bit_number);
    return 0;
}
#endif

#if 0
// Equal_Bitshift

#include <avr/io.h>

int main(void)
{
    PINA = (1<<PINA6);
    return 0;
}
#endif

#if 0
// OrEqual_Bitshift
#include <avr/io.h>

int main(void)
{
    PINA |= (1<<PINA6);
    return 0;
}
#endif

#if 0
#include <avr/io.h>

#define SET_BIT(port, bit)      (port) |= (_BV(bit))

int main(void)
{
    SET_BIT(PORTA, PORTA2);
    return 0;
}
#endif

#if 0
int main(void)
{
    PORTA |= (1<<PORTA2);
    return 0;
}
#endif
