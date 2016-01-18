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
	return std::abs(std::pow(Vector2d::Distance(a, p), gamma) + std::pow(Vector2d::Distance(b, p), gamma) - std::pow(Vector2d::Distance(a, b), gamma)) < 1.f;
}

void Map::CalcBetaSkeleton(float gamma, const float STEP_X, const float STEP_Y)
{
	std::vector<Vector2d> pointInBetaSkeleton;
	int size = towns.size();
	const float step_x = 0.1f;

	const float step_y = 0.1f;
	for (int a = 0; a < size; ++a)
	{
		for (int b = 0; b < size; ++b)
		{
			for (float x = xMin; x < xMax; x += step_x)
			{
				for (float y = yMin; y < yMax; y += step_y)
				{
					Vector2d p = Vector2d(x, y);
					if (p != towns[a] && p != towns[b] && IsInBetaSkeleton(p, towns[a], towns[b], gamma))
					{
						pointInBetaSkeleton.push_back(p);
					}
				}
			}
		}
	}
	AddWayFromPointList(pointInBetaSkeleton);
}
