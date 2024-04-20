#include "game.h"
#include <conio.h>


Game::Game()
{
	if (Init())
	{
		//��ȡ�������룬���س�����ʼ��Ϸ
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
		//������10000Ϊ��ʼ��ʧ��
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
		//��������
		initgraph(640, 400, EX_NOMINIMIZE | EX_SHOWCONSOLE);
		setorigin(0, 0);
		//���Ƴ�ʼ��ͼ
		DrawOrigin();
		return true;
	}
	return false;
}

void Game::GameStart()
{
	//��ȡ�������룬�����������ı���ٶȣ�Ȼ������ٶȣ�λ�ã�
	//�ٶȷ�����ڵ���Ͳ��ڵ���
	//�ڵ���ʱ������һ������������б��
	//���ڵ���ʱ����Vec2 x��Vec2 y�ĺ��ٶ�
	while (true)
	{
		//�����ٶȷ���
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
		//�����ٶȣ����ٶ�״̬
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