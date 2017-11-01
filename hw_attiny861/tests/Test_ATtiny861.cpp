extern "C"
{
#include "ATtiny861.h"
#include "MockHw_ATtiny861.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtiny861)
{
    void setup()
    {
        MockHw_ATtiny861_Reset();
        ATtiny861_GpioInit();
    }

    void teardown()
    {
    }
};

TEST(ATtiny861, after_init_pins_set_to_input_with_pullup_high)
{
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA0_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    BYTES_EQUAL((1<<DDA0), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA0), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA1_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_LOW);
    BYTES_EQUAL((1<<DDA1), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA1), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA2_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA2, GPIO_LOW);
    BYTES_EQUAL((1<<DDA2), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA2), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA3_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA3, GPIO_LOW);
    BYTES_EQUAL((1<<DDA3), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA3), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA4_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA4, GPIO_LOW);
    BYTES_EQUAL((1<<DDA4), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA4), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA5_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA5, GPIO_LOW);
    BYTES_EQUAL((1<<DDA5), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA5), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA6_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA6, GPIO_LOW);
    BYTES_EQUAL((1<<DDA6), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA6), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA7_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA7, GPIO_LOW);
    BYTES_EQUAL((1<<DDA7), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA7), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PA0_as_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    BYTES_EQUAL((1<<DDA0), DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_PB0_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB0), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB0), PORTB);
}

TEST(ATtiny861, set_gpio_PB1_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB1, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB1), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB1), PORTB);
}

TEST(ATtiny861, set_gpio_PB2_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB2, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB2), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB2), PORTB);
}

TEST(ATtiny861, set_gpio_PB3_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB3, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB3), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB3), PORTB);
}

TEST(ATtiny861, set_gpio_PB4_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB4, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB4), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB4), PORTB);
}

TEST(ATtiny861, set_gpio_PB5_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB5, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB5), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB5), PORTB);
}

TEST(ATtiny861, set_gpio_PB6_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB6, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB6), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB6), PORTB);
}

TEST(ATtiny861, set_gpio_PB7_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB7, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB7), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB7), PORTB);
}

TEST(ATtiny861, set_gpio_PB0_as_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_HIGH);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL((1<<DDB0), DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_gpio_as_output_can_handle_invalid_gpio)
{
    ATtiny861_GpioSetAsOutput(ATTN861_GPIO_MAX, GPIO_LOW);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

// TEST(ATtiny861, set_gpio_as_output_can_handle_invalid_state)
// {
    // C++ won't allow this. What about C?
    // ATtiny861_GpioSetAsOutput(ATTN861_GPIO_MAX, 0);
// }

TEST(ATtiny861, set_output_can_handle_invalid_gpio)
{
    ATtiny861_GpioSetState(ATTN861_GPIO_MAX, GPIO_HIGH);
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_output_can_set_PA0_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_LOW);
    ATtiny861_GpioSetState(ATTN861_PA0, GPIO_HIGH);
    BYTES_EQUAL((1<<DDA0), DDRA);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}

TEST(ATtiny861, set_output_can_set_PA0_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    ATtiny861_GpioSetState(ATTN861_PA0, GPIO_LOW);

    BYTES_EQUAL((1<<DDA0), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA0), PORTA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTB);
}