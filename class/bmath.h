#ifndef BMATH_H
#define BMATH_H
#include <cmath>

struct Point
{
public:
	Point() :x(0), y(0) {};
	Point(double Px, double Py)
	{
		x = Px;
		y = Py;
	}
	double x;
	double y;
};

//以左下角为原点建立坐标系以描绘物理世界
class Vec2
{
public:
	double length; 
	Vec2() :x(0),y(0),start(),end(),length(0) {};
	Vec2(Point Pstart, Point Pend)
	{
		start = Pstart;
		end = Pend;
		x = start.x - end.x, 2;
		y = start.y - end.y, 2;
		length = sqrt(pow(x,2) + pow(y,2));
	}
	Vec2(double Px, double Py)
	{
		x = Px;
		y = Py;
		start.x = 0;
		start.y = 0;
		end.x = 0;
		end.y = 0;
		length = sqrt(pow(x, 2)+pow(y, 2));
	}
	Vec2(double Px, double Py, Point Pstart, Point Pend)
	{
		x = Px;
		y = Py;
		start = Pstart;
		end = Pend;
		length = sqrt(pow(x, 2) + pow(y, 2));
	}
	~Vec2()
	{
	}
private:
	//向量起点和终点
	Point start;
	Point end;
public:
	double x;
	double y;
};

class BMath:public Vec2
{
public:

	//返回垂直于两点向量的单位向量指针
	Vec2 Derivative(Point start, Point end);
	//求向量长度
	static double GetLength(Vec2 vec);
	static double GetLength(Point start, Point end);
	//求向量夹角
	static double CosineAngle(Vec2 first, Vec2 second);
	//分解速度
	static Vec2 VelocityDivision(bool condition,Vec2 velocity);
};
#endif BMATH_H
