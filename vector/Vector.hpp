#ifndef UTILITRON_VECTOR_VECTOR_H_
#   define UTILITRON_VECTOR_VECTOR_H_

#include <iostream>
#include <cmath>

namespace util {

/******************************************\
| Vector classes for different dimensions, |
\******************************************/
namespace vec {

//ENUMERATORS
//!Access enumerators for the dimension values
enum {

    X = 0,
    Y,
    Z,
    W
};

//!Access enumerators for the colour values
enum {

    R = 0,
    G,
    B,
    A
};

//!Access enumerators for the measurement values
enum {

    WIDTH = 0,
    HEIGHT,
    DEPTH,
    FOURTH
};

} } //util //vec

#endif