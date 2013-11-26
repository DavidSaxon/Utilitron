#ifndef UTILITRON_VECTOR_VECTOR2_H_
#   define UTILITRON_VECTOR_VECTOR2_H_

#include <iostream>
#include <cmath>

#include <vector/Vector.hpp>

namespace util { namespace vec {

/*****************************\
| 2 dimensional vector class. |
|                             |
| @author David Saxon         |
\*****************************/
class Vector2 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @vector the vector to print
    @return the changed output stream*/
    friend std::ostream& operator <<(std::ostream& output,
        const Vector2& vector);

public:

    //CONSTRUCTORS
    /*!Creates a new zero 2D vector*/
    Vector2() :
        mX(0),
        mY(0) {
    }

    /*!Creates a new 2d vector
    @x the x value of the new vector
    @y the y value of the new vector*/
    Vector2(float x, float y) :
        mX(x),
        mY(y) {
    }

    /*!Creates a new vector by copying the other 2d vector
    @other the 2d vector to copy from*/
    Vector2(const Vector2& other) :
        mX(other.mX),
        mY(other.mY) {
    }

    //DESTRUCTOR
    /*!Destroys this vector*/
    ~Vector2() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @other the other vector to copy from*/
    Vector2& operator =(const Vector2& other);

    /*!Checks if this vector and the other vector are equal
    @other the other vector to compare with
    @return if the vectors are equal*/
    bool operator ==(const Vector2& other) const;

    /*!Checks if this vector and the vector are not equal
    @other the other vector to compare with
    @return if the vectors are not equal*/
    bool operator !=(const Vector2& other) const;

    /*!Gets the value at the specified index
    @index the index to get
    @return the value at the index*/
    float& operator [](unsigned index);

    /*!Gets the value at the specified index
    @index the index
    @return the value*/
    const float& operator [](unsigned index) const;

    /*!@return the vector with all elements negated*/
    Vector2 operator -() const;

    /*!Creates a new vector from the addition of this and the scalar
    @scalar the scalar to add with
    @return the result of the addition*/
    Vector2 operator +(float scalar) const;

    /*!Adds the value of the scalar to the vector
    @scalar the scalar to add with*/
    void operator +=(float scalar);

    /*!Creates a new vector from the addition of this and the other vector
    @other the other vector to add with
    @return the result of the addition*/
    void operator +(const Vector2& other) const;

    /*!Adds the value of the other vector to this vector
    @other the other vector to add to this*/
    void operator +=(const Vector2& other);

    /*!Creates a new vector from the subtraction of the scalar from this vector
    @scalar the scalar to subtract with
    @return the result of the subtraction*/
    Vector2 operator -(float scalar) const;

    /*!Subtracts the value of the scalar from this vector
    @scalar the scalar to subtract with*/
    void operator -=(float scalar);

    /*!Creates a new vector from the subtraction of the other vector from
    this vector
    @other the other vector to subtract with
    @return the result of the subtraction*/
    void operator -(const Vector2& other) const;

    /*!Subtracts the value of the other vector from this vector
    @other the other vector to subtract with*/
    void operator -=(const Vector2& other);

    /*!Creates a new vector from the multiplication of this vector and the
    given scalar
    @scalar the scalar to multiply with
    @return the result of the multiplication*/
    Vector2 operator *(float scalar) const;

    /*!Multiplies this vector by the given scalar
    @scalar the scalar to multiply with*/
    void operator *=(float scalar);

    /*!Creates a new vector from the division of this vector by the given scalar
    @scalar the scalar to divide with
    @return the result of the division*/
    Vector2 operator /(float scalar) const;

    /*!Divides this vector by the given scalar
    @scalar the scalar to divide with*/
    void operator /=(float scalar);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 2d zero vector*/
    static Vector2 zero();

    /*!@return the 2d x axis vector*/
    static Vector2 xAxis();

    /*!@return the 2d y axis vector*/
    static Vector2 yAxis();

    /*!Resets the vector to the zero vector*/
    void clear();

    /*!Inverses the vector*/
    void inverse();

    /*!@return the vector inversed*/
    Vector2 getInverse() const;

    /*!@return the magnitude of the vector*/
    float magnitude() const;

    /*!normalises the vector*/
    void normalise();

    /*!Computes the dot product between this vector and the other vector
    @other the other vector to compute with
    @return the result of the dot product*/
    float dotProduct(const Vector2& other) const;

    /*!Calculates the distance vector and the other vector
    @other the other vector to get the distance between
    @return the distance*/
    float distanceTo(const Vector2& other) const;

    /*!Calculates the angle between this vector and the other vector
    @other the other vector to calculate the angle between
    @return the angle*/
    float angleBetween(const Vector2& other) const;

    /*!@return the vector as an array*/
    float* toArray() const;

    /*!@return the vector represented as a string*/
    std::string toString() const;

    //GETTERS
    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!@return the red value*/
    float getR() const;

    /*!@return the green value*/
    float getG() const;

    /*!@return the width*/
    float getWidth() const;

    /*!@return the height*/
    float getHeight() const;

    //SETTERS
    /*!Sets the new values
    @x the new x value
    @y the new y value*/
    void set(float x, float y);

    /*!@x the new x value*/
    void setX(float x);

    /*!@y the new y value*/
    void setY(float y);

    /*!@r the new red value*/
    void setR(float r);

    /*!@g the new green value*/
    void setG(float g);

    /*!@width the new width*/
    void setWidth(float width);

    /*!@height the new height*/
    void setHeight(float height);

private:

    //VARIABLES
    //the two values of the vector
    float mX;
    float mY;
};

//INLINE
//OPERATORS
inline std::ostream& operator <<(std::ostream& output,
    const Vector2& vector) {

    //pass the vector to the output stream
    output << vector.toString();

    return output;
}

} } //util //vec

#endif