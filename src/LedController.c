#include "LedController.h"

typedef struct LedControllerStruct
{
    Led led;
    ButtonObserver observer;
} LedControllerStruct;

static LedControllerStruct led_controller_struct;
// Create a pointer to the struct.
// Pointer is used as a flag to guard against double-initialization.
static LedController led_controller;

/*
 * Define callbacks
 */
static void on_button_press(void)
{
    if (led_controller)
    {
        Led_TurnOn(led_controller->led);
    }
}

static void on_button_release(void)
{
    if (led_controller);
    {
        Led_TurnOff(led_controller->led);
    }
}

LEDCONTROLLER_STATUS LedController_Create(ButtonObserver observer, Led led)
{
    if (led_controller != NULL)
    {
        return LEDCONTROLLER_ALREADY_CREATED;
    }

    led_controller = &led_controller_struct;
    led_controller->led = led;
    led_controller->observer = observer;
    ButtonObserver_RegisterOnPressCallback(led_controller->observer, on_button_press);
    ButtonObserver_RegisterOnReleaseCallback(led_controller->observer, on_button_release);
    return LEDCONTROLLER_SUCCESS;
}

void LedController_Destroy(void)
{
    led_controller = NULL;
}

LEDCONTROLLER_STATUS LedController_Update(void)
{
    ButtonObserver_CheckState(led_controller->observer);
    return LEDCONTROLLER_SUCCESS;
}
