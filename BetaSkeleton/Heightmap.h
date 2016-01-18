#pragma once

#include <vector>
#include <CImg.h>

class Heightmap
{
private:
	int width;
	int height;
	std::vector<std::vector<float>> map;
public:
	Heightmap(const char *filename);
	~Heightmap();
};

