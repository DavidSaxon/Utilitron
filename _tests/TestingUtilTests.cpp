#include "_tests/DefineTestSuite.hpp"

#ifdef TESTING

#include <iostream>

#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(testing_utils_tests) {

    util::test::primary(std::cout, "Testing Testing Utilities");
}

#endif