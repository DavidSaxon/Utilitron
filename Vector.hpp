#ifndef UTILITRON_VECTOR_VECTOR_H_
#   define UTILITRON_VECTOR_VECTOR_H_

#include <cmath>
#include <iostream>
#include <sstream>

#include "exceptions/ArrayException.hpp"

namespace util {

/****************************************************************\
| Vectors represented as classes with functions for vector math. |
\****************************************************************/
namespace vec {

/**********************************************************************\
| A two dimensional vector class that provides component access, basic |
| operators and static constructor functions.                          |
|                                                                      |
| @author David Saxon                                                  |
\**********************************************************************/
class Vector2 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @v the vector to print
    @return the changed output stream*/
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector2& v) {

        output << v.toString();

        return output;
    }

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

    /*!@return the vector in string format*/
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[ " << x << ", " << y << "]";

        return ss.str();
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

/************************************************************************\
| A three dimensional vector class that provides component access, basic |
| operators and static constructor functions.                            |
|                                                                        |
| @author David Saxon                                                    |
\************************************************************************/
class Vector3 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @v the vector to print
    @return the changed output stream*/
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector3& v) {

        output << v.toString();

        return output;
    }

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

    /*!@return the vector in string format*/
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[ " << x << ", " << y << ", " << z << "]";

        return ss.str();
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

/***********************************************************************\
| A four dimensional vector class that provides component access, basic |
| operators and static constructor functions.                           |
|                                                                       |
| @author David Saxon                                                   |
\***********************************************************************/
class Vector4 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @v the vector to print
    @return the changed output stream*/
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector4& v) {

        output << v.toString();

        return output;
    }

