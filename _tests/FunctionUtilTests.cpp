#include <cstdlib>

#include "_tests/DefineTestSuite.hpp"

#ifdef FUNCTION

#include "FunctionUtil.hpp"
#include "TestingUtil.hpp"

//VARIABLES
//the global counter variable
unsigned gCounter = 0;


/*!Functions that tests the centre method*/
inline void repeatNoArgsTestFunction() {

    //increment the global counter
    ++gCounter;
}

/*!Tests the repeatFunction function with no arguments*/
inline void repeatNoArgsTest() {

    //TODO: tertiary message

    //generate a random number of times to test the repeater
    unsigned n = rand() % 10000;

    //zero the counter
    gCounter = 0;
    //call the repeat function
    util::func::repeatFunction(repeatNoArgsTestFunction, n);

    //check that the counter is correct
    BOOST_CHECK(gCounter == n);
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    std::cout << "--------------------------" << std::endl;
    std::cout << "Testing Function Utilities" << std::endl;
    std::cout << "--------------------------" << std::endl;

    //seed the random number generator
    srand(time(NULL));

    //TODO: secondary message

    for (unsigned i = 0; i < TESTING_CYCLES; ++i) {

        repeatNoArgsTest();
    }
    
}

#endif