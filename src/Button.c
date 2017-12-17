#include "Button.h"

typedef struct ButtonStruct
{
    BUTTONHW_BUTTON_NUMBER button_number;
} ButtonStruct;

Button Button_Create(BUTTONHW_BUTTON_NUMBER button_number)
{
    Button self = calloc( 1, sizeof(*self) );
    self->button_number = button_number;
    return self;
}

void Button_Destroy(Button * self)
{
    free(*self);
}

BUTTON_STATE Button_GetState(Button self)
{
    if (self == NULL)
        return BUTTON_INVALID;

    return ButtonHw_GetState(self->button_number);
}
