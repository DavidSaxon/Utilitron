#include "_tests/DefineTestSuite.hpp"

#ifdef TESTING

#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(testing_utils_tests) {

    std::cout << "--------------------------" << std::endl;
    std::cout << "Testing Testing Utilities" << std::endl;
    std::cout << "--------------------------" << std::endl;

    BOOST_CHECK(1 == 1);
}

#endif