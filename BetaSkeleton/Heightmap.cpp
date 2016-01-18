#include "Heightmap.h"



Heightmap::Heightmap(const char *filename)
{
	//CImg<unsigned char> map_img(filename);
	//width = map_img.width();
	//height = map_img.height();

	//map = std::vector<std::vector<float>>();

	//if (!map.isNull())
	//{
	//	// On parcour chaque pixel de l'image pour récupérer le niveau de gris
	//	for (int z = 0; z < height; ++z)
	//	{
	//		QVector<double> tmp = QVector<double>();
	//		QRgb rowData = (QRgb)map.scanLine(z);

	//		for (int x = 0; x < width; ++x)
	//		{
	//			QRgb pixelData = rowData[x];
	//			double y = double(qGray(pixelData)) / 255;

	//			tmp.push_back(y);
	//		}
	//		_heightMap.push_back(tmp);
	//	}
	//}
}


Heightmap::~Heightmap()
{
}
