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
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA0, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA1)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA1, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA2)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA2, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA3)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA3, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA4)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA4, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA5)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA5, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA6)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA6, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PA7)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDA6, bit_number );
}

/*
 * DDRB bits
 */
TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB0)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB0, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB1)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB1, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB2)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB2, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB3)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB3, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB4)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB4, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB5)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB5, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB6)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB6, bit_number );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_for_PB7)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PB7, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( DDB7, bit_number );
}

/*
 * DDR bit sanity checks
 */
TEST(ATtiny861_GpioMap, get_DDR_bit_do_not_fail_with_null_bit_number)
{
    ret = ATtiny861_GpioMap_GetDdrBit(ATTN861_PA0, NULL);
    LONGS_EQUAL( ATTINY861_GPIOMAP_NULL_POINTER, ret );
}

TEST(ATtiny861_GpioMap, get_DDR_bit_return_error_for_invalid_bit_number)
{
    ret = ATtiny861_GpioMap_GetDdrBit(255, &bit_number);
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
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA0, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA1)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA1, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA2)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA2, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA3)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA3, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA4)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA4, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA5)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA5, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA6)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA6, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PA7)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PA7, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTA7, bit_number );
}

/*
 * PORTB bits
 */
TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB0)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB0, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB1)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB1, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB2)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB2, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB3)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB3, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB4)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB4, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB5)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB5, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB6)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB6, bit_number );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_for_PB7)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB7, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PORTB7, bit_number );
}

/*
 * PORT bit sanity checks
 */
TEST(ATtiny861_GpioMap, get_PORT_bit_do_not_fail_with_null_bit_number)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB0, NULL);
    LONGS_EQUAL( ATTINY861_GPIOMAP_NULL_POINTER, ret );
}

TEST(ATtiny861_GpioMap, get_PORT_bit_return_error_for_invalid_bit_number)
{
    ret = ATtiny861_GpioMap_GetPortBit(255, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_INVALID_PIN, ret );
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
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA0, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA1)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA1, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA2)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA2, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA3)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA3, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA4)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA4, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA5)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA5, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA6)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA6, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PA7)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PA7, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINA7, bit_number );
}

/*
 * PINB bits
 */
TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB0)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB0, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB0, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB1)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB1, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB1, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB2)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB2, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB2, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB3)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB3, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB3, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB4)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB4, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB4, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB5)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB5, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB5, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB6)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB6, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB6, bit_number );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_for_PB7)
{
    ret = ATtiny861_GpioMap_GetPortBit(ATTN861_PB7, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_SUCCESS, ret );
    BYTES_EQUAL( PINB7, bit_number );
}

/*
 * PIN bit sanity checks
 */
TEST(ATtiny861_GpioMap, get_PIN_bit_do_not_fail_with_null_bit_number)
{
    ret = ATtiny861_GpioMap_GetPinBit(ATTN861_PB0, NULL);
    LONGS_EQUAL( ATTINY861_GPIOMAP_NULL_POINTER, ret );
}

TEST(ATtiny861_GpioMap, get_PIN_bit_return_error_for_invalid_bit_number)
{
    ret = ATtiny861_GpioMap_GetPinBit(255, &bit_number);
    LONGS_EQUAL( ATTINY861_GPIOMAP_INVALID_PIN, ret );
}
