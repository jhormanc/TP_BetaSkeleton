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
//
//void Svg::addConvexEdge(const Convex2d &p, const int HEIGHT)
//{
//	body += p.toStringEdges(HEIGHT);
//}
//
//void Svg::addConvexPoint(const Polygone2d &p, const int HEIGHT)
//{
//	body += p.toStringPoint(HEIGHT);
//}