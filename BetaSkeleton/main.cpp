#include "Map.h"
#include "Svg.h"

int main(char argc, char ** argv)
{
	float WIDTH = 800;
	float HEIGHT = 800;
	int TOWN_COUNT = 10;
	Map map = Map::GenRandomTowns(0, WIDTH, 0, HEIGHT, TOWN_COUNT);
	// SVG Export
	// map.CalcSkeleton ? Skeleton(map) ?

	Svg svg("test.svg", 500, 500);

	svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	svg.save();
	
	return 1;
}