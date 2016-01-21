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

		std::cout << magicNum << std::endl;
		std::cout << width << height << maxColVal << std::endl;
		std::cout << m_Ptr << std::endl;

		for (int y = 0; y < height * 3; y += 3) {
		
			map.push_back(std::vector<float>());

			for (int x = 0; x < width * 3; x += 3) {
				int idx = x + y * width;
				
				int r = m_Ptr[idx] & 0xff;
				int g = m_Ptr[idx + 1] & 0xff;
				int b = m_Ptr[idx + 2] & 0xff;
				
				float gray_scale = 255.f - ((float)r + (float)g + (float)b) / 3.0f; // Average method [0, 255]
				
				map[y / 3].push_back(gray_scale);
			}
		}
		is.close();
	} else {
		std::cout << "Error: can't open file." << std::endl;
	}
}

float Heightmap::getDistance(const Vector2d &p0, const Vector2d &p1) {
	float dist = 0;

	int n = 200;
	float distance = Vector2d::Distance(p0, p1);
	float dn = distance / n;

	for (int i = 0; i < n; ++i)
	{
		Vector2d pi = p0 + (p1 - p0) * (float(i) / n);

		float z = map[pi.y][pi.x];
		Vector2d next = p0 + (p1 - p0) * ((float(i + 1.f)) / n);
		float dz = std::abs(map[next.y][next.x] - z) / dn;
		
		dist += dn * (1.f + (255.f - z) / 127.f 
			+ (dz < 0.15f ? dz / 0.15f : 40.f) 
			+ (z > 250.f ? 400.f : 0.f));
	}
	return dist;
}


Heightmap::~Heightmap()
{
}
