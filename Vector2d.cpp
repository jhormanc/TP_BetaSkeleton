/*!
* \file Vector2d.cpp
* \brief Source classe Vector2d
*
* Class Vector2d
*
*/

#include "Vector2d.h"

Vector2d::Vector2d() : x(0.f), y(0.f) 
{
}

Vector2d::Vector2d(float _x, float _y) : x(_x), y(_y)
{
}

Vector2d Vector2d::Random(float minX, float maxX, float minY, float maxY)
{
	return Vector2d(randf(minX, maxX), randf(minY, maxY));
}