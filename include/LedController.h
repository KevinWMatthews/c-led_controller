#ifndef LED_CONTROLLER_INCLUDED
#define LED_CONTROLLER_INCLUDED

#include "Led.h"
#include "ButtonObserver.h"

typedef struct LedControllerStruct * LedController;

LedController LedController_Create(ButtonObserver observer, Led led);
void LedController_Destroy(LedController * self);

#endif
