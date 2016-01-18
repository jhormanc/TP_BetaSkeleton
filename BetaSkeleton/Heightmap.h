#pragma once

#include <vector>
#include <iostream>
#include <fstream> 
#include <string>


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

