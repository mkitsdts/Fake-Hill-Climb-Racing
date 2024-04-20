#ifndef CAR_H
#define CAR_H
#include "physics.h"

const double dt = 0.2;
class Physics;
class Vec2;

//技术不行只能把车抽象成一个理想状态下的一个质点
class Car
{
public:
	//汽车速度
	Vec2 velocity;
	//汽车坐标
	Point carPosition;

public:
	Car();
	~Car();

	//更新汽车速度和加速度状态
	void UpdateState(Car car, Vec2 newVelocity) const;
	void UpdateState(bool condition, Car car, Vec2 newVelocity) const;

	//获取汽车坐标的序号
	int GetCarSerialNumber() const;
	int GetCarNextSerialNumber() const;

	//获取汽车坐标
	double GetCarXPositon() const;
	double GetCarYPositon() const;
	Point GetCarPosition() const;


protected:
	//汽车加速度
	double acceleration;
	//汽车速率
	double speed;
};


#endif CAR_H

