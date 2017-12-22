extern "C"
{
#include "LedController.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedController)
{

};

IGNORE_TEST(LedController, wiring_check)
{
    FAIL("Start here");
}
