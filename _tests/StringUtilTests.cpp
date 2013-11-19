#include "_tests/DefineTestSuite.hpp"

#ifdef STRING

#include "StringUtil.hpp"
#include "TestingUtil.hpp"

//VARIABLES

/*!Functions that tests the centre method*/
inline void centreTest() {

    std::cout << "Hello World" << std::endl;
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    std::cout << "--------------------------" << std::endl;
    std::cout << "Testing String Utilities" << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::string tester = "Hello World";

    //TODO: secondary message

    unsigned numOfLines = util::str::centre(tester, 80);

    if (numOfLines == 1) {

        //check that the string is that many characters long long
    }
}

#endif