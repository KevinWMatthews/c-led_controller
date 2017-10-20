#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

typedef struct LedStruct * Led;

Led Led_Create(void);
void Led_Destroy(Led);

#endif
