#include "ATtiny861_Gpio.h"

/*
 * Basic hardware sanity check.
 * Set an output pin high to be sure that it works.
 */
int main(void)
{
    ATTINY861_STATUS_CODE ret;
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }

    return 0;
}
