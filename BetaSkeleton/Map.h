#pragma once
#include "Vector2d.h"
#include <vector>

class Map
{

	bool IsInBetaSkeleton(const Vector2d &, const Vector2d &, const Vector2d &, float);
	void AddWayFromPointList(const std::vector<Vector2d> &);
public:
	std::vector<Vector2d> towns;
	std::vector<Vector2d> waysPoints;
	std::vector<Vector2d> waysEdges;
	float xMax, yMax, xMin, yMin;
	Map(std::vector<Vector2d>, float, float, float, float);
	static Map GenRandomTowns(float, float, float, float, int);
	void CalcBetaSkeleton(float);
};

