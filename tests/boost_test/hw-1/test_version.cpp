#define BOOST_TEST_MODULE test_version

#include <string>
#include "../../../hw-1/utils/utils.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    const int versionNum = globalGetVersion();
    BOOST_CHECK_MESSAGE(versionNum > 0, std::string("Version is incorrect! Expected >0. Got: ") + std::to_string(versionNum));
}

BOOST_AUTO_TEST_SUITE_END()
