#include "bmath.h"

double BMath::GetLength(Vec2 vec)
{
	return vec.length;
}

double BMath::GetLength(Point start, Point end)
{
	double x = end.x - start.x;
	double y = end.y - start.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vec2 BMath::Derivative(Point start, Point end)
{
	Point temp1(end.x - start.x, end.y - start.y);
	Point temp2;
	temp2.x = sqrt((pow(temp1.x, 2) + pow(temp1.y, 2)) / pow(temp1.y, 2));
	temp2.y = sqrt(1.0 - pow(temp2.x, 2));
	return Vec2(temp1, temp2);
}

double BMath::CosineAngle(Vec2 first, Vec2 second)
{
	return abs(first.x*second.x+first.y*second.y) / (first.length*second.length);
}