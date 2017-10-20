#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "LedHw.h"

typedef struct LedStruct * Led;

// Create a software abstraction for an LED
Led Led_Create(LEDHW_GPIO);
void Led_Destroy(Led);

LEDHW_STATE Led_GetState(Led);

#endif
