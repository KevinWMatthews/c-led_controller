#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "ATtiny861_Pins.h"

typedef struct LedStruct * Led;

typedef enum
{
    LED_SUCCESS         =  0,
    LED_NULL_POINTER    = -1,
    LED_ERROR           = -2,
} LED_RETURN_CODE;

/*
 * Create an LED handle and initialize the underlying GPIO as output.
 * LEDs default to the off state.
 */
typedef struct LedParams
{

} LedParams;
Led Led_Create(ATTINY861_PIN pin, LedParams *params);

/*
 * Free all resources associated with the LED handle
 * and set its pointer to NULL.
 * TODO should this turn the LED off and tri-state the GPIO?
 */
void Led_Destroy(Led * self);

typedef enum
{
    LED_OFF = 0,
    LED_ON  = 1
} LED_STATE;

/*
 * Get the state of the LED.
 * On error, state is unmodified and its value should not be used.
 */
LED_RETURN_CODE Led_GetState(Led self, LED_STATE *state);

/*
 * Turn an LED on.
 * On error, does nothing.
 */
LED_RETURN_CODE Led_TurnOn(Led self);

/*
 * Turn an LED off.
 * On error, does nothing.
 */
LED_RETURN_CODE Led_TurnOff(Led self);

/*
 * Toggle an LED.
 * On error, does nothing.
 */
LED_RETURN_CODE Led_Toggle(Led self);

#endif
