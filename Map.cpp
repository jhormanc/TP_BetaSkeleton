#include "Map.h"




Map::Map(std::vector<Vector2d> towns) : towns(towns)
{
}

Map Map::GenRandomTowns(float Xmin, float Xmax, float Ymin, float Ymax, int townCount)
{
	std::vector<Vector2d> towns;
	for (int i = 0; i < townCount; ++i)
	{
		towns.push_back(Vector2d::Random(Xmin, Xmax, Ymin, Ymax));
	}
}
