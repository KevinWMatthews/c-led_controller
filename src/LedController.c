#include "LedController.h"

typedef struct LedControllerStruct
{
    Led led;
    ButtonObserver observer;
} LedControllerStruct;

static LedControllerStruct led_controller;

/*
 * Define callbacks
 */
static void on_button_press(void)
{
    Led_TurnOn(led_controller.led);
}

LEDCONTROLLER_STATUS LedController_Create(ButtonObserver observer, Led led)
{
    led_controller.led = led;
    led_controller.observer = observer;
    ButtonObserver_RegisterOnPressCallback(led_controller.observer, on_button_press);
    return LEDCONTROLLER_SUCCESS;
}

void LedController_Destroy(void)
{
    return;
}

LEDCONTROLLER_STATUS LedController_Update(void)
{
    ButtonObserver_CheckState(led_controller.observer);
    return LEDCONTROLLER_SUCCESS;
}
