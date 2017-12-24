#ifndef LED_CONTROLLER_INCLUDED
#define LED_CONTROLLER_INCLUDED

#include "Led.h"
#include "ButtonObserver.h"

typedef struct LedControllerStruct * LedController;

typedef enum
{
    LEDCONTROLLER_SUCCESS   = 0
} LEDCONTROLLER_STATUS;

// This is a single-instance module!
LEDCONTROLLER_STATUS LedController_Create(ButtonObserver observer, Led led);
void LedController_Destroy(void);

LEDCONTROLLER_STATUS LedController_Update(void);

#endif
