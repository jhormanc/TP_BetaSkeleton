/*!
* \file ColorRGB.h
* \brief Header struct ColorRGB
*
* Struct ColorRGB
*
*/

#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


/*!
* \struc ColorRGB
* \brief Struc color.
*/
struct ColorRGB
{
	float red, green, blue;
	bool transparent;

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe ColorRGB
	*
	*/
	ColorRGB()
	{
		transparent = true;
	}

	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe ColorRGB
	*
	*  \param x : Couleur rouge
	*  \param y : Couleur vert
	*  \param z : Couleur bleu
	*/
	ColorRGB(const float x, const float y, const float z)
	{
		red = x;
		green = y;
		blue = z;
		transparent = false;
	}

	/*!
	*  \brief Conversion en string
	*
	*  Methode qui convertit ColorRGB en string
	*
	*  \return ColorRGB en string
	*/
	std::string toString() const
	{
		std::stringstream ss;
		if (transparent)
			ss << "transparent";
		else
			ss << "rgb(" << red << "," << green << "," << blue << ")";
		return ss.str();
	}
};