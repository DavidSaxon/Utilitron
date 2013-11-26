#include "_tests/DefineTestSuite.hpp"

#ifdef FUNCTION

#include <cstdlib>
#include <sstream>

#include "FunctionUtil.hpp"
#include "StringUtil.hpp"
#include "TestingUtil.hpp"

//VARIABLES
//the global counter variable
unsigned gCounter = 0;

inline void repeatNoArgsTestFunction() {

    //increment the global counter
    ++gCounter;
}

inline void repeatNoArgsTest() {

    //generate a random number of times to test the repeater
    unsigned n = rand() % 10000;

    std::string sl[3] = {
        "Repeating function ",
        util::str::convert<unsigned>(n),
        " times"
    };
    util::test::tertiary(std::cout, util::str::concatenate(sl, 3));

    //zero the counter
    gCounter = 0;
    //call the repeat function
    util::func::repeatFunction(repeatNoArgsTestFunction, n);

    //check that the counter is correct
    BOOST_CHECK(gCounter == n);
}

inline void repeatOneArgTestFunction(void* value) {

    gCounter += *((int*) value);
}

inline void repeatOneArgTest() {

    //generate a random number of times to test the repeater
    unsigned n = rand() % 10000;

    std::string sl[3] = {
        "Repeating function ",
        util::str::convert<unsigned>(n),
        " times"
    };
    util::test::tertiary(std::cout, util::str::concatenate(sl, 3));

    //generate a number to add
    unsigned add = rand() % 100;

    //zero the counter
    gCounter = 0;
    //call the repeat function
    util::func::repeatFunction(repeatOneArgTestFunction, &add, n);

    //calculate the desired number
    unsigned total = add * n;

    BOOST_CHECK(gCounter == total);
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    util::test::primary(std::cout, "Testing Function Utilities");

    //seed the random number generator
    srand(time(NULL));

    util::test::secondary(std::cout,
        "Testing repeatFunction with no arguments");
    for (unsigned i = 0; i < TESTING_CYCLES; ++i) {

        repeatNoArgsTest();
    }

    util::test::secondary(std::cout,
        "Testing repeatFunction with one arguments");
    util::func::repeatFunction(repeatOneArgTest, TESTING_CYCLES);
}

#endif