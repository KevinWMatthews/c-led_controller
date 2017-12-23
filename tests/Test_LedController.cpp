extern "C"
{
#include "LedController.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedController)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(LedController, can_be_created_and_destroyed)
{
    Led led = Led_Create(LEDHW_LED_1);
    Button button = Button_Create(BUTTONHW_BUTTON_1);
    ButtonObserver observer = ButtonObserver_Create(button, BUTTON_RELEASED);

    LedController led_controller = LedController_Create(observer, led);

    LedController_Destroy(&led_controller);
    ButtonObserver_Destroy(&observer);
    Button_Destroy(&button);
    Led_Destroy(&led);
}
