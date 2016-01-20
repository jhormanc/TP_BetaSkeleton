#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <fstream>

#include "Map.h"
#include "Svg.h"
#include "Heightmap.h"

int main(char argc, char ** argv)
{
	srand(time(NULL));


	/***********************************************************************************************************************************************/
	/*****************************************************     CONSTANTE    ************************************************************************/
	/***********************************************************************************************************************************************/
	const float WIDTH = 1000;
	const float HEIGHT = 1000;

	const float STEP_X = 0.1f;
	const float STEP_Y = 0.1f;
	const int TOWN_COUNT = 10;
	const int TOWN_MAX = 100;
	const float POINT_RADIUS = 5.f;
	const float LINE_WIDTH = 1.f;
	const float GAMMA = 1.f;
	const int REPEAT = 3;
	ColorRGB RED{ 255, 0, 0 };
	ColorRGB BLUE{ 0, 0, 255 };


	/***********************************************************************************************************************************************/
	/*******************************************************     MAP     ***************************************************************************/
	/***********************************************************************************************************************************************/

	//Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	//map.CalcBetaSkeleton(GAMMA, STEP_X, STEP_Y);


	/***********************************************************************************************************************************************/
	/*******************************************************  TEST SVG  ****************************************************************************/
	/***********************************************************************************************************************************************/
	/*Svg svg("test.svg", WIDTH, HEIGHT);
*/
	//svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	//svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });
	//svg.addPoints(map.towns, POINT_RADIUS, RED);

	//svg.addPoints(map.waysPoints, POINT_RADIUS, BLUE);
	//svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	//svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	//	svg.addPoints(map.waysPoints, POINT_RADIUS, BLUE);

	//svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);

	//svg.addPoints(map.towns, POINT_RADIUS, RED);
	//svg.save();

	//Heightmap heightmap = Heightmap("Heightmap.ppm");
	//



	/***********************************************************************************************************************************************/
	/*******************************************************   MEASURE   ***************************************************************************/
	/***********************************************************************************************************************************************/
	//std::ofstream mesureFile("mesureConvex.txt", std::ios::out | std::ios::trunc);

	//for (int i = 3; i < TOWN_MAX; ++i)
	//{
	//	float timeRes = 0.f;
	//	//Convex2d measureConvex;
	//	for (int repeat = 0; repeat < REPEAT; ++repeat)
	//	{

	//		Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, i));
	//		auto start = std::chrono::high_resolution_clock::now();
	//		map.CalcBetaSkeleton(GAMMA, STEP_X, STEP_Y);
	//		auto end = std::chrono::high_resolution_clock::now();
	//		timeRes += std::chrono::duration<float, std::milli>(end - start).count();

	//		//// MEASURE TEST
	//		//std::string s = "measure";
	//		//s.append(std::to_string(i));
	//		//s.append("_");
	//		//s.append(std::to_string(repeat));
	//		//s.append(".svg");
	//		//Svg doc(s, (float)WIDTH, (float)HEIGHT);
	//		//doc.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);
	//		//doc.addPoints(map.towns, POINT_RADIUS, RED);
	//		//doc.save();
	//	}
	//	mesureFile << i << " " << timeRes / (float)REPEAT << std::endl;

	//}


	/***********************************************************************************************************************************************/
	/*******************************************************   HEIGHTMAP   *************************************************************************/
	/***********************************************************************************************************************************************/

	Heightmap heightmap = Heightmap("Heightmap.ppm");
	Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	map.CalcBetaSkeletonHeightmap(GAMMA, STEP_X, STEP_Y, heightmap);


	Svg svg("test.svg", WIDTH, HEIGHT);

	svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);

	svg.addPoints(map.towns, POINT_RADIUS, RED);
	svg.save();

	system("pause");
	return 0;
}