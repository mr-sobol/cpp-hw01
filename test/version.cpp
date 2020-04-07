#define BOOST_TEST_MODULE otus-homework-01
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "version.h"

BOOST_AUTO_TEST_CASE(version)
{
    BOOST_REQUIRE_GE(PROJECT_VERSION_MINOR, 0);
}
