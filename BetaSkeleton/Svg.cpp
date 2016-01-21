/*!
* \file Svg.cpp
* \brief Source classe Svg
*
* Class Svg
*
*/

#include "Svg.h"


Svg::Svg(const std::string &filename, float w, const float h) : file_name(filename), width(w), height(h)
{
}

std::string Svg::toString() const
{
	std::stringstream ss;
	ss << "<?xml " << SvgHelper::attribute("version", "1.0") << SvgHelper::attribute("standalone", "no")
		<< "?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "
		<< "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg "
		<< SvgHelper::attribute("width", width, "px")
		<< SvgHelper::attribute("height", height, "px")
		<< SvgHelper::attribute("xmlns", "http://www.w3.org/2000/svg")
		<< SvgHelper::attribute("xmlns:xlink", "http://www.w3.org/1999/xlink")
		<< SvgHelper::attribute("version", "1.1") << ">\n" << body << SvgHelper::elemEnd("svg");
	return ss.str();
}

bool Svg::save() const
{
	std::ofstream ofs(file_name.c_str());
	if (!ofs.good())
		return false;

	ofs << toString();
	ofs.close();
	return true;
}

void Svg::addPoint(const Vector2d &point, const int radius, const ColorRGB &color)
{
	std::stringstream ss;

	ss << SvgHelper::elemStart("circle");
	ss << SvgHelper::attribute("cx", point.x) << SvgHelper::attribute("cy", point.y) << SvgHelper::attribute("r", radius) << SvgHelper::attribute("fill", color.toString()) << SvgHelper::emptyElemEnd();

	body += ss.str();
}


void Svg::addPoints(const std::vector<Vector2d> &points, const int radius, const ColorRGB &color)
{
	for (int i = 0; i < points.size(); i++)
	{
		addPoint(points[i], radius, color);
	}
}

void Svg::addLine(const Vector2d &p1, const Vector2d &p2, const int width, const ColorRGB &color)
{
	std::stringstream ss;
	ss << SvgHelper::elemStart("line") << SvgHelper::attribute("x1", p1.x)
		<< SvgHelper::attribute("y1", p1.y)
		<< SvgHelper::attribute("x2", p2.x)
		<< SvgHelper::attribute("y2", p2.y)
		<< SvgHelper::attribute("stroke-width", width) << SvgHelper::attribute("stroke", color.toString()) << SvgHelper::emptyElemEnd();

	body += ss.str();
}

void Svg::addLines(const std::vector<Vector2d> &points, const std::vector<Vector2d> &edges, const int width, const ColorRGB &color)
{
	for (int i = 0; i < edges.size(); i++)
	{
		addLine(points[(int)edges[i].x], points[(int)edges[i].y], width, color);
	}
}

void Svg::addCost(const std::vector<Vector2d> &points, const std::vector<Vector2d> &edges, const std::vector<float> &costs, const ColorRGB &color)
{
	for (int i = 0; i < edges.size(); i++)
	{
		Vector2d p1 = points[(int)edges[i].x];
		Vector2d p2 = points[(int)edges[i].y];
		float x = (p2.x + p1.x) * 0.5f;
		float y = (p2.y + p1.y) * 0.5f;
		addText(std::to_string((int)costs[i]), x, y, color);
	}
}

void Svg::addImg(const std::string filename, const int width, const int height)
{
	std::stringstream ss;
	ss << SvgHelper::elemStart("image")
		<< SvgHelper::attribute("xlink:href", filename)
		<< SvgHelper::attribute("x", 0)
		<< SvgHelper::attribute("y", 0)
		<< SvgHelper::attribute("height", height)
		<< SvgHelper::attribute("width", width)
		<< SvgHelper::emptyElemEnd();

	body += ss.str();
}

void Svg::addText(const std::string &text, float x, const float y, const ColorRGB &color)
{
	std::stringstream ss;
	ss << "<text "
		<< SvgHelper::attribute("x", x)
		<< SvgHelper::attribute("y", y)
		<< SvgHelper::attribute("fill", color.toString())
		<< ">"
		<< text.c_str()
		<< "</text>";

	body += ss.str();
}