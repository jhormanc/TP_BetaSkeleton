#pragma once
#include "Vector2d.h"
#include "Heightmap.h"
#include <vector>

class Map
{

	bool IsInBetaSkeleton(const Vector2d &, const Vector2d &, const Vector2d &, float);
	bool IsInBetaSkeletonHeightmap(const Vector2d &, const Vector2d &, const Vector2d &, float, Heightmap &);
	bool IsInMoonBetaSkeleton(const Vector2d &, const Vector2d &, const Vector2d &, float);
	void AddWayFromPointList(const std::vector<Vector2d> &);
public:
	std::vector<Vector2d> towns;
	std::vector<Vector2d> waysPoints;
	std::vector<Vector2d> waysEdges;

	std::vector<Vector2d> betaSkeletonLunePoints;

	float xMax, yMax, xMin, yMin;

	Map(std::vector<Vector2d>, float, float, float, float);

	static Map GenRandomTowns(float, float, float, float, int);

	void CalcBetaSkeleton(const float);
	void CalcBetaSkeletonWithMoon(const float, const float, const float, const float, const float);
	void CalcBetaSkeletonHeightmap(const float, const float, const float, Heightmap &);
};