public:

    //VARIABLES
    //position co-ordinates access components
    float x;
    float y;
    float z;
    float w;

    //colour access components
    float& r;
    float& g;
    float& b;
    float& a;

    //measurement access components
    float& width;
    float& height;
    float& depth;
    float& fourth;

    //CONSTRUCTORS
    /*!Creates a new four dimensional vector with the given values
    @aX the x value of the vector
    @aY the y value of the vector
    @aZ the z value of the vector
    @aW the w value of the vector*/
    inline Vector4(float aX, float aY, float aZ, float aW) :
        x(aX),
        y(aY),
        z(aZ),
        w(aW),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by the copying the values from
    the given 4d vector
    @v4 the 4d vector to copy from*/
    inline Vector4(const Vector4& v4) :
        x(v4.x),
        y(v4.y),
        z(v4.z),
        w(v4.w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the x and y components
    from the given 2d vector and sets the z and w components from the
    given values
    @v2 the 2d vector to copy from
    @aZ the z value of the vector
    @aW the w value of the vector*/
    inline Vector4(const Vector2& v2, float aZ, float aW) :
        x(v2.x),
        y(v2.y),
        z(aZ),
        w(aW),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the y and z components
    from the given 2d vector and sets the x and w components from the
    given values
    @aX the x value of the vector
    @v2 the 2d vector to copy from
    @aW the w value of the vector*/
    inline Vector4(float aX, const Vector2& v2, float aW) :
        x(aX),
        y(v2.x),
        z(v2.y),
        w(aW),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the z and w components
    from the given 2d vector and sets the x and y components from the
    given values
    @aX the x value of the vector
    @aY the y value of the vector
    @v2 the 2d vector to copy from*/
    inline Vector4(float aX, float aY, const Vector2& v2) :
        x(aX),
        y(aY),
        z(v2.x),
        w(v2.y),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the x and y components
    from the first 2d vector and the z and w components from the second
    2d vector
    @firstV2 the first 2d vector
    @secondV2 the second 2d vector*/
    inline Vector4(const Vector2& firstV2, const Vector2& secondV2) :
        x(firstV2.x),
        y(firstV2.y),
        z(secondV2.x),
        w(secondV2.y),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the x, y, and z
    components from the given 3d vector and sets the w component
    from the given value
    @v3 the 3d vector to copy from
    @aW the w value of the vector*/
    inline Vector4(const Vector3& v3, float aW) :
        x(v3.x),
        y(v3.y),
        z(v3.z),
        w(aW),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    /*!Creates a new four dimensional vector by setting the y, x, and w
    components from the given 3d vector and sets the x component
    from the given value
    @aX the x value of the vector
    @v3 the 3d vector to copy from*/
    inline Vector4(float aX, const Vector3& v3) :
        x(aX),
        y(v3.x),
        z(v3.y),
        w(v3.z),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z),
        fourth(w) {
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!@returns a new 2d vector of the x and y components of this vector*/
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /*!@returns a new 2d vector of the x and z components of this vector*/
    inline Vector2 xz() const {

        return Vector2(x, z);
    }

    /*!@returns a new 2d vector of the x and w components of this vector*/
    inline Vector2 xw() const {

        return Vector2(x, w);
    }

    /*!@returns a new 2d vector of the y and x components of this vector*/
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    /*!@returns a new 2d vector of the y and z components of this vector*/
    inline Vector2 yz() const {

        return Vector2(y, z);
    }

    /*!@returns a new 2d vector of the y and w components of this vector*/
    inline Vector2 yw() const {

        return Vector2(y, w);
    }

    /*!@returns a new 2d vector of the z and x components of this vector*/
    inline Vector2 zx() const {

        return Vector2(z, x);
    }

    /*!@returns a new 2d vector of the z and y components of this vector*/
    inline Vector2 zy() const {

        return Vector2(z, y);
    }

    /*!@returns a new 2d vector of the z and w components of this vector*/
    inline Vector2 zw() const {

        return Vector2(z, w);
    }

    /*!@returns a new 3d vector of the x, y, and z components of this vector*/
    inline Vector3 xyz() const {

        return Vector3(x, y, z);
    }

    /*!@returns a new 3d vector of the x, y, and w components of this vector*/
    inline Vector3 xyw() const {

        return Vector3(x, y, w);
    }

    /*!@returns a new 3d vector of the x, z, and y components of this vector*/
    inline Vector3 xzy() const {

        return Vector3(x, z, y);
    }

    /*!@returns a new 3d vector of the x, z, and w components of this vector*/
    inline Vector3 xzw() const {

        return Vector3(x, z, w);
    }

    /*!@returns a new 3d vector of the x, w, and y components of this vector*/
    inline Vector3 xwy() const {

        return Vector3(x, w, y);
    }

    /*!@returns a new 3d vector of the x, w, and y components of this vector*/
    inline Vector3 xwz() const {

        return Vector3(x, w, z);
    }

    /*!@returns a new 3d vector of the y, x, and z components of this vector*/
    inline Vector3 yxz() const {

        return Vector3(y, x, z);
    }

    /*!@returns a new 3d vector of the y, x, and w components of this vector*/
    inline Vector3 yxw() const {

        return Vector3(y, x, w);
    }

    /*!@returns a new 3d vector of the y, z, and x components of this vector*/
    inline Vector3 yzx() const {

        return Vector3(y, z, x);
    }

    /*!@returns a new 3d vector of the y, z, and w components of this vector*/
    inline Vector3 yzw() const {

        return Vector3(y, z, w);
    }

    /*!@returns a new 3d vector of the y, w, and x components of this vector*/
    inline Vector3 ywx() const {

        return Vector3(y, w, x);
    }

    /*!@returns a new 3d vector of the y, w, and z components of this vector*/
    inline Vector3 ywz() const {

        return Vector3(y, w, z);
    }

    /*!@returns a new 3d vector of the z, x, and y components of this vector*/
    inline Vector3 zxy() const {

        return Vector3(z, x, y);
    }

    /*!@returns a new 3d vector of the z, x, and w components of this vector*/
    inline Vector3 zxw() const {

        return Vector3(z, x, w);
    }

    /*!@returns a new 3d vector of the z, y, and x components of this vector*/
    inline Vector3 zyx() const {

        return Vector3(z, y, x);
    }

    /*!@returns a new 3d vector of the z, y, and w components of this vector*/
    inline Vector3 zyw() const {

        return Vector3(z, y, w);
    }

    /*!@returns a new 3d vector of the z, w, and x components of this vector*/
    inline Vector3 zwx() const {

        return Vector3(z, w, x);
    }

    /*!@returns a new 3d vector of the z, w, and y components of this vector*/
    inline Vector3 zwy() const {

        return Vector3(z, w, y);
    }

    /*!@returns a new 3d vector of the w, x, and y components of this vector*/
    inline Vector3 wxy() const {

        return Vector3(w, x, y);
    }

    /*!@returns a new 3d vector of the w, x, and z components of this vector*/
    inline Vector3 wxz() const {

        return Vector3(w, x, z);
    }

    /*!@returns a new 3d vector of the w, y, and x components of this vector*/
    inline Vector3 wyx() const {

        return Vector3(w, y, x);
    }

    /*!@returns a new 3d vector of the w, y, and z components of this vector*/
    inline Vector3 wyz() const {

        return Vector3(w, y, z);
    }

    /*!@returns a new 3d vector of the w, z, and x components of this vector*/
    inline Vector3 wzx() const {

        return Vector3(w, z, x);
    }

    /*!@returns a new 3d vector of the w, z, and y components of this vector*/
    inline Vector3 wzy() const {

        return Vector3(w, z, y);
    }

    /*!@returns a clone of this vector*/
    inline Vector4 xyzw() const {

        return Vector4(x, y, z, w);
    }

    /*!@returns a 4d vector with the x, y, w, and z components*/
    inline Vector4 xywz() const {

        return Vector4(x, y, w, z);
    }

    /*!@returns a 4d vector with the x, z, y, and w components*/
    inline Vector4 xzyw() const {

        return Vector4(x, z, y, w);
    }

    /*!@returns a 4d vector with the x, w, y, and z components*/
    inline Vector4 xwyz() const {

        return Vector4(x, w, y, z);
    }

    /*!@returns a 4d vector with the y, x, z, and w components*/
    inline Vector4 yxzw() const {

        return Vector4(y, x, z, w);
    }

    /*!@returns a 4d vector with the y, x, w, and z components*/
    inline Vector4 yxwz() const {

        return Vector4(y, x, w, z);
    }

    /*!@returns a 4d vector with the y, z, x, and w components*/
    inline Vector4 yzxw() const {

        return Vector4(y, z, x, w);
    }

    /*!@returns a 4d vector with the y, z, x, and w components*/
    inline Vector4 yzwx() const {

        return Vector4(y, z, w, x);
    }

    /*!@returns a 4d vector with the y, w, x, and z components*/
    inline Vector4 ywxz() const {

        return Vector4(y, w, x, z);
    }

    /*!@returns a 4d vector with the y, w, z, and x components*/
    inline Vector4 ywzx() const {

        return Vector4(y, w, z, x);
    }

    /*!@returns a 4d vector with the z, x, y, and w components*/
    inline Vector4 zxyw() const {

        return Vector4(z, x, y, w);
    }

    /*!@returns a 4d vector with the z, x, w, and y components*/
    inline Vector4 zxwy() const {

        return Vector4(z, x, y, w);
    }

    /*!@returns a 4d vector with the z, y, x, and w components*/
    inline Vector4 zyxw() const {

        return Vector4(z, y, x, w);
    }

    /*!@returns a 4d vector with the z, y, w, and x components*/
    inline Vector4 zywx() const {

        return Vector4(z, y, w, x);
    }

    /*!@returns a 4d vector with the z, w, x, and y components*/
    inline Vector4 zwxy() const {

        return Vector4(z, y, w, x);
    }

    /*!@returns a 4d vector with the z, w, y, and x components*/
    inline Vector4 zwyx() const {

        return Vector4(z, w, y, x);
    }

    /*!@returns a clone of this vector*/
    inline Vector4 clone() const {

        return Vector4(x, y, z, w);
    }

    /*!@return the vector in string format*/
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[ " << x << ", " << y << ", " << z <<  ", " << w << "]";

        return ss.str();
    }

    /*!@return the zero three dimensional vector*/
    inline static Vector4 zero() {

        return Vector4(0, 0, 0, 0);
    }

    /*!@return the x axis vector*/
    inline static Vector4 xAxis() {

        return Vector4(1, 0, 0, 0);
    }

    /*!@return the y axis vector*/
    inline static Vector4 yAxis() {

        return Vector4(0, 1, 0, 0);
    }

    /*!@return the z axis vector*/
    inline static Vector4 zAxis() {

        return Vector4(0, 0, 1, 0);
    }

    /*!@return the w axis vector*/
    inline static Vector4 wAxis() {

        return Vector4(0, 0, 0, 1);
    }
};

