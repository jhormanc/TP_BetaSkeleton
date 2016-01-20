#include "Map.h"
#include "Svg.h"
#include "Heightmap.h"

int main(char argc, char ** argv)
{
	const float WIDTH = 1024;
	const float HEIGHT = 1024;

	const float STEP_X = 0.1f;
	const float STEP_Y = 0.1f;
	const int TOWN_COUNT = 10;
	const float POINT_RADIUS = 5.f;
	const float LINE_WIDTH = 1.f;
	const float GAMMA = 1.f;
	ColorRGB RED{ 255, 0, 0 };
	ColorRGB BLUE{ 0, 0, 255 };

	Heightmap heightmap = Heightmap("Heightmap.ppm");

	Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	map.CalcBetaSkeletonHeightmap(GAMMA, STEP_X, STEP_Y, heightmap);


	Svg svg("test.svg", WIDTH, HEIGHT);

	//svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	//svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });
	//svg.addPoints(map.towns, POINT_RADIUS, RED);

	//svg.addPoints(map.waysPoints, POINT_RADIUS, BLUE);
	//svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	//svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	//svg.addPoints(map.waysPoints, POINT_RADIUS, BLUE);

	svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);

	svg.addPoints(map.towns, POINT_RADIUS, RED);
	svg.save();

	//system("pause");
	return 1;
}