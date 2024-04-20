#include "car.h"

Car::Car()
{
	velocity = Vec2(Point(0, 0), Point(0, 0));
	speed = 0;
	acceleration = 0;
	carPosition = Point(0, 200);
}

Car::~Car()
{
}

void Car::UpdateState(bool condition, Car car, Vec2 newVelocity) const
{
	//º”ÀŸ
	if (condition)
	{
		car.acceleration += 0.7;
		car.speed += dt * acceleration;
		car.velocity = newVelocity;
		car.velocity.length = speed;
	}
	//ºıÀŸ
	else
	{
		car.acceleration -= 0.7;
		car.speed -= dt * acceleration;
		car.velocity = newVelocity;
		car.velocity.length = speed;
	}
}

void Car::UpdateState(Car car, Vec2 newVelocity) const
{
	car.acceleration -= 0.5;
	car.speed -= dt * acceleration;
	car.velocity = newVelocity;
}

int Car::GetCarSerialNumber() const
{
	return (int)(carPosition.x + 2) / 4;
}

int Car::GetCarNextSerialNumber() const
{
	return (int)(carPosition.x + 2) / 4 + 1;
}

double Car::GetCarXPositon() const
{
	return carPosition.x;
}

double Car::GetCarYPositon() const
{
	return carPosition.y;
}

Point Car::GetCarPosition() const
{
	return carPosition;
}