//VECTOR MATH FUNCTIONS
/*!Computes the magnitude of the given vector
@v the vector to compute the magnitude
@return the magnitude*/
inline float magnitude(const Vector2& v) {

    return sqrt((v.x * v.x) + (v.y * v.y));
}

/*!Computes the magnitude of the given vector
@v the vector to compute the magnitude
@return the magnitude*/
inline float magnitude(const Vector3& v) {

    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/*!Computes the magnitude of the given vector
@v the vector to compute the magnitude
@return the magnitude*/
inline float magnitude(const Vector4& v) {

    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w + v.w));
}

/*!Computes a normalised version of the given vector
@v the vector to normalise
@return the normalised vector*/
inline Vector2 normalise(const Vector2& v) {

    float mag = magnitude(v);

    return Vector2(v.x / mag, v.y / mag);
}

/*!Computes a normalised version of the given vector
@v the vector to normalise
@return the normalised vector*/
inline Vector3 normalise(const Vector3& v) {

    float mag = magnitude(v);

    return Vector3(v.x / mag, v.y / mag, v.z / mag);
}

/*!Computes a normalised version of the given vector
@v the vector to normalise
@return the normalised vector*/
inline Vector4 normalise(const Vector4& v) {

    float mag = magnitude(v);

    return Vector4(v.x / mag, v.y / mag, v.z / mag, v.w / mag);
}

