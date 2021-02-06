#include <gtest/gtest.h>
#include "dummy.hpp"

TEST(DummyTest, DummyTestDescription)
{
    ASSERT_TRUE(true);
    ASSERT_EQ(dummy(), 1);
}
