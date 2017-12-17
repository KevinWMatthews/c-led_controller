extern "C"
{
#include "Button.h"
#include "Mock_ButtonHw.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Button)
{
    Button button;

    void setup()
    {
        MockButtonHw_Init();
        button = Button_Create(BUTTONHW_BUTTON_1);
    }

    void teardown()
    {
        Button_Destroy(&button);
    }
};

TEST(Button, create_and_destroy_a_button)
{
}

TEST(Button, by_default_button_is_released)
{
    LONGS_EQUAL( BUTTON_RELEASED, Button_GetState(button) );
}

TEST(Button, button_can_be_pressed)
{
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    LONGS_EQUAL( BUTTON_PRESSED, Button_GetState(button) );
}

// TEST(Button, can_destroy_a_null_led)
// {
//     Button_Destroy(NULL);
// }

// TEST(Button, button_is_null_after_destroy)
// {
//     Button button2 = Button_Create();
//     Button_Destroy(&button);
//     POINTERS_EQUAL(NULL, button2);
// }
