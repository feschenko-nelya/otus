#include <gtest/gtest.h>
#include <string>
#include "../../../hw-2/utils/IpAddress.h"
using namespace std;

TEST(TestGroup, SubTest_1)
{
    IpAddress addr;
    ASSERT_FALSE(addr.read(wstring(L"kjhkjhkj")));
    ASSERT_TRUE(addr.read(wstring(L"127.0.0.1")));
    ASSERT_TRUE(addr.read(wstring(L"127.0.0.1	123.4.5.6")));
}

TEST(TestGroup, SubTest_2)
{
    IpAddress addr;

    addr.read(wstring(L"127.0.0.1"));
    ASSERT_TRUE(addr.getNumbers().size() == 4);

    addr.read(wstring(L"127.0.0.1	123.4.5.6"));
    ASSERT_TRUE(addr.getNumbers().size() == 4);
}

TEST(TestGroup, SubTest_3)
{
    IpAddress addr;

    addr.read(wstring(L"127.0.0.1"));
    ASSERT_TRUE(addr.contains(127));
    ASSERT_FALSE(addr.contains(7));

    addr.read(wstring(L"127.0.0.1	123.4.5.6"));
    ASSERT_TRUE(addr.contains(127));
    ASSERT_FALSE(addr.contains(2));
    ASSERT_FALSE(addr.contains(7));
    ASSERT_TRUE(addr.contains(1));
    ASSERT_TRUE(addr.contains(0));

    ASSERT_FALSE(addr.contains(123));
    ASSERT_FALSE(addr.contains(4));
    ASSERT_FALSE(addr.contains(5));
    ASSERT_FALSE(addr.contains(6));
}

TEST(TestGroup, SubTest_4)
{
    IpAddress addr;
    addr.read(wstring(L"127.0.0.1"));
    ASSERT_FALSE(addr.isEmpty());

    addr.read(wstring(L"127.0.0.1	123.4.5.6"));
    ASSERT_FALSE(addr.isEmpty());

    addr.read(wstring(L"kjhkjhkj"));
    ASSERT_TRUE(addr.isEmpty());
}

TEST(TestGroup, SubTest_5)
{
    IpAddress addr1;
    IpAddress addr2;

    addr1.read(wstring(L"127.0.0.1"));
    addr2.read(wstring(L"127.0.0.2"));

    ASSERT_TRUE(addr1.isLess(addr2));

    addr1.read(wstring(L"127.0.0.1"));
    addr2.read(wstring(L"127.0.1.0"));

    ASSERT_TRUE(addr1.isLess(addr2));

    addr1.read(wstring(L"127.0.0.1"));
    addr2.read(wstring(L"127.1.0.0"));

    ASSERT_TRUE(addr1.isLess(addr2));

    addr1.read(wstring(L"127.0.0.1"));
    addr2.read(wstring(L"128.0.0.0"));

    ASSERT_TRUE(addr1.isLess(addr2));
}

TEST(TestGroup, SubTest_6)
{
    IpAddress addr;
    addr.read(wstring(L"kjhkjhkj"));

    ASSERT_TRUE(addr.getAddress() == wstring());

    addr.read(wstring(L"127.0.0.1	123.4.5.6"));
    ASSERT_TRUE(addr.getAddress() == wstring(L"127.0.0.1"));

    addr.read(wstring(L"123.4.5.6"));
    ASSERT_TRUE(addr.getAddress() == wstring(L"123.4.5.6"));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
