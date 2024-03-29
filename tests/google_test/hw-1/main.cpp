#include <gtest/gtest.h>
#include <string>
#include "../../../hw-1/utils/utils.h"

TEST(TestGroup, SubTest_1)
{
    ASSERT_TRUE(globalGetVersion() != 0);
}

TEST(TestGroup, SubTest_2)
{
    ASSERT_FALSE(globalGetVersion() < 0);
}

TEST(TestGroup, SubTest_3)
{
    ASSERT_TRUE(globalGetVersion() > 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
