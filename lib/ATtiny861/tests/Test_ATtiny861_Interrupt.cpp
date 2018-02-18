extern "C"
{
#include "ATtiny861_Interrupt.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(ATtiny861_Interrupt)
{
    void setup()
    {
        mock().strictOrder();
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(ATtiny861_Interrupt, enable_global_interrupts)
{
    // Rather than checking that a bit is set,
    // ensure that the sei() macro is called.
    // sei() is converted directly into assembly.
    mock().expectOneCall("sei");
    ATtiny861_Interrupt_GlobalEnable();
}
