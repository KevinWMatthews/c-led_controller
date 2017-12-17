#ifndef BUTTONHW_INCLUDED
#define BUTTONHW_INCLUDED

// This enum specifies Button numbers according to the end-user's perspective.
// This should match the schematic labels.
typedef enum
{
    BUTTONHW_BUTTON_1   = 0
} BUTTONHW_BUTTON_NUMBER;

typedef enum
{
    BUTTONHW_RELEASED   = 0,
    BUTTONHW_PRESSED    = 1
} BUTTONHW_STATE;
BUTTONHW_STATE ButtonHw_GetState(BUTTONHW_BUTTON_NUMBER button_number);

#endif
