extern "C"
{
#include "ATtiny861_Gpio.h"
#include "Mock_ATtiny861_Registers.h"
#include <avr/io.h>
#include "BitManip.h"
}

#include "CppUTest/TestHarness.h"


TEST_GROUP(ATtiny861_Gpio)
{
    ATTINY861_RETURN_CODE ret;

    void setup()
    {
        Mock_ATtiny861_Registers_Reset();
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
#define IS_GPIO_OUTPUT(ddr, bit)    IS_BIT_SET(ddr, bit)
#define IS_GPIO_INPUT(ddr, bit)     IS_BIT_CLEAR(ddr, bit)

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
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_highest_pin_as_output_low)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA7) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, set_two_pins_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_LOW);
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA1) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA1) );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA3) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_lowest_port_a_pin_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA0) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_highest_port_a_pin_as_output_high)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA7) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, set_two_pins_as_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA1) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA1) );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA3) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA3) );
}

TEST(ATtiny861_Gpio, set_port_b_pin_as_output)
{
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRB, DDB0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTB, PORTB0) );
}

TEST(ATtiny861_Gpio, set_two_port_a_pins_to_different_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_HIGH);

    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRA, DDA1) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA1) );
}

TEST(ATtiny861_Gpio, set_two_port_b_pins_to_different_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PB1, GPIO_HIGH);

    CHECK_TRUE( IS_GPIO_OUTPUT(DDRB, DDB0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTB, PORTB0) );
    CHECK_TRUE( IS_GPIO_OUTPUT(DDRB, DDB1) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTB, PORTB1) );
}

TEST(ATtiny861_Gpio, set_as_output_will_not_set_invalid_pin)
{
    ret = ATtiny861_GpioSetAsOutput(66, GPIO_LOW);
    LONGS_EQUAL( ATTINY861_INVALID_PIN, ret );
}

TEST(ATtiny861_Gpio, set_as_output_will_not_set_pin_to_invalid_state)
{
    GPIO_STATE state = (GPIO_STATE)66;
    ret = ATtiny861_GpioSetAsOutput(ATTN861_PB0, state);
    LONGS_EQUAL( ATTINY861_INVALID_STATE, ret );
}



/*
 * Test SetState(). Direction must have already been set.
 */
TEST(ATtiny861_Gpio, set_high_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_low_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_HIGH);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, set_output_to_same_state)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA0) );
}

TEST(ATtiny861_Gpio, will_not_set_state_of_invalid_pin)
{
    ret = ATtiny861_GpioSetState(255, GPIO_LOW);

    LONGS_EQUAL( ATTINY861_INVALID_PIN, ret );
}

TEST(ATtiny861_Gpio, set_state_will_not_set_invalid_state)
{
    GPIO_STATE state = (GPIO_STATE)66;

    ret = ATtiny861_GpioSetState(ATTN861_PA0, state);

    LONGS_EQUAL( ATTINY861_INVALID_STATE, ret );
}


/*
 * GetState().
 */
TEST(ATtiny861_Gpio, get_state_of_port_A_output_low)
{
    GPIO_STATE state;
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);

    ret = ATtiny861_GpioGetState(ATTN861_PA0, &state);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    LONGS_EQUAL( GPIO_LOW, state );
}

TEST(ATtiny861_Gpio, get_state_of_port_A_output_high)
{
    GPIO_STATE state;
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);

    ret = ATtiny861_GpioGetState(ATTN861_PA0, &state);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    LONGS_EQUAL( GPIO_HIGH, state );
}

TEST(ATtiny861_Gpio, get_state_of_port_B_output_low)
{
    GPIO_STATE state;
    ATtiny861_GpioSetAsOutput(ATTN861_PB7, GPIO_LOW);

    ret = ATtiny861_GpioGetState(ATTN861_PB7, &state);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    LONGS_EQUAL( GPIO_LOW, state );
}

TEST(ATtiny861_Gpio, get_state_of_port_B_output_high)
{
    GPIO_STATE state;
    ATtiny861_GpioSetAsOutput(ATTN861_PB6, GPIO_HIGH);

    ret = ATtiny861_GpioGetState(ATTN861_PB6, &state);

    LONGS_EQUAL( ATTINY861_SUCCESS, ret );
    LONGS_EQUAL( GPIO_HIGH, state );
}

TEST(ATtiny861_Gpio, will_not_get_state_of_invalid_gpio)
{
    GPIO_STATE state;

    ret = ATtiny861_GpioGetState(66, &state);

    LONGS_EQUAL( ATTINY861_INVALID_PIN, ret );
}

TEST(ATtiny861_Gpio, will_not_fail_with_null_state_pointer)
{
    ret = ATtiny861_GpioGetState(ATTN861_PA0, NULL);

    LONGS_EQUAL( ATTINY861_NULL_POINTER, ret );
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

TEST(ATtiny861_Gpio, toggle_two_pins_in_opposite_states_reverse)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    ATtiny861_GpioToggle(ATTN861_PA0);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA0) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, toggle_two_adjacent_pins_in_opposite_states)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_HIGH);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);

    ATtiny861_GpioToggle(ATTN861_PA6);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA6) );
    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, toggle_two_adjacent_pins_in_opposite_states_reverse)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_LOW);
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_HIGH);

    ATtiny861_GpioToggle(ATTN861_PA6);
    ATtiny861_GpioToggle(ATTN861_PA7);

    CHECK_TRUE( GPIO_READS_HIGH(PORTA, PORTA6) );
    CHECK_TRUE( GPIO_READS_LOW(PORTA, PORTA7) );
}

TEST(ATtiny861_Gpio, will_not_toggle_invalid_pin)
{
    ret = ATtiny861_GpioToggle(255);

    LONGS_EQUAL( ATTINY861_INVALID_PIN, ret );
}
