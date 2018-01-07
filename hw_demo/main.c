#include "ATtiny861.h"

int main(void)
{
    ATTINY861_STATUS_CODE ret;
    ret = ATtiny861_GpioSetAsOutput2(ATTN861_PA0, GPIO_HIGH);
    if (ret < 0)
    {
        return -1;
    }

    return 0;
}
