#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "LedHw.h"

typedef struct LedStruct * Led;

typedef enum
{
    LED_SUCCESS         =  0,
    LED_NULL_POINTER    = -1
} LED_RETURN_CODE;

// Create a software abstraction for an LED
Led Led_Create(LEDHW_GPIO);
void Led_Destroy(Led *);

LEDHW_STATE Led_GetState(Led);

// Turn an LED on.
// Returns 0 on success, < 0 on failure
LED_RETURN_CODE Led_TurnOn(Led);

// Turn an LED off.
// Returns 0 on success, < 0 on failure
LED_RETURN_CODE Led_TurnOff(Led);

#endif
