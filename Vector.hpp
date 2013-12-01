#ifndef UTILITRON_VECTOR_VECTOR_H_
#   define UTILITRON_VECTOR_VECTOR_H_

#include <iostream>
#include <cmath>

#include "exceptions/ArrayException.hpp"

namespace util {

/****************************************************************\
| Vectors represented as classes with functions for vector math. |
\****************************************************************/
namespace vec {

//Vector2 TODO:
class Vector2 {
public:

    //VARIABLES
    //position co-ordinates access components
    float x;
    float y;

    //colour access components
    float& r;
    float& g;

    //measurement access components
    float& width;
    float& height;

    //CONSTRUCTORS
    /*!Creates a new two dimensional vector with the given values
    @aX the x value of the vector
    @aY the y value of the vector*/
    inline Vector2(float aX, float aY) :
        x(aX),
        y(aY),
        r(x),
        g(y),
        width(x),
        height(y) {
    }

    /*!Creates a new two dimensional vector by the copying the values from
    the given 2d vector
    @v2 the 2d vector copy from*/
    inline Vector2(const Vector2& v2) :
        x(v2.x),
        y(v2.y),
        r(x),
        g(y),
        width(x),
        height(y) {
    }

    //DESTRUCTOR
    /*!Destroys this vector*/
    inline ~Vector2() {
    }

    //OPERATORS
    /*!Sets the values of this vector by copying the values from the
    other given vector
    @other the vector to copy from*/
    inline Vector2& operator =(const Vector2& other) {

        x = other.x;
        y = other.y;

        return *this;
    }

    /*!@return if this vector and the other given vector are equal*/
    inline bool operator ==(const Vector2& other) const {

        return x == other.x && y == other.y;
    }

    /*!@return if this vector and the other given vector are not equal*/
    inline bool operator !=(const Vector2& other) const {

        return !((*this) == other);
    }

    /*!Gets the component of the vector at the given index
    @index the component to get
    @return the value of the component*/
    inline float& operator [](unsigned index) {

        //check that the index is within bounds
        if (index > 1) {

            util::ex::IndexOutOfBoundsException("index is greater than 1.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            default: {

                return y;
            }
        }
    }

    /*!Gets the component of the vector at the given index
    @index the component to get
    @return the value of the component*/
    inline const float& operator [](unsigned index) const {

        //check that the index is within bounds
        if (index > 1) {

            util::ex::IndexOutOfBoundsException("index is greater than 1.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            default: {

                return y;
            }
        }
    }

    /*!@return a copy of the vector which has been negated*/
    inline Vector2 operator -() const {

        return Vector2(-x, -y);
    }

    /*!Creates a new vector as the result of the addition of the components
    of this vector with the given scalar
    @scalar the scalar to add
    @return the result of the addition*/
    inline Vector2 operator +(float scalar) const {

        return Vector2(x + scalar, y + scalar);
    }

    /*!Adds the given scalar to the components of this vector
    @scalar the scalar to add*/
    inline void operator +=(float scalar) {

        x += scalar;
        y += scalar;
    }

    /*!Creates a new vector as the result of the addition of this vector
    and the other given vector
    @other the vector to add to this
    @return the result of the addition*/
    inline Vector2 operator +(const Vector2& other) const {

        return Vector2(x + other.x, y + other.y);
    }

    /*!Adds the given vector to this vector
    @other the vector to add to this*/
    inline void operator +=(const Vector2& other) {

        x += other.x;
        y += other.y;
    }

    /*!Creates a new vector as the result of the subtraction of the
    scalar from the components of this vector
    @scalar the scalar to subtract from the components
    @return the result of the subtraction*/
    inline Vector2 operator -(float scalar) const {

        return Vector2(x - scalar, y - scalar);
    }

    /*!Subtracts the given scalar from the components of this vector
    @scalar the scalar to subtract from the components*/
    inline void operator -=(float scalar) {

        x -= scalar;
        y -= scalar;
    }

    /*!Creates a new vector as the result of the subtraction of the
    given vector from this vector
    @other the vector to subtract from this
    @return the result of the subtraction*/
    inline Vector2 operator -(const Vector2& other) const {

        return Vector2(x - other.x, y - other.y);
    }

    /*!Subtracts the given vector from this vector
    @other the vector to subtract from this*/
    inline void operator -=(const Vector2& other) {

        x -= other.x;
        y -= other.y;
    }

    /*!Creates a new vector as the result of the multiplication of the
    components of this vector by the given scalar
    @scalar the scalar to multiply the components by
    @return the result of the multiplication*/
    inline Vector2 operator *(float scalar) const {

        return Vector2(x * scalar, y * scalar);
    }

    /*!Multiplies the components of this vector by the given scalar
    @scalar the scalar to multiply the components by*/
    inline void operator *=(float scalar) {

        x *= scalar;
        y *= scalar;
    }

    /*!Creates a new vector as the result of the division of the
    components of this vector by the given scalar
    @scalar the scalar to divide the components by
    @return the result of the division*/
    inline Vector2 operator /(float scalar) const {

        return Vector2(x / scalar, y / scalar);
    }

    /*!Divides the components of this vector by the given scalar
    @scalar the scalar to divide the components by*/
    inline void operator /=(float scalar) {

        x /= scalar;
        y /= scalar;
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!@return a copy of this vector*/
    inline Vector2 xy() {

        return Vector2(x, y);
    }

    /*!@return a new 2d vector with the x and y components reversed*/
    inline Vector2 yx() {

        return Vector2(y, x);
    }

    /*!@return a copy of this vector*/
    inline Vector2 clone() {

        return Vector2(x, y);
    }
};

//Vector3 TODO:
class Vector3 {
public:

    //VARIABLES
    //position co-ordinates access components
    float x;
    float y;
    float z;

    //colour access components
    float& r;
    float& g;
    float& b;

    //measurement access components
    float& width;
    float& height;
    float& depth;

    //CONSTRUCTORS
    /*!Creates a new three dimensional vector with the given values
    @aX the x component of the vector
    @aY the y component of the vector
    @aZ the z component of the vector*/
    inline Vector3(float aX, float aY, float aZ) :
        x(aX),
        y(aY),
        z(aZ),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /*!Creates a new three dimensional vector by copying the values from
    the given 2d vector and sets the z component to 0
    @v2 the 2d vector to copy from*/
    inline Vector3(const Vector2& v2) :
        x(v2.x),
        y(v2.y),
        z(0),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /*!Creates a new three dimensional vector by the copying the values from
    the given 3d vector
    @v3 the 3d vector to copy from*/
    inline Vector3(const Vector3& v3) :
        x(v3.x),
        y(v3.y),
        z(v3.z),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    //DESTRUCTOR
    /*!Destroys this vector*/
    inline ~Vector3() {
    }

};

} } //util //vec

#endif