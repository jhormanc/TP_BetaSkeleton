#include "Heightmap.h"


Heightmap::Heightmap(const char *filename, float influence)
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

		for (int x = 0; x < width * 3; x += 3) {
			map.push_back(std::vector<float>());

			for (int y = 0; y < height * 3; y += 3) {
				int idx = y + x * width;
				float gray_scale = 255.0f - ((float)m_Ptr[idx] + (float)m_Ptr[idx + 1] + (float)m_Ptr[idx + 2]) / 3.0f; // Average method [0, 255]
				//gray_scale /= maxColVal; // [0, 1]
				gray_scale = gray_scale * influence;
				map[x / 3].push_back(gray_scale);
			}
		}
		is.close();
	} else {
		std::cout << "Error: can't open file." << std::endl;
	}
}

float Heightmap::getDistance(const Vector2d &p0, const Vector2d &p1) {
	float dist = 0;
	float step = 1.0f / Vector2d::Distance(p0, p1);

	for (float t = 0; t < 1.0f; t+=step) {
		int idx_x = (1 - t) * p0.x + t * p1.x;
		int idx_y = (1 - t) * p0.y + t * p1.y;
		
		dist += map[idx_x][idx_y];
	}

	return dist;
}


Heightmap::~Heightmap()
{
}
