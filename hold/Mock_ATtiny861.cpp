extern "C"
{
#include "ATtiny861Gpio.h"
}

#include "CppUTestExt/MockSupport.h"

ATTINY861_RETURN_CODE ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    mock().actualCall("ATtiny861_GpioSetAsOutput")
        .withParameter("gpio", gpio)
        .withParameter("initial_state", initial_state);
    return (ATTINY861_RETURN_CODE)mock().intReturnValue();
}

ATTINY861_RETURN_CODE ATtiny861_GpioSetState(ATTN861_GPIO gpio, GPIO_STATE state)
{
    mock().actualCall("ATtiny861_GpioSetState")
        .withParameter("gpio", gpio)
        .withParameter("state", state);
    return (ATTINY861_RETURN_CODE)mock().intReturnValue();
}
