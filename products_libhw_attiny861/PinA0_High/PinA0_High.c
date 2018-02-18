#include "ATtiny861_Gpio.h"

/*
 * Basic hardware sanity check.
 * Set an output pin high to be sure that it works.
 */
int main(void)
{
    ATTINY861_RETURN_CODE ret;
    ret = ATtiny861_Gpio_SetAsOutput(ATTN861_PA0, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }

    return 0;
}
