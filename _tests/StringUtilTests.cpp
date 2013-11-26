#include "_tests/DefineTestSuite.hpp"

#ifdef STRING

#include <cstdlib>
#include <sstream>

#include "FunctionUtil.hpp"
#include "StringUtil.hpp"
#include "TestingUtil.hpp"

//FUNCTIONS
template<typename T>
inline void convertTest(void* vName) {

    T v = rand();

    std::stringstream ss;
    ss << "Testing converting " << *((std::string*) vName) << ": \'" <<
        v << "\' to a string";
    util::test::tertiary(std::cout, ss.str());

    //convert
    std::string s(util::str::convert<T>(v));

    //convert using a string stream
    std::stringstream sc;
    sc << v;

    BOOST_CHECK(s == sc.str());
}

inline void convertBoolTest() {

    //generate a random boolean
    bool b =  rand() % 2;

    std::stringstream ss;
    ss << "Testing converting boolean \'" <<
        b << "\' to a string";
    util::test::tertiary(std::cout, ss.str());

    //convert
    std::string s(util::str::convert<bool>(b));

    if (b) {

        BOOST_CHECK(s == "true");
    }
    else {

        BOOST_CHECK(s == "false");
    }
}

inline void concatTest() {

    //generate the number of strings to concatenate
    unsigned n = rand() % 100;

    std::stringstream ss;
    ss << "Testing concatenate with " << n << " strings";
    util::test::tertiary(std::cout, ss.str());

    //std::string s

    //std::string s =(n);

    //create an array of strings
    std::string* strings = new std::string[n];

    //generate the strings
    for (unsigned i = 0; i < n; ++i) {

        //generate the length of the string
        unsigned l = rand() % 100;

        //create a char array
        char* charArray = new char[l];

        //fill with random characters
        for (unsigned j = 0; j < l; ++j) {

            charArray[j] = rand() % 255;
        }
    }


}

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

    //copy and concatenate
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

    //copy and concatenate
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

inline void genRepeatTest() {

    //generate a random character and a number of times to repeat
    char c = rand() % 255;
    unsigned n = rand() % 1000;


}

inline void centreTest() {

    //TODO:

    std::string tester = "Hello World";

    unsigned numOfLines = util::str::centre(tester, 80);
}

/*!Tests for all Utilities exceptions*/
BOOST_AUTO_TEST_CASE(message_util_tests) {

    util::test::primary(std::cout, "Testing String Utilities");

    //seed the random number generator
    srand(time(NULL));

    util::test::secondary(std::cout, "Testing convert on char");
    std::string typeChar("char");
    util::func::repeatFunction(convertTest<char>, &typeChar, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on signed char");
    std::string typeSChar("signed char");
    util::func::repeatFunction(convertTest<signed char>, &typeSChar, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on unsigned char");
    std::string typeUChar("unsigned char");
    util::func::repeatFunction(convertTest<unsigned char>, &typeUChar, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on short");
    std::string typeShort("short");
    util::func::repeatFunction(convertTest<short>, &typeShort, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on unsigned short");
    std::string typeUShort("unsigned short");
    util::func::repeatFunction(convertTest<unsigned short>, &typeUShort, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on int");
    std::string typeInt("int");
    util::func::repeatFunction(convertTest<int>, &typeInt, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on unsigned int");
    std::string typeUInt("unsigned int");
    util::func::repeatFunction(convertTest<unsigned int>, &typeUInt, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on long");
    std::string typeLong("long");
    util::func::repeatFunction(convertTest<long>, &typeLong, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on unsigned long");
    std::string typeULong("unsigned long");
    util::func::repeatFunction(convertTest<unsigned long>, &typeULong, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing convert on boolean");
    util::func::repeatFunction(convertBoolTest, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing concatenate");
    util::func::repeatFunction(concatTest, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing concatenateFront");
    util::func::repeatFunction(concatFrontTest, TESTING_CYCLES);

    util::test::secondary(std::cout, "Testing concatenateBack");
    util::func::repeatFunction(concatBackTest, TESTING_CYCLES);
}

#endif