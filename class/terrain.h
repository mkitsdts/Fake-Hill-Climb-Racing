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
* ����һ��640*400�Ĵ��� ��ÿ8*5Ϊһ����λ������״ ��80��������
*/

class Terrain:public Physics
{
public:
	Terrain();
	~Terrain();
	//
	virtual bool Init();
	//Ϊ���ư�������������׼��
	double Perlin(double x);
	//���ֺ�����ֵ����
	double Interpolate(double X);
	
	//�����ڵ�ͼ�ϵĵ�
	std::vector <Point> usingPoint;

private:
	//������ϣ������α�����
	std::vector <int> perm;
};


#endif TERRAIN_H
