#pragma once
#include "Vector2d.h"
#include "Heightmap.h"
#include <vector>

class Map
{

	bool IsInBetaSkeleton(const Vector2d &, const Vector2d &, const Vector2d &, float);
	bool IsInMoonBetaSkeleton(const Vector2d &, const Vector2d &, const Vector2d &, float);
	bool IsInBetaSkeletonHeightmap(const Vector2d &, const Vector2d &, const Vector2d &, float, Heightmap &);

	void AddWayFromPointList(const std::vector<Vector2d> &);
public:
	std::vector<Vector2d> towns;
	std::vector<Vector2d> betaSkeletonLunePoints;
	std::vector<Vector2d> waysPoints;
	std::vector<Vector2d> waysEdges;

	float xMax, yMax, xMin, yMin;

	Map(std::vector<Vector2d>, float, float, float, float);

	static Map GenRandomTowns(float, float, float, float, int);
	static Map GenTowns1(float, float, float, float);

	void CalcBetaSkeleton(const float, const float, const float);
	void CalcBetaSkeletonWithMoon(float, const float, const float, const float, const float);
	void CalcBetaSkeletonHeightmap(const float, const float, const float, Heightmap &);
};

