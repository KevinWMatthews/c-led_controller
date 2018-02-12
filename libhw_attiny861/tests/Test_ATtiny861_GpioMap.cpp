extern "C"
{
#include "ATtiny861_GpioMap.h"
#include <avr/io.h>
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(ATtiny861_GpioMap)
{
    volatile uint8_t * reg;
    int8_t bit;

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
TEST(ATtiny861_GpioMap, get_PIN_register_for_PA0)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA0);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA1)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA1);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA2)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA2);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA3)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA3);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA4)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA4);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA5)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA5);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA6)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA6);
    POINTERS_EQUAL( &PINA, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PA7)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PA7);
    POINTERS_EQUAL( &PINA, reg );
}



/*
 * PINB register
 */
TEST(ATtiny861_GpioMap, get_PIN_register_for_PB0)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB0);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB1)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB1);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB2)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB2);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB3)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB3);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB4)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB4);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB5)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB5);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB6)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB6);
    POINTERS_EQUAL( &PINB, reg );
}

TEST(ATtiny861_GpioMap, get_PIN_register_for_PB7)
{
    reg = ATtiny861_GpioMap_GetPinRegister(ATTN861_PB7);
    POINTERS_EQUAL( &PINB, reg );
}


/*
 * PINA bits
 */
TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA0)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA0);
    BYTES_EQUAL( PINA0, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA1)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA1);
    BYTES_EQUAL( PINA1, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA2)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA2);
    BYTES_EQUAL( PINA2, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA3)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA3);
    BYTES_EQUAL( PINA3, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA4)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA4);
    BYTES_EQUAL( PINA4, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA5)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA5);
    BYTES_EQUAL( PINA5, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA6)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA6);
    BYTES_EQUAL( PINA6, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA7)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PA7);
    BYTES_EQUAL( PINA7, bit );
}

/*
 * PINB bits
 */
TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB1)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB1);
    BYTES_EQUAL( PINB1, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB2)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB2);
    BYTES_EQUAL( PINB2, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB3)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB3);
    BYTES_EQUAL( PINB3, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB4)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB4);
    BYTES_EQUAL( PINB4, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB5)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB5);
    BYTES_EQUAL( PINB5, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB6)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB6);
    BYTES_EQUAL( PINB6, bit );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB7)
{
    bit = ATtiny861_GpioMap_GetPinBit(ATTN861_PB7);
    BYTES_EQUAL( PINB7, bit );
}
