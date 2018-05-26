extern "C"
{
#include <avr/interrupt.h>
}

#include "CppUTestExt/MockSupport.h"

void sei(void)
{
    mock().actualCall("sei");
}
