#ifndef GAME_H
#define GAME_H
#include "easyx.h"
#include "car.h"
#include "terrain.h"
#include "physics.h"
#include "bmath.h"
#include "main.h"

//x轴每隔4个点做一个直线，纹理只需要用一个vector数组存储对应y轴的坐标即可
class Game :public Car, public Terrain
{
public:
	Game();
	~Game();
	//初始化窗口
	virtual bool Init();
	//启动游戏
	void GameStart();
	//绘制初始只含有直线的地图
	void DrawOrigin();
	//更新地图数据
	void UpdateMap();
	//绘制新图
	void DrawNew();
	//检测碰撞
	bool IsCollision();
	//更新镜头位置到车中心
	void UpdatePoint(Point newPoint);
private:
	Car car;
	Terrain terrain;
	char operator_num;
	Point camera;
};


#endif GAME_H
