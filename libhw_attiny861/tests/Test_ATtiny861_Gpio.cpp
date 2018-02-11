extern "C"
{
#include "ATtiny861_Gpio.h"
#include "MockHw_ATtiny861.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(ATtiny861_Gpio)
{
    ATTINY861_STATUS_CODE ret;

    void setup()
    {
        MockHw_ATtiny861_Reset();
        ATtiny861_GpioInit();
    }

    void teardown()
    {
    }
};

TEST(ATtiny861_Gpio, after_init_pins_set_to_input_with_pullup_high)
{
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0xff, PORTB);
}



// Initialize Port A gpio as output low
TEST(ATtiny861_Gpio, set_PA0_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_PA1_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA1) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA1) );
}

TEST(ATtiny861_Gpio, set_PA2_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA2, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA2) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA2) );
}

TEST(ATtiny861_Gpio, set_PA3_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA3) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_PA4_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA4, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA4) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA4) );
}

TEST(ATtiny861_Gpio, set_PA5_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA5, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA5) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA5) );
}

TEST(ATtiny861_Gpio, set_PA6_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA6) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA6) );
}

TEST(ATtiny861_Gpio, set_PA7_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA7) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA7) );
}



// Initialize Port A gpio as output high
TEST(ATtiny861_Gpio, set_PA0_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA0) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_PA1_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA1) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA1) );
}

TEST(ATtiny861_Gpio, set_PA2_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA2, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA2) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA2) );
}

TEST(ATtiny861_Gpio, set_PA3_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA3) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_PA4_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA4, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA4) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA4) );
}

TEST(ATtiny861_Gpio, set_PA5_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA5, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA5) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA5) );
}

TEST(ATtiny861_Gpio, set_PA6_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA6) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA6) );
}

TEST(ATtiny861_Gpio, set_PA7_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA7) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA7) );
}



// Initialize Port B pins output low
TEST(ATtiny861_Gpio, set_PB0_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB0) );
}

TEST(ATtiny861_Gpio, set_PB1_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB1, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB1) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB1) );
}

TEST(ATtiny861_Gpio, set_PB2_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB2, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB2) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB2) );
}

TEST(ATtiny861_Gpio, set_PB3_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB3, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB3) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB3) );
}

TEST(ATtiny861_Gpio, set_PB4_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB4, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB4) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB4) );
}

TEST(ATtiny861_Gpio, set_PB5_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB5, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB5) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB5) );
}

TEST(ATtiny861_Gpio, set_PB6_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB6, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB6) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB6) );
}

TEST(ATtiny861_Gpio, set_PB7_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB7, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB7) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB7) );
}



// Initialize Port B pins as output high
TEST(ATtiny861_Gpio, set_PB0_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB0) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB0) );
}

TEST(ATtiny861_Gpio, set_PB1_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB1, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB1) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB1) );
}

TEST(ATtiny861_Gpio, set_PB2_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB2, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB2) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB2) );
}

TEST(ATtiny861_Gpio, set_PB3_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB3, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB3) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB3) );
}

TEST(ATtiny861_Gpio, set_PB4_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB4, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB4) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB4) );
}

TEST(ATtiny861_Gpio, set_PB5_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB5, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB5) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB5) );
}

TEST(ATtiny861_Gpio, initialize_PB6_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB6, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB6) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB6) );
}

TEST(ATtiny861_Gpio, initialize_PB7_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB7, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB7) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB7) );
}



// Test SetState(). Direction must have already been set.
TEST(ATtiny861_Gpio, set_output_gpio_PA0_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
}
