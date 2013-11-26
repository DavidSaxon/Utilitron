#include "_tests/DefineTestSuite.hpp"

#ifdef MATH

#include <cstdlib>
#include <sstream>

#include "FunctionUtil.hpp"
#include "MathUtil.hpp"
#include "StringUtil.hpp"
#include "TestingUtil.hpp"

//VARIABLES
template<typename T>
inline void withinTrueTest(void* vName) {

    std::string sl[3] = {
        "Testing true within on \'",
        *((std::string*) vName)
    };
    util::test::tertiary(std::cout, util::str::concatenate(sl, 2));

    //generate the values
    T a = (T) (rand() / 100000.0f);
    T b = (T) (rand() / 100000.0f);
    a = (T) (a / 2.0);
    b = (T) (b / 2.0);
    double range = (double) (((int) abs(a - b)) + (rand() % 5));

    BOOST_CHECK(util::math::within(a, b, (T) range));
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(math_util_tests) {

    util::test::primary(std::cout, "Testing Math Utilities");

    //seed the random number generator
    srand(time(NULL));

    util::test::secondary(std::cout, "Testing within function on char");
    std::string typeCName = "char";
    util::func::repeatFunction(withinTrueTest<char>, &typeCName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on signed char");
    std::string typeSCName = "signed char";
    util::func::repeatFunction(withinTrueTest<signed char>, &typeSCName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on unsigned char");
    std::string typeUCName = "unsigned char";
    util::func::repeatFunction(withinTrueTest<unsigned char>, &typeUCName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on short");
    std::string typeSName = "short";
    util::func::repeatFunction(withinTrueTest<short>, &typeSName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on unsigned short");
    std::string typeUSName = "unsigned short";
    util::func::repeatFunction(withinTrueTest<unsigned short>, &typeUSName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on int");
    std::string typeIName = "int";
    util::func::repeatFunction(withinTrueTest<int>, &typeIName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on unsigned int");
    std::string typeUIName = "unsigned int";
    util::func::repeatFunction(withinTrueTest<unsigned int>, &typeUIName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on long");
    std::string typeLName = "long";
    util::func::repeatFunction(withinTrueTest<long>, &typeLName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on unsigned long");
    std::string typeULName = "unsigned long";
    util::func::repeatFunction(withinTrueTest<unsigned long>, &typeULName, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing within function on long long");
    std::string typeLLName = "long long";
    util::func::repeatFunction(withinTrueTest<long long>, &typeLLName, TESTING_CYCLES);
}

#endif