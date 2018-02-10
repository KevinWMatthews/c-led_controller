#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

typedef struct LedStruct * Led;

typedef enum
{
    LED_1       = 0
} LED_NUMBER;

/*
 * Create an LED handle and initialize the underlying GPIO as output.
 * LEDs default to the off state.
 */
Led Led_Create(LED_NUMBER);

/*
 * Free all resources associated with the LED handle
 * and set its pointer to NULL.
 * TODO should this tri-state the GPIO and turn the LED off?
 */
// void Led_Destroy(Led * self);

typedef enum
{
    LED_OFF = 0,
    LED_ON  = 1
} LED_STATE;
LED_STATE Led_GetState(Led self);

typedef enum
{
    LED_SUCCESS         =  0,
    LED_NULL_POINTER    = -1
} LED_RETURN_CODE;

// Turn an LED on.
LED_RETURN_CODE Led_TurnOn(Led self);

// Turn an LED off.
LED_RETURN_CODE Led_TurnOff(Led self);

#endif
