#ifndef UTILITRON_FUNCTIONUTIL_H_
#   define UTILITRON_FUNCTIONUTIL_H_

#include <iostream>

namespace util {

/*******************************\
| Utilities relating functions. |
\*******************************/
namespace func {

//FUNCTIONS
/*!Calls the given function with no arguments the given number of times
@function the function to call
@n the number of times to call the function*/
inline void repeatFunction(void (*function)(), unsigned n) {

    //call the function in a loop
    for (unsigned i = 0; i < n; ++i) {

        function();
    }
}


} } //util //func

#endif