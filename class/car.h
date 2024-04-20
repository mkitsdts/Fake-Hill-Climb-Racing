#ifndef CAR_H
#define CAR_H
#include "physics.h"

const double dt = 0.2;
class Physics;
class Vec2;

//��������ֻ�ܰѳ������һ������״̬�µ�һ���ʵ�
class Car
{
public:
	//�����ٶ�
	Vec2 velocity;
	//��������
	Point carPosition;

public:
	Car();
	~Car();

	//���������ٶȺͼ��ٶ�״̬
	void UpdateState(Car car, Vec2 newVelocity) const;
	void UpdateState(bool condition, Car car, Vec2 newVelocity) const;

	//��ȡ������������
	int GetCarSerialNumber() const;
	int GetCarNextSerialNumber() const;

	//��ȡ��������
	double GetCarXPositon() const;
	double GetCarYPositon() const;
	Point GetCarPosition() const;


protected:
	//�������ٶ�
	double acceleration;
	//��������
	double speed;
};


#endif CAR_H

