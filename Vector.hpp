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
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /*!@return a new 2d vector with the x and y components reversed*/
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    /*!@return a copy of this vector*/
    inline Vector2 clone() const {

        return Vector2(x, y);
    }

    /*!@return the zero two dimensional vector*/
    inline static Vector2 zero() {

        return Vector2(0, 0);
    }

    /*!@return the x axis vector*/
    inline static Vector2 xAxis() {

        return Vector2(1, 0);
    }

    /*!@return the y axis vector*/
    inline static Vector2 yAxis() {

        return Vector2(0, 1);
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

    /*!Creates a new three dimensional vector by copying the x and y components
    from the given 2d vector and the z component from the given value
    @v2 the 2d vector to copy from
    @aZ the z value of the vector*/
    inline Vector3(const Vector2& v2, float aZ) :
        x(v2.x),
        y(v2.y),
        z(aZ),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /*!Creates a new three dimensional from the given x value and copying
    the y and z components from the given 2d vector
    @aX the x value of the vector
    @v2 the 2d vector to copy from*/
    inline Vector3(float aX, const Vector2& v2) :
        x(aX),
        y(v2.x),
        z(v2.y),
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

    //OPERATORS
    /*!Sets the values of this vector by copying the values from the
    other given vector
    @other the vector to copy from*/
    inline Vector3& operator =(const Vector3& other) {

        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }

    /*!@return if this vector and the other given vector are equal*/
    inline bool operator ==(const Vector3& other) const {

        return x == other.x && y == other.y && z == other.z;
    }

    /*!@return if this vector and the other given vector are not equal*/
    inline bool operator !=(const Vector3& other) const {

        return !((*this) == other);
    }

    /*!Gets the component of the vector at the given index
    @index the component to get
    @return the value of the component*/
    inline float& operator [](unsigned index) {

        //check that the index is within bounds
        if (index > 2) {

            util::ex::IndexOutOfBoundsException("index is greater than 2.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            default: {

                return z;
            }
        }
    }

    /*!Gets the component of the vector at the given index
    @index the component to get
    @return the value of the component*/
    inline const float& operator [](unsigned index) const {

        //check that the index is within bounds
        if (index > 2) {

            util::ex::IndexOutOfBoundsException("index is greater than 2.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            default: {

                return z;
            }
        }
    }

    /*!@return a copy of the vector which has been negated*/
    inline Vector3 operator -() const {

        return Vector3(-x, -y, -z);
    }

    /*!Creates a new vector as the result of the addition of the components
    of this vector with the given scalar
    @scalar the scalar to add
    @return the result of the addition*/
    inline Vector3 operator +(float scalar) const {

        return Vector3(x + scalar, y + scalar, z + scalar);
    }

    /*!Adds the given scalar to the components of this vector
    @scalar the scalar to add*/
    inline void operator +=(float scalar) {

        x += scalar;
        y += scalar;
        z += scalar;
    }

    /*!Creates a new vector as the result of the addition of this vector
    and the other given vector
    @other the vector to add to this
    @return the result of the addition*/
    inline Vector3 operator +(const Vector3& other) const {

        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    /*!Adds the given vector to this vector
    @other the vector to add to this*/
    inline void operator +=(const Vector3& other) {

        x += other.x;
        y += other.y;
        z += other.z;
    }

    /*!Creates a new vector as the result of the subtraction of the
    scalar from the components of this vector
    @scalar the scalar to subtract from the components
    @return the result of the subtraction*/
    inline Vector3 operator -(float scalar) const {

        return Vector3(x - scalar, y - scalar, z - scalar);
    }

    /*!Subtracts the given scalar from the components of this vector
    @scalar the scalar to subtract from the components*/
    inline void operator -=(float scalar) {

        x -= scalar;
        y -= scalar;
        z -= scalar;
    }

    /*!Creates a new vector as the result of the subtraction of the
    given vector from this vector
    @other the vector to subtract from this
    @return the result of the subtraction*/
    inline Vector3 operator -(const Vector3& other) const {

        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    /*!Subtracts the given vector from this vector
    @other the vector to subtract from this*/
    inline void operator -=(const Vector3& other) {

        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    /*!Creates a new vector as the result of the multiplication of the
    components of this vector by the given scalar
    @scalar the scalar to multiply the components by
    @return the result of the multiplication*/
    inline Vector3 operator *(float scalar) const {

        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    /*!Multiplies the components of this vector by the given scalar
    @scalar the scalar to multiply the components by*/
    inline void operator *=(float scalar) {

        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    /*!Creates a new vector as the result of the division of the
    components of this vector by the given scalar
    @scalar the scalar to divide the components by
    @return the result of the division*/
    inline Vector3 operator /(float scalar) const {

        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    /*!Divides the components of this vector by the given scalar
    @scalar the scalar to divide the components by*/
    inline void operator /=(float scalar) {

        x /= scalar;
        y /= scalar;
        z /= scalar;
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!@returns a new 2d vector of the x and y components of this vector*/
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /*!@returns a new 2d vector of the y and x components of this vector*/
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    /*!@returns a new 2d vector of the y and z components of this vector*/
    inline Vector2 yz() const {

        return Vector2(y, z);
    }

    /*!@returns a new 2d vector of the z and y components of this vector*/
    inline Vector2 zy() const {

        return Vector2(z, y);
    }

    /*!@returns a new 2d vector of the x and z components of this vector*/
    inline Vector2 xz() const {

        return Vector2(x, z);
    }

    /*!@returns a new 2d vector of the x and z components of this vector*/
    inline Vector2 zx() const {

        return Vector2(z, x);
    }

    /*!@returns a copy of this vector*/
    inline Vector3 xyz() const {

        return Vector3(x, y, z);
    }

    /*!@returns new 3d vector from the x, z, and y components*/
    inline Vector3 xzy() const {

        return Vector3(x, z, y);
    }

    /*!@returns new 3d vector from the y, x, and z components*/
    inline Vector3 yxz() const {

        return Vector3(y, x, z);
    }

    /*!@returns new 3d vector from the y, z, and x components*/
    inline Vector3 yzx() const {

        return Vector3(y, z, x);
    }

    /*!@returns new 3d vector from the z, x, and y components*/
    inline Vector3 zxy() const {

        return Vector3(z, x, y);
    }

    /*!@returns new 3d vector from the z, y, and x components*/
    inline Vector3 zyx() const {

        return Vector3(z, y, x);
    }

    /*!@returns a copy of this vector*/
    inline Vector3 clone() const {

        return Vector3(x, y, z);
    }

    /*!@return the zero three dimensional vector*/
    inline static Vector3 zero() {

        return Vector3(0, 0, 0);
    }

    /*!@return the x axis vector*/
    inline static Vector3 xAxis() {

        return Vector3(1, 0, 0);
    }

    /*!@return the y axis vector*/
    inline static Vector3 yAxis() {

        return Vector3(0, 1, 0);
    }

    /*!@return the z axis vector*/
    inline static Vector3 zAxis() {

        return Vector3(0, 0, 1);
    }
};

} } //util //vec

#endif