#pragma once

#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <CImg.h>
#include "Vector2d.h"

using namespace cimg_library;

class Heightmap
{
private:
	int width;
	int height;
	std::vector<std::vector<float>> map;

public:
	Heightmap(const char *filename, float influence);
	~Heightmap();

	float getDistance(const Vector2d &p0, const Vector2d &p1);
};

