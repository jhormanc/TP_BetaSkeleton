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

				//std::cout << r << " " << g << " " << b  << std::endl;
				
				float gray_scale = 255.f - ((float)r + (float)g + (float)b) / 3.0f; // Average method [0, 255]
				//gray_scale /= maxColVal; // [0, 1]
				
			//	gray_scale = gray_scale * influence;
				
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
	float step = 0.1f;
	Vector2d dir = Vector2d::Normalize(p1 - p0);
	Vector2d current(p0);
	int n = 10;
	float distance = Vector2d::Distance(p0, p1);
	for (int i = 0; i < n; ++i)
	{
		/*while (distance > Vector2d::Distance(p0, current))
		{*/
		Vector2d pi = p0 + (p1 - p0) * (i / n);
		//    current = current + dir * step;
		float z = map[pi.y][pi.x];
		Vector2d next = p0 + (p1 - p0) * ((i + 1) / n);
		float dz = std::abs(map[next.y][next.x] - z);
		dist += (distance / n) * (1.f + (z / 127.f) + (dz * 4));
	}
	return dist;
}

bool Heightmap::isABCanPass(const Vector2d &A, const Vector2d &B)
{	
	float dist = 0;
	float step = .1f;
	float minH = 2.f;
	float maxH = 210.f;
	Vector2d dir = Vector2d::Normalize(B - A);
	Vector2d current(A);
	while (Vector2d::Distance(A, B) > Vector2d::Distance(A, current) )
	{
		current = current +  dir * step;
	
		if (map[current.y][current.x] > maxH)
			return false;
	}
	return true;
}


Heightmap::~Heightmap()
{
}
