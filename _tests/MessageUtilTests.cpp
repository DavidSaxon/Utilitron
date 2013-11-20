#include "_tests/DefineTestSuite.hpp"

#ifdef MESSAGE

#include "MessageUtil.hpp"
#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    util::test::primary(std::cout, "Testing Message Utilities");


    util::msg::primary(std::cout, "Primary");

    std::cout << std::endl;

    util::msg::secondary(std::cout, "Secondary");

    std::cout << std::endl;

    util::msg::tertiary(std::cout, "Tertiary");
}

#endif