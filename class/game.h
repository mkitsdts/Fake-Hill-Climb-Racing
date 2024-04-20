#ifndef GAME_H
#define GAME_H
#include "easyx.h"
#include "car.h"
#include "terrain.h"
#include "physics.h"
#include "bmath.h"
#include "main.h"

//x��ÿ��4������һ��ֱ�ߣ�����ֻ��Ҫ��һ��vector����洢��Ӧy������꼴��
class Game :public Car, public Terrain
{
public:
	Game();
	~Game();
	//��ʼ������
	virtual bool Init();
	//������Ϸ
	void GameStart();
	//���Ƴ�ʼֻ����ֱ�ߵĵ�ͼ
	void DrawOrigin();
	//���µ�ͼ����
	void UpdateMap();
	//������ͼ
	void DrawNew();
	//�����ײ
	bool IsCollision();
	//���¾�ͷλ�õ�������
	void UpdatePoint(Point newPoint);
private:
	Car car;
	Terrain terrain;
	char operator_num;
	Point camera;
};


#endif GAME_H