/*!Computes the dot product of the two given vectors
@a the first vector
@b the second vector
@return the result of dot product*/
inline float dot(const Vector2& a, const Vector2& b) {

    return (a.x * b.x) + (a.y * b.y);
}

/*!Computes the dot product of the two given vectors
@a the first vector
@b the second vector
@return the result of dot product*/
inline float dot(const Vector3& a, const Vector3& b) {

    return (a.x * b.x) + (a.y * b.y) * (a.z * b.z);
}

/*!Computes the dot product of the two given vectors
@a the first vector
@b the second vector
@return the result of dot product*/
inline float dot(const Vector4& a, const Vector4& b) {

    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

/*!Computes the cross product of the two given vectors
@a the first vector
@b the second vector
@return the result of cross product*/
inline Vector3 cross(const Vector3& a, const Vector3& b) {

    //the cross product values
    float cx = (a.y * b.z) - (a.z * b.y);
    float cy = (a.x * b.z) - (a.z * b.x);
    float cz = (a.x * b.y) - (a.y * b.x);

    return Vector3(cx, cy, cz);
}

/*!Calculates the distance between the two vectors
@a the first vector
@b the second vector
@return the distance between the vectors*/
inline float distance(const Vector2& a, const Vector2& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f));
}

/*!@Calculates the distance between the two vectors
@a the first vector
@b the second vector
@return the distance between the vectors*/
inline float distance(const Vector3& a, const Vector3& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f) +
        pow(a.z - b.z, 2.0f));
}

/*!@Calculates the distance between the two vectors
@a the first vector
@b the second vector
@return the distance between the vectors*/
inline float distance(const Vector4& a, const Vector4& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f) +
        pow(a.z - b.z, 2.0f) + pow(a.w - b.w, 2.0f));
}

/*!@return the angle between the two vectors
@a the first vector
@b the second vector
@return the angle between the vectors*/
inline float angleBetween(const Vector2& a, const Vector2& b) {

    return (-1.0f * atan2(a.y - b.y, a.x - b.x));
}

} } //util //vec

#endif