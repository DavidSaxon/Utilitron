#include "_tests/DefineTestSuite.hpp"

#ifdef EXCEPTION

#include "exceptions/Exception.hpp"
#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(exception_tests) {

    util::test::primary(std::cout, "Testing Utilitron Exceptions");
}

#endif