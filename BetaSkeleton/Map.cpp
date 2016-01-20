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


void Map::AddWayFromPointList(const std::vector<Vector2d> & pointList)
{
	for (int i = 0; i < pointList.size(); ++i)
	{
		waysPoints.push_back(pointList[i]);
	}
	//if (pointList.size() > 0) // Arrivera jamais quandIsInBetaSkeleton sera code
	//{
	//	Vector2d min = pointList[0];
	//	Vector2d max = pointList[0];
	//	for (int i = 1; i < pointList.size(); ++i)
	//	{
	//		min.Min(pointList[i]);
	//		max.Max(pointList[i]);
	//	}
	//	waysPoints.push_back(min);
	//	waysPoints.push_back(max);
	//	waysEdges.push_back(Vector2d(waysPoints.size() - 2, waysPoints.size() - 1));
	//}
}

bool Map::IsInBetaSkeleton(const Vector2d & p, const Vector2d & a, const Vector2d & b, float gamma)
{
	return std::pow(Vector2d::Distance(a, p), gamma) + std::pow(Vector2d::Distance(b, p), gamma) < std::pow(Vector2d::Distance(a, b), gamma);
}

bool Map::IsInBetaSkeletonHeightmap(const Vector2d & p, const Vector2d & a, const Vector2d & b, float gamma, Heightmap &map) {
	return std::pow(map.getDistance(a, p), gamma) + std::pow(map.getDistance(b, p), gamma) < std::pow(map.getDistance(a, b), gamma);
}

void Map::CalcBetaSkeleton(float gamma, const float STEP_X, const float STEP_Y)
{
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
	}
	//AddWayFromPointList(pointInBetaSkeleton);
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
				if (towns[p] != towns[a] && towns[p] != towns[b] && IsInBetaSkeletonHeightmap(towns[p], towns[a], towns[b], gamma, map))
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
