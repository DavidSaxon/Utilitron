#ifndef UTILITRON_MESSAGEUTIL_H_
    #define UTILITRON_MESSAGEUTIL_H_

#include <iostream>

namespace util {

/*****************************************************\
| Functions for printing different priority messages. |
\*****************************************************/
namespace msg {

//FUNCTIONS
/**Prints a primary level message to the given output
@output the output stream to print to
@message the message to print*/
inline void primary(std::ostream& output, const std::string& message) {

    output << message << std::endl;
}

} } //util //msg

#endif