#include "ATtiny861.h"
#include "BitManip.h"
#include <avr/io.h>

/*
 * We need to know:
 *  DDRxn
 *      x is the byte
 *      n is the bit
 *  PORTxn
 *      byte x
 *      bit n
 *  PINxn
 *      byte x
 *      bit n
 *
 * Can use a switch statement or structures.
 */

ATTINY861_STATUS_CODE ATtiny861_GpioSetAsOutput2(ATTN861_GPIO gpio, GPIO_STATE initial_state)
{
    // hard-coded for pa0, output, low
    SBI(DDRA, DDA0);
    CBI(PORTA, PORTA0);
    return ATTINY861_SUCCESS;
}
/*
 * ddr: Data Direction Register (DDR)
 *      Set for output (1), clear for input (0)
 * ddr_bit:
 *      Which bit in DDR control this GPIO.
 *
 * port: Data Register (PORT)
 *  When input:
 *      1       Enable internal pull-up
 *      0       Disable internal pull-up
 *  When output:
 *      1       Drive pin high
 *      0       Drive pin low
 * port_bit:
 *      Which port bit controls this GPIO.
 *
 * pin: Port Input Pin Address (PIN)
 *      Read the value of the gpio, regardless of direction.
 *      (Writing 1 will toggle the value of the PORT pin, regardless of its state).
 * port_pin:
 *      Which pin bit controls this GPIO.
 */
typedef struct ATtiny861_Gpio
{
    volatile uint8_t * ddr;
    volatile uint8_t ddr_bit;
    volatile uint8_t * port;
    volatile uint8_t port_bit;
    volatile uint8_t *pin;
    volatile uint8_t pin_bit;
} ATtiny861_Gpio;

// Specify all GPIOs
static ATtiny861_Gpio gpios[16] = {
    {   // PA0
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA0,
        .port_bit = PORTA0,
        .pin_bit = PINA0
    },
    {   // PA1
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA1,
        .port_bit = PORTA1,
        .pin_bit = PINA1
    },
    {   // PA2
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA2,
        .port_bit = PORTA2,
        .pin_bit = PINA2
    },
    {   // PA3
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA3,
        .port_bit = PORTA3,
        .pin_bit = PINA3
    },
    {   // PA4
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA4,
        .port_bit = PORTA4,
        .pin_bit = PINA4
    },
    {   // PA5
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA5,
        .port_bit = PORTA5,
        .pin_bit = PINA5
    },
    {   // PA6
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA6,
        .port_bit = PORTA6,
        .pin_bit = PINA6
    },
    {   // PA7
        .ddr = &DDRA,
        .port = &PORTA,
        .pin = &PINA,
        .ddr_bit = DDA7,
        .port_bit = PORTA7,
        .pin_bit = PINA7
    },
    {   // PB0
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB0,
        .port_bit = PORTB0,
        .pin_bit = PINB0
    },
    {   // PB1
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB1,
        .port_bit = PORTB1,
        .pin_bit = PINB1
    },
    {   // PB2
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB2,
        .port_bit = PORTB2,
        .pin_bit = PINB2
    },
    {   // PB3
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB3,
        .port_bit = PORTB3,
        .pin_bit = PINB3
    },
    {   // PB4
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB4,
        .port_bit = PORTB4,
        .pin_bit = PINB4
    },
    {   // PB5
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB5,
        .port_bit = PORTB5,
        .pin_bit = PINB5
    },
    {   // PB6
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB6,
        .port_bit = PORTB6,
        .pin_bit = PINB6
    },
    {   // PB7
        .ddr = &DDRB,
        .port = &PORTB,
        .pin = &PINB,
        .ddr_bit = DDB7,
        .port_bit = PORTB7,
        .pin_bit = PINB7
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

static void set_gpio_as_output(ATtiny861_Gpio * gpio)
{
    if (!gpio)
        return;

    // To set a GPIO as an output, set the Data Direction Register (DDR) bit.
    //TODO check before dereferencing this pointer...
    SBI( *(gpio->ddr), gpio->ddr_bit );
}

static void set_gpio_state(ATtiny861_Gpio * gpio, GPIO_STATE state)
{
    if (!gpio)
        return;

    // if (!gpio->pin)
        // return;

    //TODO check before dereferencing the port pointer...
    if (state == GPIO_HIGH)
    {
        // To drive an output high, set the PORT bit
        // The corresponding PIN bit will respond appropriately.
        SBI( *(gpio->port), gpio->port_bit );
        //TEST CODE ONLY
        // *(gpio->pin);
        // SBI( *(gpio->pin), gpio->pin_bit );
    }
    else if (state == GPIO_LOW)
    {
        // To drive an output low, clear the PORT bit
        // The corresponding PIN bit will respond appropriately.
        CBI( *(gpio->port), gpio->port_bit );
    }
}

static GPIO_STATE get_gpio_state(ATtiny861_Gpio * gpio)
{
    // if (!gpio)
        // return GPIO_INVALID;
    if (!gpio->pin)
        return GPIO_INVALID;

    return *(gpio->pin) & gpio->pin_bit;
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

ATTINY861_STATUS_CODE ATtiny861_GpioSetState(ATTN861_GPIO gpio, GPIO_STATE state)
{
    if (gpio >= ATTN861_GPIO_MAX)
    {
        return ATTINY861_GPIO_INVALID;
    }
    set_gpio_state(&gpios[gpio], state);
    return ATTINY861_SUCCESS;
}

GPIO_STATE ATtiny861_GpioGetState(ATTN861_GPIO gpio)
{
    return get_gpio_state(&gpios[gpio]);
}
