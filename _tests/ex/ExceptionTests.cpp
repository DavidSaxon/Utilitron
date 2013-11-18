#include "_tests/DefineTestSuite.hpp"

#ifdef EXCEPTION

#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(exception_tests) {

    std::cout << "--------------------------" << std::endl;
    std::cout << "Testing Exceptions" << std::endl;
    std::cout << "--------------------------" << std::endl;

    BOOST_CHECK(1 == 1);
}

#endif