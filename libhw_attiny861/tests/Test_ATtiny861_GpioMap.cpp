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
    uint8_t bit_number;
    int ret;

    void setup()
    {
    }

    void teardown()
    {
    }
};



/*
 * DDRA register
 */
TEST(ATtiny861_GpioMap, get_DDR_register_for_PA0)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA0);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA1)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA1);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA2)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA2);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA3)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA3);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA4)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA4);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA5)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA5);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA6)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA6);
    POINTERS_EQUAL( &DDRA, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PA7)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PA7);
    POINTERS_EQUAL( &DDRA, reg );
}



/*
 * DDRB register
 */
TEST(ATtiny861_GpioMap, get_DDR_register_for_PB0)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB0);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB1)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB1);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB2)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB2);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB3)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB3);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB4)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB4);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB5)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB5);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB6)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB6);
    POINTERS_EQUAL( &DDRB, reg );
}

TEST(ATtiny861_GpioMap, get_DDR_register_for_PB7)
{
    reg = ATtiny861_GpioMap_GetDdrRegister(ATTN861_PB7);
    POINTERS_EQUAL( &DDRB, reg );
}



/*
 * DDRA bits
 */
TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA0)
{
    ret = ATtiny861_GpioMap_GetDdrBit2(ATTN861_PA0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA0, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA1)
{
    ret = ATtiny861_GpioMap_GetDdrBit2(ATTN861_PA1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA1, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA2)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA2);
    BYTES_EQUAL( DDA2, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA3)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA3);
    BYTES_EQUAL( DDA3, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA4)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA4);
    BYTES_EQUAL( DDA4, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA5)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA5);
    BYTES_EQUAL( DDA5, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA6)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA6);
    BYTES_EQUAL( DDA6, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA7)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA7);
    BYTES_EQUAL( DDA7, bit );
}

/*
 * DDRB bits
 */
TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB1)
{
    ret = ATtiny861_GpioMap_GetDdrBit2(ATTN861_PB1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB1, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB2)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB2);
    BYTES_EQUAL( DDB2, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB3)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB3);
    BYTES_EQUAL( DDB3, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB4)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB4);
    BYTES_EQUAL( DDB4, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB5)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB5);
    BYTES_EQUAL( DDB5, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB6)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB6);
    BYTES_EQUAL( DDB6, bit );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB7)
{
    bit = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB7);
    BYTES_EQUAL( DDB7, bit );
}



/*
 * DDR Bit sanity checks
 */
TEST(ATtiny861_GpioMap, do_not_fail_with_null_bit_number)
{
    ret = ATtiny861_GpioMap_GetDdrBit2(ATTN861_PA0, NULL);
    LONGS_EQUAL( ATTINY861_GPIOMAP_NULL_POINTER, ret );
}

TEST(ATtiny861_GpioMap, return_error_for_invalid_bit_number)
{
    ret = ATtiny861_GpioMap_GetDdrBit2(255, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_INVALID_PIN, ret );
}




/*
 * PORTA register
 */
TEST(ATtiny861_GpioMap, get_PORT_register_for_PA0)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA0);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA1)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA1);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA2)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA2);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA3)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA3);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA4)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA4);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA5)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA5);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA6)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA6);
    POINTERS_EQUAL( &PORTA, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PA7)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PA7);
    POINTERS_EQUAL( &PORTA, reg );
}



/*
 * PORTB register
 */
TEST(ATtiny861_GpioMap, get_PORT_register_for_PB0)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB0);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB1)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB1);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB2)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB2);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB3)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB3);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB4)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB4);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB5)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB5);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB6)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB6);
    POINTERS_EQUAL( &PORTB, reg );
}

TEST(ATtiny861_GpioMap, get_PORT_register_for_PB7)
{
    reg = ATtiny861_GpioMap_GetPortRegister(ATTN861_PB7);
    POINTERS_EQUAL( &PORTB, reg );
}



/*
 * PORTA bits
 */
TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA0)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA0);
    BYTES_EQUAL( PORTA0, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA1)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA1);
    BYTES_EQUAL( PORTA1, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA2)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA2);
    BYTES_EQUAL( PORTA2, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA3)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA3);
    BYTES_EQUAL( PORTA3, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA4)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA4);
    BYTES_EQUAL( PORTA4, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA5)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA5);
    BYTES_EQUAL( PORTA5, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA6)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA6);
    BYTES_EQUAL( PORTA6, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA7)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PA7);
    BYTES_EQUAL( PORTA7, bit );
}

/*
 * PORTB bits
 */
TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB1)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB1);
    BYTES_EQUAL( PORTB1, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB2)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB2);
    BYTES_EQUAL( PORTB2, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB3)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB3);
    BYTES_EQUAL( PORTB3, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB4)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB4);
    BYTES_EQUAL( PORTB4, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB5)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB5);
    BYTES_EQUAL( PORTB5, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB6)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB6);
    BYTES_EQUAL( PORTB6, bit );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB7)
{
    bit = ATtiny861_GpioMap_GetPortBit(ATTN861_PB7);
    BYTES_EQUAL( PORTB7, bit );
}



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
