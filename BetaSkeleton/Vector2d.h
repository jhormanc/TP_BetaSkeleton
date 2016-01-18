/*!
* \file Vector2d.h
* \brief Header classe Vector2d
*
* Class Vector2d
*
*/

#pragma once

#include <iostream> 

#include "Global.h"

using namespace std;

/*! \class Vector2d
* \brief Class Vector2d
*
*  La classe gere les vector 2d
*/
class Vector2d {

public:

	float x;
	float y;

	/*!
	*  \brief Constructor
	*
	*  Create a Vector2d
	*
	*/
	Vector2d();

	/*!
	*  \brief Constructor
	*
	*  Create a vector 2d from two coordinates
	*
	*  \param _x : X coordinate
	*  \param _y : Y coordinate
	*/
	Vector2d(float _x, float _y);

	/*!
	*  \brief Operator plus
	*
	*  Addition of a vector 2d
	*
	*  \param v : Vector 2d
	*/
	inline Vector2d operator+(const Vector2d& v) const {
		return Vector2d(x + v.x, y + v.y);
	}

	/*!
	*  \brief Operator minus
	*
	*  Subtraction of a vector 2d
	*
	*  \param v : Vector 2d
	*/
	inline Vector2d operator-(const Vector2d& v) const {
		return Vector2d(x - v.x, y - v.y);
	}

	/*!
	*  \brief Operator multiply
	*
	*  Multiply by a vector 2d
	*
	*  \param v : Vector 2d
	*/
	inline Vector2d operator*(const Vector2d& v) const {
		return Vector2d(x * v.x, y * v.y);
	}

	/*!
	*  \brief Operator Divide
	*
	*  Divide by a vector 2d
	*
	*  \param v : Vector 2d
	*/
	inline Vector2d operator/(const Vector2d& v) const {
		return Vector2d(x / v.x, y / v.y);
	}

	
	/*!
	*  \brief Operator equal
	*
	*  Check if the Vectors have the same values
	*
	*  \param v : Vector 2d
	*/
	inline bool operator==(const Vector2d& v) const {
		return(x == v.x && y == v.y);
	}

	/*Check which Vectors are closer or further from the
	origin.
	bool operator>(const Vector2d&) const;
	bool operator<(const Vector2d&) const;
	bool operator>=(const Vector2d&) const;
	bool operator<=(const Vector2d&) const;*/

	friend ostream& operator<<(ostream& os, const Vector2d& v)
	{
		os << "x = " << v.x << "//y = " << v.y << "\n";
		return os;
	}

	/*!
	*  \brief Operator -
	*
	*  Negate both the x and y values
	*/
	inline Vector2d operator-() const {
		return Vector2d(-x, -y);
	}

	/*!
	*  \brief Operator *
	*
	*  Apply scalar operations
	*
	*  \param scalar : float
	*/
	inline Vector2d operator*(const float& scalar) const {
		return Vector2d(x*scalar, y*scalar);
	}

	/*!
	*  \brief Operator /
	*
	*  Apply scalar operations
	*
	*  \param scalar : float
	*/
	inline Vector2d operator/(const float& scalar) const {
		float mult = 1.f / scalar;
		return operator*(mult);
	}

	//Product functions

	/*!
	*  \brief Dot product
	*
	*   Dot product
	*
	*  \param a : Vector 2d
	*  \param b : Vector 2d
	*  \return The dot product of a and b
	*/
	inline static float DotProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.x) + (a.y * b.y));
	}

	/*!
	*  \brief Cross product
	*
	*   Cross product
	*
	*  \param a : Vector 2d
	*  \param b : Vector 2d
	*  \return The Cross product of a and b
	*/
	inline static float CrossProduct(const Vector2d& a, const Vector2d& b) {
		return ((a.x * b.y) - (a.y * b.x));
	}

	/*!
	*  \brief Length squared
	*
	*  \return The Length squared
	*/
	inline float LengthSquared() const {
		return x*x + y*y;
	}

	/*!
	*  \brief Length
	*
	*  \return The square root of the length squared
	*/
	inline float Length() const {
		return sqrt(LengthSquared());
	}

	/*!
	*  \brief Normalize
	*
	*  \param v : Vector 2d
	*  \return The normalized v
	*/
	inline static Vector2d Normalize(Vector2d v)
	{
		return v/v.LengthSquared();
	}

	/*!
	*  \brief Random value
	*
	*  \param minX : float
	*  \param maxX : float
	*  \param minY : float
	*  \param maxY : float
	*  \return The a random vector2d from the input values
	*/
	static Vector2d Random(float minX, float maxX, float minY, float maxY);

	/*!
	*  \brief Rotate to 90 degrees in the Anti Clockwise order
	*
	*  \return The rotated vector 2d
	*/
	inline Vector2d rotate90AntiClockwise() const {
		return Vector2d(-y, x);
	}

	/*!
	*  \brief Rotate to 90 degrees in the Clockwise order
	*
	*  \return The rotated vector 2d
	*/
	inline Vector2d rotate90Clockwise() const {
		return Vector2d(y, -x);
	}

	inline const Vector2d & Min(Vector2d v)
	{
		x = std::min(x, v.x);
		y = std::min(y, v.y);
		return *this;
	}

	inline const Vector2d & Max(Vector2d v)
	{
		x = std::max(x, v.x);
		y = std::max(y, v.y);
		return *this;
	}
};