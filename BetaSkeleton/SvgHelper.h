/*!
* \file SvgHelper.h
* \brief Header classe SvgHelper
*
* Class SvgHelper
*
*/

#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


/*! \class SvgHelper
* \brief Class SvgHelper
*
*  
*/
class SvgHelper
{
public:
	template <typename T>
	static std::string attribute(std::string const & attribute_name,
		T const & value, std::string const & unit = "")
	{
		std::stringstream ss;
		ss << attribute_name << "=\"" << value << unit << "\" ";
		return ss.str();
	}

	static std::string elemStart(std::string const & element_name)
	{
		return "\t<" + element_name + " ";
	}

	static std::string elemEnd(std::string const & element_name)
	{
		return "</" + element_name + ">\n";
	}

	static std::string emptyElemEnd()
	{
		return "/>\n";
	}

};