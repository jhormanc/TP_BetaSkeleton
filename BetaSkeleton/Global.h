/*!
* \file Global.h
* \brief Méthodes globales
*
*/

#pragma once

#include <cmath>
#include <algorithm>


/*!
*  \brief Interpolation linéaire
*
*  \param t : float
*  \param v1 : float
*  \param v2 : float
*  \return L'interpolation de v1 en v2 en fonction de t
*/
inline float lerp(float t, float v1, float v2)
{
	return (1.f - t) * v1 + t * v2;
}

/*!
*  \brief Clamp
*
*  \param val : float
*  \param low : float
*  \param high : float
*  \return Clamp val en fonction de low et high
*/
inline float clamp(float val, float low, float high)
{
	if (val < low) return low;
	else if (val > high) return high;
	else return val;
}

/*!
*  \brief Random
*
*  \param low : float
*  \param high : float
*  \return A radnom value between low et high
*/
inline float randf(float low, float high)
{
	return low + (float)rand() / (float)(RAND_MAX / (high - low));
}