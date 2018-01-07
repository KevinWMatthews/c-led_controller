#ifndef LED2_H_INCLUDED
#define LED2_H_INCLUDED

typedef struct LedStruct * Led;

typedef enum
{
    LED_1       = 0
} LED_NUMBER;
Led Led_Create(LED_NUMBER);
void Led_Destroy(Led * self);

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
