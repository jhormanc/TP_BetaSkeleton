#include "Map.h"
#include "Svg.h"

int main(char argc, char ** argv)
{
	float WIDTH = 800;
	float HEIGHT = 800;
	int TOWN_COUNT = 10;
	int POINT_RADIUS = 100;
	ColorRGB RED{ 255, 0, 0 };
	Map map(Map::GenRandomTowns(0, WIDTH, 0, HEIGHT, TOWN_COUNT));
	map.CalcBetaSkeleton(2.f);

	Svg svg("test.svg", WIDTH, HEIGHT);

	svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	svg.addPoints(map.towns, POINT_RADIUS, RED);

	svg.save();
	
	return 1;
}