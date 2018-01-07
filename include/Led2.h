#ifndef LED2_H_INCLUDED
#define LED2_H_INCLUDED

typedef struct LedStruct * Led;

typedef enum
{
    LED_1       = 0
} LED_NUMBER;
Led Led_Create(LED_NUMBER);
void Led_Destroy(Led * self);

#endif
