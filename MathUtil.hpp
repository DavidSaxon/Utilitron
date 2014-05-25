#ifndef UTILITRON_MATHUTIL_H_
#   define UTILITRON_MATHUTIL_H_

#include <cmath>

namespace util {

/******************************\
| Utilities relating to maths. |
\******************************/
namespace math {

//FUNCTIONS
/*!Clamps the values between the thresholds
@v the value to clamp
@lower the the lower threshold
@upper the upper threshold
@return the clamped value*/
template<typename T>
inline T clamp(T v, T lower, T upper) {

    if (v < lower) {

        return lower;
    }
    if (v > upper) {

        return upper;
    }

    return v;
}

/*!Ensures that the value is above the given threshold
@v the value to clamp
@threshold the threshold to clamp above
@return the clamped value*/
template<typename T>
inline T clampAbove(T v, T threshold) {

    if (v < threshold) {

        return threshold;
    }

    return v;
}

/*!Ensures that the value is below the given threshold
@v the value to clamp
@threshold the threshold to clamp above
@return the clamped value*/
template<typename T>
inline T clampBelow(T v, T threshold) {

    if (v > threshold) {

        return threshold;
    }

    return v;
}

/*!Checks if the two values are within the range of each other.
@a the first value to compare
@b the second value to compare
@range the range to check between the values*/
template<typename T>
inline bool within(T a, T b, T range) {

    //return if abs is less than
    return abs(a - b) <= range;
}

/*!Checks if the two values are within the range of each other.
@a the first value to compare
@b the second value to compare
@range the range to check between the values*/
template<>
inline bool within(float a, float b, float range) {

    //return if abs is less than
    return fabs(a - b) <= range;
}

/*!Checks if the two values are within the range of each other.
@a the first value to compare
@b the second value to compare
@range the range to check between the values*/
template<>
inline bool within(double a, double b, double range) {

    //return if abs is less than
    return fabs(a - b) <= range;
}

} } //util //math

#endif
