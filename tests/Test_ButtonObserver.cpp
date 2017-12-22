extern "C"
{
#include "ButtonObserver.h"
#include "Mock_ButtonHw.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(ButtonObserver)
{
    Button button;
    ButtonObserver observer;
    BUTTON_OBSERVER_STATUS ret;

    void setup()
    {
        mock().strictOrder();

        MockButtonHw_Init();
        MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);

        button = Button_Create(BUTTONHW_BUTTON_1);
        observer = ButtonObserver_Create(button, BUTTON_RELEASED);
        ret = BUTTON_OBSERVER_DEFAULT;
    }

    void teardown()
    {
        ButtonObserver_Destroy(&observer);
        Button_Destroy(&button);
        mock().checkExpectations();
        mock().clear();
    }
};

/*
 * Mock callbacks
 */
void on_button_press_callback(void)
{
    mock().actualCall("on_button_press_callback");
}

void on_button_release_callback(void)
{
    mock().actualCall("on_button_release_callback");
}

/*
 * Create and destroy
 */
TEST(ButtonObserver, can_be_created_and_destroyed)
{
    ButtonObserver obs;
    obs = ButtonObserver_Create(button, BUTTON_RELEASED);
    ButtonObserver_Destroy(&obs);
    POINTERS_EQUAL(NULL, obs);
}

TEST(ButtonObserver, can_destroy_a_null_pointer)
{
    ButtonObserver_Destroy(NULL);
}

/*
 * Test button presses
 */
TEST(ButtonObserver, can_register_on_button_press_callback)
{
    ret = ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);
    LONGS_EQUAL(BUTTON_OBSERVER_SUCCESS, ret);
}

TEST(ButtonObserver, press_does_nothing_when_state_does_not_change)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);

    // Expect nothing.

    ButtonObserver_CheckState(observer);
}

TEST(ButtonObserver, executes_callback_when_button_is_pressed)
{
    // Initial HW state is released

    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);

    mock().expectOneCall("on_button_press_callback");

    ButtonObserver_CheckState(observer);        // Does nothing
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // Catches button press
}

TEST(ButtonObserver, callback_will_not_execute_twice_when_button_is_pressed_once)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);

    mock().expectOneCall("on_button_press_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // Catches press
    ButtonObserver_CheckState(observer);        // Does nothing
}

TEST(ButtonObserver, executes_callback_twice_when_button_is_pressed_twice)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);

    mock().expectOneCall("on_button_press_callback");
    mock().expectOneCall("on_button_press_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // Execute press callback
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // No callback, state change
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // Execute press callback
}

TEST(ButtonObserver, can_clear_on_press_callback)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);

    mock().expectOneCall("on_button_press_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);

    ButtonObserver_RegisterOnPressCallback(observer, NULL);
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // No callback, state change
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);
}

/*
 * Test button releases
 */
TEST(ButtonObserver, can_register_on_button_release_callback)
{
    ret = ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);
    LONGS_EQUAL(BUTTON_OBSERVER_SUCCESS, ret);
}

TEST(ButtonObserver, release_does_nothing_when_state_does_not_change)
{
    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    // Expect nothing.

    ButtonObserver_CheckState(observer);
}

TEST(ButtonObserver, executes_callback_when_button_is_released)
{
    // Initial HW state is released

    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    mock().expectOneCall("on_button_release_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // Catch state change, no callback
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // Catches release
}

TEST(ButtonObserver, callback_will_not_execute_twice_when_button_is_released_once)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_release_callback);

    mock().expectOneCall("on_button_release_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // Catches release
    ButtonObserver_CheckState(observer);        // Does nothing
}

TEST(ButtonObserver, executes_callback_twice_when_button_is_released_twice)
{
    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    mock().expectOneCall("on_button_release_callback");
    mock().expectOneCall("on_button_release_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // No callback, state change
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // Execute release callback

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // No callback, state change
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // Execute release callback
}

TEST(ButtonObserver, can_clear_on_release_callback)
{
    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    mock().expectOneCall("on_button_release_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // No callback, state change

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);        // Execute release callback

    ButtonObserver_RegisterOnReleaseCallback(observer, NULL);
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);        // No callback, state change
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);
}

TEST(ButtonObserver, executes_both_press_and_release_callbacks)
{
    ButtonObserver_RegisterOnPressCallback(observer, on_button_press_callback);
    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    mock().expectOneCall("on_button_press_callback");
    mock().expectOneCall("on_button_release_callback");

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);

    ButtonObserver_CheckState(observer);
}

/*
 * Test failures
 */
TEST(ButtonObserver, will_not_execute_button_release_after_invalid_status)
{
    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_release_callback);

    // Button is initially released

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_INVALID);
    ButtonObserver_CheckState(observer);
    ButtonObserver_CheckState(observer);

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_RELEASED);
    ButtonObserver_CheckState(observer);
}

TEST(ButtonObserver, will_not_execute_button_press_after_invalid_status)
{
    // Set initial HW state
    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);

    ButtonObserver_RegisterOnReleaseCallback(observer, on_button_press_callback);

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_INVALID);
    ButtonObserver_CheckState(observer);
    ButtonObserver_CheckState(observer);

    MockButtonHw_SetState(BUTTONHW_BUTTON_1, BUTTONHW_PRESSED);
    ButtonObserver_CheckState(observer);
}

/*
 * NULL checks
 */
TEST(ButtonObserver, will_not_create_observer_with_null_button)
{
    ButtonObserver obs;
    obs = ButtonObserver_Create(NULL, BUTTON_RELEASED);
    POINTERS_EQUAL(NULL, obs);
}

TEST(ButtonObserver, will_not_register_on_press_callback_to_null_struct)
{
    ret = ButtonObserver_RegisterOnPressCallback(NULL, on_button_press_callback);
    LONGS_EQUAL(BUTTON_OBSERVER_NULL, ret);
}

TEST(ButtonObserver, can_register_null_on_press_callback)
{
    ret = ButtonObserver_RegisterOnPressCallback(observer, NULL);
    LONGS_EQUAL(BUTTON_OBSERVER_SUCCESS, ret);
}

TEST(ButtonObserver, will_not_register_on_release_callback_to_null_struct)
{
    ret = ButtonObserver_RegisterOnReleaseCallback(NULL, on_button_release_callback);
    LONGS_EQUAL(BUTTON_OBSERVER_NULL, ret);
}

TEST(ButtonObserver, can_register_null_on_release_callback)
{
    ret = ButtonObserver_RegisterOnPressCallback(observer, NULL);
    LONGS_EQUAL(BUTTON_OBSERVER_SUCCESS, ret);
}

TEST(ButtonObserver, will_not_check_state_of_null_struct)
{
    ret = ButtonObserver_CheckState(NULL);
    LONGS_EQUAL(BUTTON_OBSERVER_NULL, ret);
}
