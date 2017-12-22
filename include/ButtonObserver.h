#ifndef BUTTON_OBSERVER_INCLUDED
#define BUTTON_OBSERVER_INCLUDED

#include "Button.h"

typedef struct ButtonObserverStruct * ButtonObserver;

ButtonObserver ButtonObserver_Create(BUTTON_STATE state);
void ButtonObserver_Destroy(ButtonObserver * self);

#endif
