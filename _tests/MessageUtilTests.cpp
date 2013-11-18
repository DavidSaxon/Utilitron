#include "_tests/DefineTestSuite.hpp"

#ifdef MESSAGE

#include "MessageUtil.hpp"
#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    std::cout << "--------------------------" << std::endl;
    std::cout << "Testing Message Utilities" << std::endl;
    std::cout << "--------------------------" << std::endl;

    //basically we are just going to print each type and make
    //sure nothing goes wrong
    util::msg::primary(std::cout, "Primary");
}

#endif