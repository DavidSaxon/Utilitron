#ifndef UTILITRON_TESTINGUTIL_H_
#   define UTILITRON_TESTINGUTIL_H_

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

#include "MessageUtil.hpp"

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
const bool TERTIARY_TESTING_MESSAGES = false;

//FUNCTIONS
/*!Prints a primary testing message if enabled
@output the stream to print to
@message the message to print*/
inline void primary(std::ostream& output, const std::string& message) {

    if (PRIMARY_TESTING_MESSAGES) {

        util::msg::primary(output, message);
    }
}

/*!Prints a secondary testing message if enabled
@output the stream to print to
@message the message to print*/
inline void secondary(std::ostream& output, const std::string& message) {

    if (SECONDARY_TESTING_MESSAGES) {

        util::msg::secondary(output, message);
    }
}

/*!Prints a tertiary testing message if enabled
@output the stream to print to
@message the message to print*/
inline void tertiary(std::ostream& output, const std::string& message) {

    if (TERTIARY_TESTING_MESSAGES) {

        util::msg::tertiary(output, message);
    }
}

} } //util //test

#endif