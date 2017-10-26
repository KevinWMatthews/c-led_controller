extern "C"
{
#include "ATtiny861.h"
#include "avr/io.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ATtiny861)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ATtiny861, after_init_pins_set_to_input_with_pullup_high)
{
    ATtiny861_GpioInit();
    BYTES_EQUAL(0x00, DDRA);
    BYTES_EQUAL(0x00, DDRB);
    BYTES_EQUAL(0xff, PORTA);
    BYTES_EQUAL(0xff, PORTB);
}
