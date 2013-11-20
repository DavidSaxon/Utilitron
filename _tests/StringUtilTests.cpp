#include "_tests/DefineTestSuite.hpp"

#ifdef STRING

#include <cstdlib>
#include <sstream>

#include "FunctionUtil.hpp"
#include "StringUtil.hpp"
#include "TestingUtil.hpp"


//FUNCTIONS
inline void concatFrontTest() {

    //generate two strings
    unsigned lengthA = rand() % 100;
    unsigned lengthB = rand() % 100;

    //generate the character arrays with random chars
    char* charArrayA = new char[lengthA];
    char* charArrayB = new char[lengthB];
    for (unsigned i = 0; i < lengthA; ++i) {

        charArrayA[i] = rand() % 255;
    }
    for (unsigned i = 0; i < lengthB; ++i) {

        charArrayB[i] = rand() % 255;
    }

    //put int strings
    std::string a(charArrayA);
    std::string b(charArrayB);

    std::stringstream ss;
    ss << "Testing concatenateFront with \'" << b << "\' in front of \'" << a;
    util::test::tertiary(std::cout, ss.str());

    //concatenate
    std::string concat(a);

    util::str::concatenateFront(concat, b);

    //check if the length is the sum of the two originals
    BOOST_CHECK(concat.length() == a.length() + b.length());

    //check that the string has the correct characters
    for (unsigned i = 0; i < concat.length(); ++i) {

        //check the string in front
        if (i < b.length()) {

            BOOST_CHECK(concat[i] == b[i]);
        }
        //check the string behind
        else {

            BOOST_CHECK(concat[i] == a[i - b.length()]);
        }
    }
}

inline void concatBackTest() {

    //generate two strings
    unsigned lengthA = rand() % 100;
    unsigned lengthB = rand() % 100;

    //generate the character arrays with random chars
    char* charArrayA = new char[lengthA];
    char* charArrayB = new char[lengthB];
    for (unsigned i = 0; i < lengthA; ++i) {

        charArrayA[i] = rand() % 255;
    }
    for (unsigned i = 0; i < lengthB; ++i) {

        charArrayB[i] = rand() % 255;
    }

    //put int strings
    std::string a(charArrayA);
    std::string b(charArrayB);

    std::stringstream ss;
    ss << "Testing concatenateBack with \'" << b << "\' in behind \'" << a;
    util::test::tertiary(std::cout, ss.str());

    //concatenate
    std::string concat(a);

    util::str::concatenateBack(concat, b);

    //check if the length is the sum of the two originals
    BOOST_CHECK(concat.length() == a.length() + b.length());

    //check that the string has the correct characters
    for (unsigned i = 0; i < concat.length(); ++i) {

        //check the string in front
        if (i < a.length()) {

            BOOST_CHECK(concat[i] == a[i]);
        }
        //check the string behind
        else {

            BOOST_CHECK(concat[i] == b[i - a.length()]);
        }
    }
}

inline void centreTest() {

    //TODO:

    std::string tester = "Hello World";

    unsigned numOfLines = util::str::centre(tester, 80);
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    util::test::primary(std::cout, "Testing Message Utilities");

    //seed the random number generator
    srand(time(NULL));

    util::test::secondary(std::cout, "Testing concatenateFront");
    util::func::repeatFunction(concatFrontTest, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing concatenateBack");
    util::func::repeatFunction(concatBackTest, TESTING_CYCLES);
}

#endif