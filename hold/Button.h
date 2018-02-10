#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED

#include "ButtonHw.h"

typedef struct ButtonStruct * Button;

Button Button_Create(BUTTONHW_BUTTON_NUMBER button_number);
void Button_Destroy(Button * self);

typedef enum
{
    BUTTON_INVALID  = -1,
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED  = 1
} BUTTON_STATE;
BUTTON_STATE Button_GetState(Button self);

#endif
