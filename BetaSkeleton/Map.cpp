#include "Map.h"




Map::Map(std::vector<Vector2d> towns, float xMin_, float yMin_, float xMax_, float yMax_) : towns(towns), waysEdges(std::vector<Vector2d>()), waysPoints(std::vector<Vector2d>()), xMin(xMin_), yMin(yMin_), xMax(xMax_), yMax(yMax_)
{
}

Map Map::GenRandomTowns(float xMin_, float yMin_, float xMax_, float yMax_, int townCount)
{
	std::vector<Vector2d> towns;
	for (int i = 0; i < townCount; ++i)
	{
		towns.push_back(Vector2d::Random(xMin_, xMax_, yMin_, yMax_));
	}
	return Map(towns, xMin_, yMin_, xMax_, yMax_);
}

// Marche avec Heighmap2.ppm
Map Map::GenTowns1(float xMin_, float yMin_, float xMax_, float yMax_) {
	std::vector<Vector2d> towns = {
		Vector2d(700,260),
		Vector2d(380,330),
		Vector2d(490,400),
		Vector2d(280,420),
		Vector2d(360,560),
		Vector2d(560,600),
		Vector2d(215,650),
		Vector2d(350,820),
		Vector2d(870,760),
		Vector2d(900,800)
	};

	return Map(towns, xMin_, yMin_, xMax_, yMax_);
}


void Map::AddWayFromPointList(const std::vector<Vector2d> & pointList)
{
	for (int i = 0; i < pointList.size(); ++i)
	{
		betaSkeletonLunePoints.push_back(pointList[i]);
	}
}

bool Map::IsInBetaSkeleton(const Vector2d & p, const Vector2d & a, const Vector2d & b, float gamma)
{
	return std::pow(Vector2d::Distance(a, p), gamma) + std::pow(Vector2d::Distance(b, p), gamma) < std::pow(Vector2d::Distance(a, b), gamma);
}

bool Map::IsInMoonBetaSkeleton(const Vector2d & p, const Vector2d & a, const Vector2d & b, float gamma)
{
	return std::abs(std::pow(Vector2d::Distance(a, p), gamma) + std::pow(Vector2d::Distance(b, p), gamma) - std::pow(Vector2d::Distance(a, b), gamma)) < 1.f;
}

bool Map::IsInBetaSkeletonHeightmap(const Vector2d & p, const Vector2d & a, const Vector2d & b, float gamma, Heightmap &map) {
	return std::pow(map.getDistance(a, p), gamma) + std::pow(map.getDistance(b, p), gamma) < std::pow(map.getDistance(a, b), gamma);
}

void Map::CalcBetaSkeleton(float gamma)
{
	int size = towns.size();
	bool hasATownInBetaSkeleton = false;
	const float step_y = 0.1f;
	int cmp = 1;
	for (int a = 0; a < size; ++a)
	{

		for (int b = cmp; b < size; ++b)
		{
			if (a == b) continue;
			bool hasATownInBetaSkeleton = false;
			for (int p = 0; p < size; ++p)
			{
					if (towns[p] != towns[a] && towns[p] != towns[b] && IsInBetaSkeleton(towns[p], towns[a], towns[b], gamma))
					{	
						hasATownInBetaSkeleton = true;
					}

			}
			if (!hasATownInBetaSkeleton)
			{

				waysPoints.push_back(towns[a]);
				waysPoints.push_back(towns[b]);
				waysEdges.push_back(Vector2d(waysPoints.size() - 2, waysPoints.size() - 1));
			}

		}
		++cmp;
	}
}

void Map::CalcBetaSkeletonWithMoon(float gamma, const float STEP_X, const float STEP_Y, const float WIDTH, const float HEIGHT)
{
	int size = towns.size();
	std::vector<Vector2d> pointInBetaSkeleton;
	bool hasATownInBetaSkeleton = false;
	int cmp = 1;
	for (int a = 0; a < size; ++a)
	{

		for (int b = cmp; b < size; ++b)
		{
			if (a == b) continue;
			bool hasATownInBetaSkeleton = false;
			for (int p = 0; p < size; ++p)
			{
				if (towns[p] != towns[a] && towns[p] != towns[b] && IsInBetaSkeleton(towns[p], towns[a], towns[b], gamma))
				{
					hasATownInBetaSkeleton = true;
				}

			}
			if (!hasATownInBetaSkeleton)
			{

				waysPoints.push_back(towns[a]);
				waysPoints.push_back(towns[b]);
				waysEdges.push_back(Vector2d(waysPoints.size() - 2, waysPoints.size() - 1));
			}


			for (float x = 0; x < WIDTH; x += STEP_X)
			{
				for (float y = 0; y < HEIGHT; y += STEP_Y)
				{
					Vector2d p(x, y);
					if (IsInMoonBetaSkeleton(p, towns[a], towns[b], gamma))
					{
						pointInBetaSkeleton.push_back(p);
					}
				}
			}

			AddWayFromPointList(pointInBetaSkeleton);
		}
		++cmp;
	}
}

void Map::CalcBetaSkeletonHeightmap(float gamma, const float STEP_X, const float STEP_Y, Heightmap &map) {
	std::vector<Vector2d> pointInBetaSkeleton;
	int size = towns.size();
	const float step_x = 0.1f;
	bool hasATownInBetaSkeleton = false;
	const float step_y = 0.1f;
	for (int a = 0; a < size; ++a)
	{
		for (int b = 0; b < size; ++b)
		{
			bool hasATownInBetaSkeleton = false;
			for (int p = 0; p < size; ++p)
			{
				if (p != a && p != b && IsInBetaSkeletonHeightmap(towns[p], towns[a], towns[b], gamma, map))
				{
					hasATownInBetaSkeleton = true;
				}

			}
			if (!hasATownInBetaSkeleton)
			{

				waysPoints.push_back(towns[a]);
				waysPoints.push_back(towns[b]);
				waysEdges.push_back(Vector2d(waysPoints.size() - 2, waysPoints.size() - 1));
			}
		}
	}
}
