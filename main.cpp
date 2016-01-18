#include "Map.h"
int main(char argc, char ** argv)
{
	float WIDTH = 800;
	float HEIGHT = 800;
	int TOWN_COUNT = 10;
	Map map = Map::GenRandomTowns(0, WIDTH, 0, HEIGHT, TOWN_COUNT);
	// SVG Export
	// map.CalcSkeleton ? Skeleton(map) ?
	return 1;
}