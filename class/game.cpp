#include "game.h"
#include <conio.h>


Game::Game()
{
	if (Init())
	{
		//获取键盘输入，按回车键开始游戏
		while (true)
		{
			if (_kbhit())
			{
				operator_num = _getch();
				if (operator_num == 13)
				{
					GameStart();
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		//错误码10000为初始化失败
		exit(-10000);
	}
}

Game::~Game()
{
}

bool Game::Init()
{
	if (Terrain::Init())
	{
		//创建窗口
		initgraph(640, 400, EX_NOMINIMIZE | EX_SHOWCONSOLE);
		setorigin(0, 0);
		//绘制初始地图
		DrawOrigin();
		return true;
	}
	return false;
}

void Game::GameStart()
{
	//获取键盘输入，如果有输入则改变加速度，然后更新速度，位置，
	//速度方向分在地面和不在地面
	//在地面时等于下一个坐标点的连线斜率
	//不在地面时等于Vec2 x和Vec2 y的合速度
	while (true)
	{
		//汽车速度方向
		Vec2 temp(terrain.usingPoint[GetCarSerialNumber()], terrain.usingPoint[GetCarNextSerialNumber()]);
		if (_kbhit())
		{
			operator_num = _getch();
			if (operator_num == 'A'|| operator_num == 'a')
			{
				UpdateState(false,car,temp);
				if (IsCollision())
				{
					Physics::InGroundDisplacement(car);
				}
				else
				{
					Physics::OutGroundDisplacement(car);
				}
			}
			else if(operator_num == 'D' || operator_num == 'd')
			{
				
				UpdateState(true, car,temp);
				if (IsCollision())
				{
					car.carPosition=Physics::InGroundDisplacement(car);
				}
				else
				{
					car.carPosition=Physics::OutGroundDisplacement(car);
				}
			}
			continue;
		}
		//更新速度，加速度状态
		else
		{
			Car::UpdateState(car, temp);
			Physics::InGroundDisplacement(car);
		}
		DrawNew();
	}
}

void Game::DrawNew()
{
	UpdateMap();
	BeginBatchDraw();
	setlinecolor(BLUE);
	for (int i = 0,n=0; i <= 640; i+=4,++n)
	{
		line(i,groundPoint[n],i+4,groundPoint[n+1]);
		FlushBatchDraw();
	}
	EndBatchDraw();
}

bool Game::IsCollision()
{
	if (GetCarYPositon() >= usingPoint[((int)GetCarXPositon() + 2) / 4].y)
	{
		return true;
	}
	return false;
}

void Game::UpdatePoint(Point newPoint)
{
	camera = newPoint;
	return;
}

void Game::DrawOrigin()
{

	return;

}

void Game::UpdateMap()
{

	return;

}