#include "ButtonObserver.h"
#include <stdlib.h>


typedef struct ButtonObserverStruct
{
    Button button;
    BUTTON_STATE last_state;
    BUTTON_OBSERVER_ON_PRESS on_press;
    BUTTON_OBSERVER_ON_RELEASE on_release;
} ButtonObserverStruct;

ButtonObserver ButtonObserver_Create(Button button, BUTTON_STATE initial_state)
{
    ButtonObserver self = NULL;

    if (!button)
    {
        return NULL;
    }

    self = calloc( 1, sizeof(*self) );
    //TODO check if self is null?

    self->button = button;
    self->last_state = initial_state;
    return self;
}

void ButtonObserver_Destroy(ButtonObserver * self)
{
    if (self)
    {
        free(*self);
        *self = NULL;
    }
}

BUTTON_OBSERVER_STATUS ButtonObserver_RegisterOnPressCallback(ButtonObserver self, BUTTON_OBSERVER_ON_PRESS on_press_callback)
{
    if (!self)
    {
        return BUTTON_OBSERVER_NULL;
    }

    self->on_press = on_press_callback;
    return BUTTON_OBSERVER_SUCCESS;
}

BUTTON_OBSERVER_STATUS ButtonObserver_RegisterOnReleaseCallback(ButtonObserver self, BUTTON_OBSERVER_ON_RELEASE on_release_callback)
{
    if (!self)
    {
        return BUTTON_OBSERVER_NULL;
    }

    self->on_release = on_release_callback;
    return BUTTON_OBSERVER_SUCCESS;
}

BUTTON_OBSERVER_STATUS ButtonObserver_CheckState(ButtonObserver self)
{
    BUTTON_STATE current_state;

    if (!self)
    {
        return BUTTON_OBSERVER_NULL;
    }

    current_state = Button_GetState(self->button);
    if (current_state == BUTTON_INVALID)
    {
        return BUTTON_OBSERVER_INVALID;
    }

    if (current_state == self->last_state)
    {
        return BUTTON_OBSERVER_SUCCESS;
    }

    self->last_state = current_state;
    if (current_state == BUTTON_PRESSED)
    {
        if (self->on_press)
            self->on_press();
    }
    else if (current_state == BUTTON_RELEASED)
    {
        if (self->on_release)
            self->on_release();
    }

    return BUTTON_OBSERVER_SUCCESS;
}
