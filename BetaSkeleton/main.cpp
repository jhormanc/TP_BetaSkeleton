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
	//srand(time(NULL));


	/***********************************************************************************************************************************************/
	/*****************************************************     CONSTANTE    ************************************************************************/
	/***********************************************************************************************************************************************/

	const float WIDTH = 660;
	const float HEIGHT = 660;

	const float STEP_X = 0.1f;
	const float STEP_Y = 0.1f;
	const int TOWN_COUNT = 5;
	const int TOWN_MAX = 100;
	const float POINT_RADIUS = 1.f;
	const float LINE_WIDTH = 1.f;
	const float GAMMA = 2.f;
	const int REPEAT = 3;
	ColorRGB RED{ 255, 0, 0 };
	ColorRGB BLUE{ 0, 0, 255 };

	ColorRGB PURPLE{ 255, 0, 255 };


	/***********************************************************************************************************************************************/
	/************************************************************************* MAP     ******************** /
		/***********************************************************************************************************************************************/

		auto start = std::chrono::high_resolution_clock::now();
	//Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));

	//auto start = std::chrono::high_resolution_clock::now();
	//Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	////map.CalcBetaSkeleton(GAMMA);
	//map.CalcBetaSkeletonWithMoon(GAMMA, STEP_X, STEP_Y, WIDTH, HEIGHT);
	//Svg svg("test.svg", WIDTH, HEIGHT);

	//map.CalcBetaSkeleton(GAMMA);
	//map.CalcBetaSkeletonWithMoon(GAMMA, STEP_X, STEP_Y, WIDTH, HEIGHT);
	/*Map map(Map::GenTowns1(0, 0, WIDTH, HEIGHT));
	Heightmap heightmap("Heightmap.ppm", 1.f);
	map.CalcBetaSkeletonWithMoonHeightmap(GAMMA, STEP_X, STEP_Y, WIDTH, HEIGHT, heightmap);
	Svg svg("test.svg", WIDTH, HEIGHT);*/

	//svg.addPoints(map.betaSkeletonLunePoints, POINT_RADIUS, PURPLE);
	//svg.addPoints(map.towns, POINT_RADIUS, RED);
	//svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);
	//svg.save();

	//auto end = std::chrono::high_resolution_clock::now();
	//float timeRes = std::chrono::duration<float, std::milli>(end - start).count();
	//std::cout << timeRes / (float)REPEAT << "ms" << std::endl;

	/***********************************************************************************************************************************************/
	/*******************************************************    MOON     ***************************************************************************/
	/***********************************************************************************************************************************************/

	/*Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	map.CalcBetaSkeletonWithMoon(GAMMA, STEP_X, STEP_Y, WIDTH, HEIGHT);
	Svg svg("test.svg", WIDTH, HEIGHT);

	svg.addPoints(map.towns, POINT_RADIUS, RED);
	svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);
	svg.addPoints(map.betaSkeletonLunePoints, POINT_RADIUS, PURPLE);
	svg.save();*/


	/***********************************************************************************************************************************************/
	/*******************************************************  TEST SVG  ****************************************************************************/
	/***********************************************************************************************************************************************/
	/*Svg svg("test.svg", WIDTH, HEIGHT);
	Map map(Map::GenRandomTowns(0, 0, WIDTH, HEIGHT, TOWN_COUNT));
	
	svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	svg.addPoint(Vector2d(50, 50), 5, ColorRGB { 255, 0, 0 });
	svg.addLine(Vector2d(0, 0), Vector2d(30, 100), 2, ColorRGB{ 0, 255, 0 });

	svg.addPoints(map.waysPoints, POINT_RADIUS, BLUE);

	
	svg.addPoints(map.towns, POINT_RADIUS, RED);
	
	svg.save();*/

	//Heightmap heightmap = Heightmap("Heightmap.ppm");


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


	/*/***********************************************************************************************************************************************/
	/*******************************************************   HEIGHTMAP   *************************************************************************/
	/***********************************************************************************************************************************************/
	Heightmap heightmap = Heightmap("france.ppm", 1.0f);
	//Heightmap heightmap = Heightmap("Heightmap.ppm", 1.0f);

	/*Map map1(Map::GenTowns1(0, 0, WIDTH, HEIGHT));
	Map map2(Map::GenTowns1(0, 0, WIDTH, HEIGHT));*/
	//Map map1(Map::GenTowns2(0, 0, WIDTH, HEIGHT));
	Map map(Map::GenTowns2(0, 0, WIDTH, HEIGHT));

	map.CalcBetaSkeletonHeightmap(GAMMA, heightmap);
	//map.CalcBetaSkeletonWithMoonHeightmap(GAMMA, STEP_X, STEP_Y, WIDTH, HEIGHT, heightmap);

	Svg svg("test1.svg", WIDTH, HEIGHT);
	svg.addImg("france.jpg", WIDTH, HEIGHT);
	//svg.addImg("heightmap.jpg", WIDTH, HEIGHT);
	svg.addLines(map.waysPoints, map.waysEdges, LINE_WIDTH, BLUE);

	svg.addPoints(map.towns, POINT_RADIUS, RED);
	//svg.addPoints(map.betaSkeletonLunePoints, POINT_RADIUS, PURPLE);
	svg.save();

	system("pause");
	return 0;
}