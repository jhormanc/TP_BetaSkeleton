/*!
* \file Svg.h
* \brief Header classe Svg
*
* Class Svg
*
*/


#pragma once

#include <string>
#include "Vector2d.h
#include <vector>

/*! \class Svg
* \brief Class Svg
*
*  La classe gere les export SVG
*/
class Svg
{
	std::string file_name;
	std::string body;
	
	float width;
	float height;

public:
	/*!
	*  \brief Constructor
	*
	*  Create a Svg
	*
	*  \param filename : Name of the file to generate
	*  \param w : Width
	*  \param h : Height
	*/
	Svg(const std::string &filename, float w, const float h);

	/*!
	*  \brief Convert to string
	*
	*/
	std::string toString() const;

	/*!
	*  \brief Save the file
	*
	*/
	bool save() const;
//
//	/*!
//	*  \brief Add the edges of a convex polygon
//	*
//	* Add the edges of a convex polygon 2d in the file
//	*
//	*  \param p : The convex polygon
//	*  \param HEIGHT : Height
//	*/
//	void addConvexEdge(const std::vector<Vector2d> &p, const int HEIGHT);
//
//	/*!
//	*  \brief Add the points of polygon 2d
//	*
//	*  Add the points of polygon 2d in the file
//	*
//	*  \param p : The polygon
//	*  \param HEIGHT : Height
//	*/
//	void addConvexPoint(const Polygone2d &p, const int HEIGHT);
//};

