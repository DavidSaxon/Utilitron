#include "_tests/DefineTestSuite.hpp"

#ifdef VECTOR2

#include "vector/Vector2.hpp"
#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(vector2_tests) {

    util::test::primary(std::cout, "Testing Vector2");
}

#endif