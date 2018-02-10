#ifndef BUTTON_OBSERVER_INCLUDED
#define BUTTON_OBSERVER_INCLUDED

#include "Button.h"

typedef struct ButtonObserverStruct * ButtonObserver;

ButtonObserver ButtonObserver_Create(Button button, BUTTON_STATE initial_state);
void ButtonObserver_Destroy(ButtonObserver * self);

typedef enum
{
    BUTTON_OBSERVER_INVALID = -3,
    BUTTON_OBSERVER_NULL    = -2,
    BUTTON_OBSERVER_DEFAULT = -1,   // Use to initialize a status variable and avoid a false match.
    BUTTON_OBSERVER_SUCCESS = 0
} BUTTON_OBSERVER_STATUS;

typedef void (*BUTTON_OBSERVER_ON_PRESS)(void);
typedef void (*BUTTON_OBSERVER_ON_RELEASE)(void);
BUTTON_OBSERVER_STATUS ButtonObserver_RegisterOnPressCallback(ButtonObserver self, BUTTON_OBSERVER_ON_PRESS on_press_callback);
BUTTON_OBSERVER_STATUS ButtonObserver_RegisterOnReleaseCallback(ButtonObserver self, BUTTON_OBSERVER_ON_RELEASE on_release_callback);

BUTTON_OBSERVER_STATUS ButtonObserver_CheckState(ButtonObserver self);

#endif
