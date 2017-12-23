#ifndef LED_CONTROLLER_INCLUDED
#define LED_CONTROLLER_INCLUDED

#include "Led.h"
#include "ButtonObserver.h"

typedef struct LedControllerStruct * LedController;

LedController LedController_Create(ButtonObserver observer, Led led);
void LedController_Destroy(LedController * self);

typedef enum
{
    LEDCONTROLLER_SUCCESS   = 0
} LEDCONTROLLER_STATUS;
LEDCONTROLLER_STATUS LedController_Update(LedController self);

#endif
