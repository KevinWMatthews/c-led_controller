#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

typedef struct LedStruct * Led;

Led Led_Create(void);
void Led_Destroy(Led);

typedef enum
{
    LED_OFF = 0
} LED_STATE;
LED_STATE Led_GetState(Led);

#endif
