#include "ATtiny861.h"

int main(void)
{
    ATTINY861_STATUS_CODE ret;
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB6, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }

    return 0;
}
