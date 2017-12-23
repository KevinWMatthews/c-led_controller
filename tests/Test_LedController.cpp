extern "C"
{
#include "LedController.h"
#include "Mock_ButtonHw.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedController)
{
    LEDCONTROLLER_STATUS ret;
    Led led;
    Button button;
    ButtonObserver observer;
    LedController led_controller;

    void setup()
    {
        MockButtonHw_Init();

        led = Led_Create(LEDHW_LED_1);
        button = Button_Create(BUTTONHW_BUTTON_1);
        observer = ButtonObserver_Create(button, BUTTON_RELEASED);
        led_controller = LedController_Create(observer, led);
    }

    void teardown()
    {
        LedController_Destroy(&led_controller);
        ButtonObserver_Destroy(&observer);
        Button_Destroy(&button);
        Led_Destroy(&led);
    }
};

TEST(LedController, can_be_created_and_destroyed)
{
}

TEST(LedController, can_destroy_a_null_pointer)
{
    LedController_Destroy(NULL);
}

TEST(LedController, do_nothing_when_button_is_not_pressed)
{
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);

    ret = LedController_Update(led_controller);
    LONGS_EQUAL( LEDCONTROLLER_SUCCESS, ret );
    LONGS_EQUAL( LED_OFF, Led_GetState(led) );
}

TEST(LedController, turn_on_led_when_button_is_pressed)
{
    LED_STATE led_state_1, led_state_2;
    // ButtonHw initial state is released.

    LedController_Update(led_controller);
    led_state_1 = Led_GetState(led);

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    LedController_Update(led_controller);
    led_state_2 = Led_GetState(led);

    LONGS_EQUAL( LED_OFF, led_state_1 );
    LONGS_EQUAL( LED_ON, led_state_2 );
}
