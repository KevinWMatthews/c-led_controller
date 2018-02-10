#ifndef MOCK_BUTTONHW_INCLUDED
#define MOCK_BUTTONHW_INCLUDED

// Designed to allow the Button module to be tested without creating a
// dependency on specific hardware.
// Before each test, initialize the mock with Init(). This ensures that the actions of previous tests have no effect on the current test.
// During test setup, set the state of the mock hardware to simulate a physical button press or release. This corresponds to the ButtonHw layer noticing that a GPIO has been driven high or low but allows the Button module to ignore the specifics of the GPIO - you don't need to know which GPIO is toggld or if high/low corresponds to pressed/released.

// Set up the mock - make sure everything is cleared before first use.
void MockButtonHw_Init(void);

// Set the mock hardware to a particular state - pressed or released.
void MockButtonHw_SetState(BUTTONHW_BUTTON_NUMBER number, BUTTONHW_STATE state);

#endif
