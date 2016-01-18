#include "Heightmap.h"


Heightmap::Heightmap(const char *filename)
{
	std::ifstream is (filename, std::ifstream::binary);

	if (is) {
		std::string magicNum;
		int maxColVal;
		char * m_Ptr;

		is >> magicNum;
		is >> width >> height >> maxColVal;
		is.get();
		
		size_t size = width * height * 3;
		
		m_Ptr = new char[size];
		is.read(m_Ptr, size);

		std::vector<std::vector<float>> map = std::vector<std::vector<float>>();

		for (int x = 0; x < width * 3; x += 3) {
			map.push_back(std::vector<float>());

			for (int y = 0; y < height * 3; y += 3) {
				int idx = y + x * width;
				float gray_scale = ((float)m_Ptr[idx] + (float)m_Ptr[idx + 1] + (float)m_Ptr[idx + 2]) / 3; // Average method
				map[x / 3].push_back(gray_scale);
			}
		}
		is.close();
	} else {
		std::cout << "Error: can't open file." << std::endl;
	}
}


Heightmap::~Heightmap()
{
}
