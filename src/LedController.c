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
    //TODO this has to reference a file-scope variable!
    //This means that it is/will be tricky to have multiple LedControllers.
    //Should we have one controller monitor several buttons? Probably.
    //I guess that we want this object to controll all Led's
    Led_TurnOn(led_controller.led);
}

LedController LedController_Create(ButtonObserver observer, Led led)
{
    led_controller.led = led;
    led_controller.observer = observer;
    ButtonObserver_RegisterOnPressCallback(led_controller.observer, on_button_press);
    return &led_controller;
}

void LedController_Destroy(LedController * self)
{
    return;
}

LEDCONTROLLER_STATUS LedController_Update(LedController self)
{
    ButtonObserver_CheckState(self->observer);
    return LEDCONTROLLER_SUCCESS;
}
