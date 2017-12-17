#include "ButtonHw.h"

//TODO this will need to be expanded to handle multiple buttons.
BUTTONHW_STATE button1_state;

void MockButtonHw_Init(void)
{
    button1_state = BUTTONHW_RELEASED;
}

void MockButtonHw_SetState(BUTTONHW_BUTTON_NUMBER number, BUTTONHW_STATE state)
{
    button1_state = state;
}

BUTTONHW_STATE ButtonHw_GetState(BUTTONHW_BUTTON_NUMBER button_number)
{
    return button1_state;
}
