#include "LedControllerConfig.h"
#include <stdio.h>

int main(void)
{
    printf("LedController Version %d.%d\n", LedController_VERSION_MAJOR, LedController_VERSION_MINOR);
    printf("Blink!\n");
    return 0;
}
