#ifndef UTILITRON_FUNCTIONUTIL_H_
#   define UTILITRON_FUNCTIONUTIL_H_

#include <iostream>

namespace util {

/********************************************************\
| Utilities used for calling and manipulating functions. |
\********************************************************/
namespace func {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/**Calls a function with no parameters a given number of times
@param function the function to call
@param n the number of times to call the function*/
inline void repeatFunction(void (*function)(), unsigned n) {

    //call the function in a loop
    for (unsigned i = 0; i < n; ++i) {

        function();
    }
}

/**Calls a function with one parameter a given number of times
@param function the function to call
@param argument the argument to pass to the function
@param n the number of times to call the function*/
template <typename T>
inline void repeatFunction(void (*function)(T a), T argument, unsigned n) {

    for (unsigned i = 0; i < n; ++i) {

        function(argument);
    }
}

} } //util //func

#endif
