/*!
* \file Svg.h
* \brief Header classe Svg
*
* Class Svg
*
*/


#pragma once

#include <string>
#include "Vector2d.h"
#include "ColorRGB.h"
#include <vector>
#include "SvgHelper.h"

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

	void addPoint(const Vector2d &point, const int radius, const ColorRGB &color);
	void addPoints(const std::vector<Vector2d> &points, const int radius, const ColorRGB &color);
	void addLine(const Vector2d &p1, const Vector2d &p2, const int width, const ColorRGB &color);
	void addLines(const std::vector<Vector2d> &points, const std::vector<Vector2d> &edges, const int radius, const ColorRGB &color);
};

