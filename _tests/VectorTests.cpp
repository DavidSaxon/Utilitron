#include "_tests/DefineTestSuite.hpp"

#ifdef VECTOR

#include "Vector.hpp"
#include "TestingUtil.hpp"

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(vector_tests) {

    util::test::primary(std::cout, "Testing Vector");

    util::vec::Vector2 v(1, 2);

    std::cout << v.x << std::endl;
    std::cout << v.r << std::endl;

    v.x = 5;

    std::cout << v.x << std::endl;
    std::cout << v.r << std::endl;

    v.r += 4;

    std::cout << v.x << std::endl;
    std::cout << v.width << std::endl;

    util::vec::Vector2 v1(v);
    v1.y += 5;

    std::cout << v1.x << std::endl;
    std::cout << v1.g << std::endl;
}

#endif