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

/*
 * Output:          DDR bit high
 * Input:           DDR bit low
 * GPIO set high:   PORT bit high
 * GPIO set low:    PORT bit low
 * GPIO reads high: PIN bit high
 * GPIO reads low:  PIN bit low
 */
#define GPIO_SET_OUTPUT(ddr, bit)   IS_BIT_SET(ddr, bit)
#define GPIO_SET_INPUT(ddr, bit)    IS_BIT_CLEAR(ddr, bit)

#define GPIO_SET_HIGH(port, bit)    IS_BIT_SET(port, bit)
#define GIO_SET_LOW(port, bit)      IS_BIT_CLEAR(port, bit)

#define GPIO_READS_HIGH(pin, bit)   IS_BIT_SET(pin, bit)
#define GPIO_READS_LOW(pin, bit)    IS_BIT_CLEAR(pin, bit)

TEST(ATtiny861_Gpio, after_init_pins_set_to_input_with_pullup_high)
{
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0xff, PORTB);
}



/*
 * Initialize GPIO as output
 */
TEST(ATtiny861_Gpio, set_lowest_pin_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_highest_pin_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA7) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, set_two_pins_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_LOW);
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA1) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA1) );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA3) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_lowest_port_a_pin_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA0) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_highest_port_a_pin_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA7) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, set_two_pins_as_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA1) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA1) );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA3) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_port_b_pin_as_output)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB0) );
}

TEST(ATtiny861_Gpio, set_two_port_a_pints_to_different_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);

    CHECK_TRUE( IS_BIT_SET(DDRA, DDA0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
    CHECK_TRUE( IS_BIT_SET(DDRA, DDA1) );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA1) );
}

TEST(ATtiny861_Gpio, set_two_port_b_pints_to_different_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PB1, GPIO_HIGH);

    CHECK_TRUE( IS_BIT_SET(DDRB, DDB0) );
    CHECK_TRUE( IS_BIT_CLEAR(PORTB, PORTB0) );
    CHECK_TRUE( IS_BIT_SET(DDRB, DDB1) );
    CHECK_TRUE( IS_BIT_SET(PORTB, PORTB1) );
}



/*
 * Test SetState(). Direction must have already been set.
 */
TEST(ATtiny861_Gpio, set_high_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_low_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_SET(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_output_to_same_state)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_BIT_CLEAR(PORTA, PORTA0) );
}



/*
 * Toggle gpio
 */
TEST(ATtiny861_Gpio, toggle_PA0_from_low_to_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioToggle(ATTN861_PA0);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, toggle_PA0_from_high_to_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioToggle(ATTN861_PA0);
    ret = ATtiny861_GpioToggle(ATTN861_PA0);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, toggle_PB7)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    ret = ATtiny861_GpioToggle(ATTN861_PB7);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_LOW(PORTB, PORTB7) );
}

TEST(ATtiny861_Gpio, toggle_two_pins_from_high_to_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    ATtiny861_GpioToggle(ATTN861_PA0);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, toggle_two_pins_from_low_to_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    ATtiny861_GpioToggle(ATTN861_PA0);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA0) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, toggle_two_pins_in_opposite_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    ATtiny861_GpioToggle(ATTN861_PA0);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA7) );
}
