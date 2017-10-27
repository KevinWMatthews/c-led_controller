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
}

TEST(ATtiny861, set_gpio_PA1_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA1, GPIO_LOW);
    BYTES_EQUAL((1<<DDA1), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA1), PORTA);
}

TEST(ATtiny861, set_gpio_PA2_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA2, GPIO_LOW);
    BYTES_EQUAL((1<<DDA2), DDRA);
    BYTES_EQUAL(0xff & ~(1<<PORTA2), PORTA);
}

//TODO add other pins...

TEST(ATtiny861, set_gpio_PA0_as_output_high)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PA0, GPIO_HIGH);
    BYTES_EQUAL((1<<DDA0), DDRA);
    BYTES_EQUAL(0xff, PORTA);
}

//TODO add other pins...

TEST(ATtiny861, set_gpio_PB0_as_output_low)
{
    ATtiny861_GpioSetAsOutput(ATTN861_PB0, GPIO_LOW);
    BYTES_EQUAL((1<<DDB0), DDRB);
    BYTES_EQUAL(0xff & ~(1<<PORTB0), PORTB);
}
