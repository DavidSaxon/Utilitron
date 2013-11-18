#ifndef UTILITRON_TESTINGUTIL_H_
#   define UTILITRON_TESTINGUTIL_H_

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

namespace util {
    
/************************************************\
| Useful functions and flags related to testing. |
\************************************************/
namespace test {

//VARIABLES
//!Is true to print primary testing messages
const bool PRIMARY_TESTING_MESSAGES = true;
//!Is true to print secondary testing messages
const bool SECONDARY_TESTING_MESSAGES = true;
//!Is true to print tertiary testing messages
const bool TERTIARY_TESTING_MESSAGES = true;

} } //util //test

#endif