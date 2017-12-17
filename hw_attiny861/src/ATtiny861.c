#include "ATtiny861.h"
#include "BitManip.h"
#include <avr/io.h>

// ddr: Data Direction Register (DDR)
//      Set for output, clear for input
// ddr_bit:
//      Which bit in DDR control this GPIO.
// port: Data register (PORT)
//  When input:
//      1       Enable internal pull-up
//      0       Disable internal pull-up
//  When output:
//      1       Drive pin high
//      0       Drive pin low
// port_bit:
//      Which port bit controls this gpio.
typedef struct ATtiny861_Gpio
{
    uint8_t * ddr;
    uint8_t ddr_bit;
    uint8_t * port;
    uint8_t port_bit;
} ATtiny861_Gpio;

// Specify all GPIOs
static ATtiny861_Gpio gpios[16] = {
    {   // PA0
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA0,
        .port_bit = PORTA0
    },
    {   // PA1
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA1,
        .port_bit = PORTA1
    },
    {   // PA2
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA2,
        .port_bit = PORTA2
    },
    {   // PA3
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA3,
        .port_bit = PORTA3
    },
    {   // PA4
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA4,
        .port_bit = PORTA4
    },
    {   // PA5
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA5,
        .port_bit = PORTA5
    },
    {   // PA6
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA6,
        .port_bit = PORTA6
    },
    {   // PA7
        .ddr = &DDRA,
        .port = &PORTA,
        .ddr_bit = DDA7,
        .port_bit = PORTA7
    },
    {   // PB0
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB0,
        .port_bit = PORTB0
    },
    {   // PB1
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB1,
        .port_bit = PORTB1
    },
    {   // PB2
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB2,
        .port_bit = PORTB2
    },
    {   // PB3
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB3,
        .port_bit = PORTB3
    },
    {   // PB4
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB4,
        .port_bit = PORTB4
    },
    {   // PB5
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB5,
        .port_bit = PORTB5
    },
    {   // PB6
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB6,
        .port_bit = PORTB6
    },
    {   // PB7
        .ddr = &DDRB,
        .port = &PORTB,
        .ddr_bit = DDB7,
        .port_bit = PORTB7
    }
};

void ATtiny861_GpioInit(void)
{
    // Pins should default to inputs on power-up.

    // The ATtiny861 datasheet, section 10.1.6 states that all unconnected pins
    // should be left as inputs and have their internal pull-up resistor driven high.
    PORTA = 0xff;
    PORTB = 0xff;
}

static void set_gpio_as_output(ATtiny861_Gpio *gpio)
{
    if (!gpio)
        return;

    // To set a GPIO as an output, set the Data Direction Register (DDR) bit.
    SBI( *(gpio->ddr), gpio->ddr_bit );
}

static void set_gpio_state(ATtiny861_Gpio *gpio, GPIO_STATE state)
{
    if (!gpio)
        return;

    if (state == GPIO_HIGH)
    {
        // To drive an output high, set the PORT bit
        SBI( *(gpio->port), gpio->port_bit );
    }
    else if (state == GPIO_LOW)
    {
        // To drive an output high, clear the PORT bit
        CBI( *(gpio->port), gpio->port_bit );
    }
}

ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    if (gpio >= ATTN861_GPIO_MAX)
    {
        return ATTINY861_GPIO_INVALID;
    }
    set_gpio_as_output(&gpios[gpio]);
    set_gpio_state(&gpios[gpio], initial_state);
    return ATTINY861_SUCCESS;
}

void ATtiny861_GpioSetState(ATTN861_GPIO gpio, GPIO_STATE state)
{
    if (gpio >= ATTN861_GPIO_MAX)
    {
        return;
    }
    set_gpio_state(&gpios[gpio], state);
}
