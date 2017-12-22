extern "C"
{
#include "ButtonObserver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(ButtonObserver)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ButtonObserver, can_be_created_and_destroyed)
{
    ButtonObserver observer;
    observer = ButtonObserver_Create(BUTTON_RELEASED);
    ButtonObserver_Destroy(&observer);
    POINTERS_EQUAL(NULL, observer);
}
