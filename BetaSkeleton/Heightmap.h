#pragma once

#include <vector>

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

