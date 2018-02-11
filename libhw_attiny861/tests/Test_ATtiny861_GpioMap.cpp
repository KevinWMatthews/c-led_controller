extern "C"
{
#include "ATtiny861_GpioMap.h"
#include <avr/io.h>
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(ATtiny861_GpioMap)
{
    volatile uint8_t * reg;

    void setup()
    {
    }

    void teardown()
    {
    }
};



/*
 * PINA register
 */
TEST(ATtiny861_GpioMap, get_PIN_register_PA0)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA0);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA1)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA1);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA2)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA2);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA3)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA3);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA4)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA4);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA5)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA5);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA6)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA6);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PA7)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA7);
    POINTERS_EQUAL( &PINA, reg );
}



/*
 * PINB register
 */
TEST(ATtiny861_GpioMap, get_PIN_register_PB0)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB0);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB1)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB1);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB2)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB2);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB3)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB3);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB4)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB4);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB5)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB5);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB6)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB6);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_PB7)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB7);
    POINTERS_EQUAL( &PINB, reg );
}
