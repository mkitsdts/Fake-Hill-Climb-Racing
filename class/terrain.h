#ifndef TERRAIN_H
#define TERRAIN_H
#include "easyx.h"
#include "physics.h"
#include "bmath.h"
#include "main.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

/*
* 创建一个640*400的窗口 以每8*5为一个单位正方形状 共80个正方形
*/

class Terrain:public Physics
{
public:
	Terrain();
	~Terrain();
	//
	virtual bool Init();
	//为绘制柏林噪音曲线做准备
	double Perlin(double x);
	//柏林函数插值函数
	double Interpolate(double X);
	
	//出现在地图上的点
	std::vector <Point> usingPoint;

private:
	//建立哈希表生成伪随机数
	std::vector <int> perm;
};


#endif TERRAIN_H
