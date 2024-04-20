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
	
	//δ�����������˶���һ���������
	static Point InGroundDisplacement(Car car);
	//�����������˶���һ���������
	static Point OutGroundDisplacement(Car car);

};


#endif PHYSICS_H
