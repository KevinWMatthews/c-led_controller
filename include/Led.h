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
Led Led_Create(LEDHW_LED_NUMBER);
void Led_Destroy(Led * self);

typedef enum
{
    LED_OFF = 0,
    LED_ON  = 1
} LED_STATE;
LED_STATE Led_GetState(Led self);

// Turn an LED on.
// Returns 0 on success, < 0 on failure
LED_RETURN_CODE Led_TurnOn(Led self);

// Turn an LED off.
// Returns 0 on success, < 0 on failure
LED_RETURN_CODE Led_TurnOff(Led self);

#endif
