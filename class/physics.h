#ifndef PHYSICS_H
#define PHYSICS_H
#include "bmath.h"
#include "car.h"
#include "main.h"

class Car;
const double g = 9.80;
class Physics:public BMath
{
public:

	Physics();
	~Physics();
	
	//未脱离地面计算运动下一个点的坐标
	static Point InGroundDisplacement(Car car);
	//脱离地面计算运动下一个点的坐标
	static Point OutGroundDisplacement(Car car);

};


#endif PHYSICS_H
