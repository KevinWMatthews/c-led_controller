#if 1
#include <avr/io.h>

#define SET_BIT(port, bit)      (port) |= (_BV(bit))

int main(void)
{
    SET_BIT(PORTA, PORTA2);
    return 0;
}
#else
int main(void)
{
    PORTA |= (1<<PORTA2);
    return 0;
}
#endif
