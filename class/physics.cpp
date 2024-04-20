#include "physics.h"
#include "terrain.h"

Physics::Physics()
{
};

Physics::~Physics() 
{
};

Point Physics::InGroundDisplacement(Car car)
{
	double tempx = car.carPosition.x + car.velocity.length * dt;
	double tempy = groundPoint[tempx];
	return Point(tempx, tempy);
}

Point Physics::OutGroundDisplacement(Car car)
{
	double tempx = car.carPosition.x + car.velocity.length * CosineAngle(car.velocity, Vec2(1, 0)) * dt;
	double tempy = car.carPosition.y + car.velocity.length * CosineAngle(car.velocity, Vec2(0, 1)) * dt +
		(1.0 / 2.0) * g * dt * dt;
	return Point(tempx, tempy);
}