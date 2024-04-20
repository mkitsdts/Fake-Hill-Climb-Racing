#include "terrain.h"

Terrain::Terrain() 
{
}

Terrain::~Terrain()
{
}

bool Terrain::Init()
{
	//生成（1-128）无重复随机数
	perm =
	{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
		33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
		49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
		65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
		81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
		97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
		113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128
	};
	std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(perm.begin(), perm.end(),rng);
	double temp = 200;
	for(int i=0;i<640;++i)
	{
		if (i % 5 == 0)
		{
			groundPoint.push_back(perm[i/5]);
		}
		else
		{
			groundPoint.push_back(temp);
			temp = Perlin(temp) ;
		}
	}
    return true;
}

double Terrain::Perlin(double x)
{
	int X = (int)(x);
	x = x-X;
	// 查表实现伪随机值
	double value1 = perm[X % 128] / 128.0;
	double value2 = perm[((X + 1) % 128)] / 128.0;
	x=Interpolate(x);
	return (value1 * (1 - x) + value2 * x);
}

double Terrain::Interpolate(double X)
{
	return (3 * pow(X, 2) - 2 * pow(X, 3));
}