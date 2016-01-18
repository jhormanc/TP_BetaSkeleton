#pragma once
#include "Vector2d.h"
#include <vector>

class Map
{
public:
	std::vector<Vector2d> towns;
	Map(std::vector<Vector2d>);
	static Map GenRandomTowns(float, float, float, float, int);
};

